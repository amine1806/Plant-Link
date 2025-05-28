# Plant-Link

Ce projet est réalisé dans le cadre du module Communication Sans Fil en Licence 1 à l’Université Nice Côte D'Azur
![ChatGPT Image 22 mai 2025, 16_19_22](https://github.com/user-attachments/assets/4abf768d-c1f6-4122-a66b-7bd9a429cee8)

# Description 
Plant link aura pour but de rendre votre pot de plante connecté comme son nom l'indique.

Le système est très simple : le pot de plante est fournis avec boitié exterieur directement fixé qui a pour but de 
contenir la carte UCA21 fournie par l'université, laissant notament de la place pour un écran oled et un capteur d'humidité.

Et donc son objectif principal sera de vous envoyer un mail quand le taux d'humidié de votre plante est inferieur a 40%.

# présentation power point

[projet.pptx](https://github.com/user-attachments/files/20479971/projet.pptx)

# L'envoi du mail

l'envoi du mail se fait par une communication LoRa dans cette partie du code : 
![image](https://github.com/user-attachments/assets/0e3d62cb-ebc1-4456-a3c2-2370ffaa7d1e)

Si le taux d'humidité passe en dessous des 40% il va envoyer un message LoRa à une application sur ThethingsNetwork.

lien du site utilisé : https://www.thethingsnetwork.org/

Ensuite, TTN, grâce à un webhook, enverra des donées à un service nommé "IFTTT" qui se chargera de l'envoi du mail.

# Option suplémentaires 

En plus de cette communication incroyable nous avons rajouté quelques options a notre projet:

* Un écran oled nous affichant en temps réel le taux d'humidité
* l'utilisation de leds de differentes couleurs selon le taux d'humidité, inferieur a 40%: rouge, entre 40% et 60%: verte, et superieur à 60%: bleu (on n'as malheuresement pas pu le faire dans notre programme car la carte UCA21 ne possède pas assez de stockage pour le code et la librairie des led)

# Materielles et repartition des tâches 

* Une carte arduino (ici une cartes UCA21)
* Un capteur d'humidité "Maker soil moisture sensor"
* Un écran Oled
* 7 fils

Ce projet qui a été réalisé par Amine Boufenchouche et Nicolas podda, sur 6 semaine de travaille nous somme repartie la maniere suivant : 
![image](https://github.com/user-attachments/assets/b0082b1c-02e3-4dbe-9ec5-07ce25f27fb7)

* 1ere tâche: Amine
* 2eme tâche: Amine et Nicolas
* 3eme tâche: Amine
* 4eme tâche: (manque d'espace dans la carte)
* Montage du pôt: Nicolas
