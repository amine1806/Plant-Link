#define CFG_EU 1  // Choisis la bonne région (ici Europe)

#include <lmic.h>
#include <hal/hal.h>
#include <SPI.h>
#include "lcdgfx.h"

DisplaySSD1306_128x64_I2C display(-1);
float valeur = 0.0;

// Adresse DevAddr de ton appareil (ABP)
static const u4_t DEVADDR = 0x260BFC9A;

// Clé de session réseau (NwkSKey)
static const PROGMEM u1_t NWKSKEY[16] = {
  0x47, 0x79, 0x12, 0x7C, 0xC1, 0x28, 0x3B, 0xDF,
  0x0E, 0x23, 0x1B, 0xF3, 0x02, 0x8D, 0xDC, 0x95
};

// Clé de session application (AppSKey)
static const PROGMEM u1_t APPSKEY[16] = {
  0x43, 0x40, 0xBD, 0x50, 0x7F, 0x38, 0x17, 0x77,
  0x86, 0xA2, 0x66, 0xFE, 0xB2, 0xA4, 0x75, 0xD6
};

// Données à transmettre
static uint8_t mydata[] = "BABA";
static osjob_t sendjob;

const unsigned TX_INTERVAL = 30; // secondes entre tentatives d'envoi
int taux = 0; // Variable simulée, à ajuster avec un capteur réel

// Brochage de la carte
const lmic_pinmap lmic_pins = {
    .nss = 10,
    .rxtx = LMIC_UNUSED_PIN,
    .rst = 8,
    .dio = {6, 6, 6}
};

void os_getArtEui(u1_t* buf) { }
void os_getDevEui(u1_t* buf) { }
void os_getDevKey(u1_t* buf) { }

void onEvent(ev_t ev) {
    switch(ev) {
        case EV_TXCOMPLETE:
            Serial.println(F("EV_TXCOMPLETE (includes RX waiting)"));
            if (LMIC.txrxFlags & TXRX_ACK) {
                Serial.println(F("Received ack"));
            }
            if (LMIC.dataLen) {
                Serial.print(F("Received "));
                Serial.print(LMIC.dataLen);
                Serial.println(F(" bytes of payload"));
            }
            // Replanifier le prochain envoi
            os_setTimedCallback(&sendjob, os_getTime() + sec2osticks(TX_INTERVAL), do_send);
            break;
        default:
            Serial.print(F("Event: "));
            Serial.println((unsigned) ev);
            break;
    }
}

void do_send(osjob_t* j) {


    Serial.print(F("Mesure taux = "));
    Serial.println(valeur);

    if (valeur < 40) {
        if (LMIC.opmode & OP_TXRXPEND) {
            Serial.println(F("OP_TXRXPEND, not sending"));
        } else {
            LMIC_setTxData2(1, mydata, sizeof(mydata) - 1, 0);
            Serial.println(F("Packet queued: BABA"));
        }
    } else {
        Serial.println(F("Taux >= 40, pas d'envoi"));
    }

    // Programmer la prochaine tentative, même si rien n’est envoyé
    os_setTimedCallback(&sendjob, os_getTime() + sec2osticks(TX_INTERVAL), do_send);
}

void setup() {
    Serial.begin(115200);
    Serial.println(F("Lora ABP + condition taux"));

    os_init();
    LMIC_reset();

    LMIC_setClockError(MAX_CLOCK_ERROR * 2 / 100);

    // Configuration ABP
    #ifdef PROGMEM
      uint8_t appskey[sizeof(APPSKEY)];
      uint8_t nwkskey[sizeof(NWKSKEY)];
      memcpy_P(appskey, APPSKEY, sizeof(APPSKEY));
      memcpy_P(nwkskey, NWKSKEY, sizeof(NWKSKEY));
      LMIC_setSession(0x1, DEVADDR, nwkskey, appskey);
    #else
      LMIC_setSession(0x1, DEVADDR, NWKSKEY, APPSKEY);
    #endif

    // Configuration région (Europe - 3 canaux de base)
    LMIC_setupChannel(0, 868100000, DR_RANGE_MAP(DR_SF12, DR_SF7), BAND_CENTI);
    LMIC_setupChannel(1, 868300000, DR_RANGE_MAP(DR_SF12, DR_SF7B), BAND_CENTI);
    LMIC_setupChannel(2, 868500000, DR_RANGE_MAP(DR_SF12, DR_SF7), BAND_CENTI);

    LMIC_setLinkCheckMode(0);
    LMIC.dn2Dr = DR_SF9; // RX2
    LMIC_setDrTxpow(DR_SF7, 20);

    // Démarrage initial
    do_send(&sendjob);
    display.begin();
    display.fill(0x00);
    display.setFixedFont(ssd1306xled_font6x8);
    display.printFixed (0,  8, "Humidité", STYLE_NORMAL);


}

void loop() {
    os_runloop_once();
    int sensorValue = analogRead(A0);
  float voltageR = sensorValue/1023.0;
  float voltageI = voltageR * 100;
  valeur = 4*(100-voltageI);
  Serial.println(valeur);

  if (valeur <= 60 && valeur >= 40) {
    //led vert
  }
  
  if (valeur <= 40) {
    //envoyer mail
    //led rouge
  }

  if (valeur >= 60) {
    //led bleu
  }
    display.fill(0x00);
    display.setFixedFont(ssd1306xled_font6x8);
    display.printFixed (0,  8, "Humidité", STYLE_NORMAL);
    char buffer[20];
char valeurStr[10];
dtostrf(valeur, 4, 2, valeurStr);  // (float, min width, precision, output buffer)
snprintf(buffer, sizeof(buffer), "Valeur: %s", valeurStr);
display.printFixed(0, 8, buffer, STYLE_BOLD);


  delay(10000);
}
