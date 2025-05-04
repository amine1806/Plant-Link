

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(A0);
  float voltageR = sensorValue/1023.0;
  float voltageI = voltageR * 100;
  float valeur = 4*(100-voltageI);
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

  delay(1000);
}
