# Plant-Link

Ce projet est réalisé dans le cadre du module Communication Sans Fil en Licence 1 à l’Université Nice Côte D'Azur
![ChatGPT Image 22 mai 2025, 16_19_22](https://github.com/user-attachments/assets/4abf768d-c1f6-4122-a66b-7bd9a429cee8)

# Description 
Plant link aura pour but de rendre votre pot de plante connécté comme son nom l'indique.

le système est très simple le pot de plante est fournis d'un boitié exterieur directement fixé qui a pour but de 
contenir la carte UCA fournis par l'université, laissant notament de la place pour un écran oled et un capteur d'humidité.

Et donc son objectif principale sera de vous envoyer un mail quand le taux d'humidié de votre plante est inferieur a 40%.

# présentation power point

[projet.pptx](https://github.com/user-attachments/files/20479971/projet.pptx)

# L'envoye du mail

l'envoye du mail se fait par une communication LoRa ou comme vous pouvait le voir juste ici 
![image](https://github.com/user-attachments/assets/0e3d62cb-ebc1-4456-a3c2-2370ffaa7d1e)

Si la valeur dépasse en dessous des 40% il va envoyer un message a un application crée sur ThethingNetwork.

lien du site utilisé : https://www.thethingsnetwork.org/

Et puis ensuite grace à un wehbook crée nous un pouvont crée lien que quand le message est reçu nous envoyont un mail 
directment saisi sur le wehbook avec comme pour exemple le message "attention ta plante a soif, va l'arroser vite" 

(le wehbook que nous utilisont pour envoyer est payant mais vous pouvait trouver une alternative avec la création d'un serveur privé en python mais a cause du manque de temps nous avons pas put le faire)

# Option suplémentaires 

en plus de cette communication incroyable nous avons en plus rajouté quelque option a notre projet:

* Un écran oled nous affichant en temp réel le taux d'humidité
* l'utilisation de led de differente selon le taux d'humidité, inferieur a 40%: rouge, entre 40 et 60: verte et superieur à 60: bleu (malheuresement de le faire dans notre programme car la cartes ne posséde pas assez de stockage pour les led)

# Materielles et repartition des tâches 

* Une carte arduino (ici une cartes UCA21)
* Un capteur d'humidité
* Un écran Oled
* 10 fils

Ce projet qui a été réaliser par Amine Boufenchouche et Nicolas podda, ou sur 6 semaine de travaille nous somme repartie la maniere suivant : 
![image](https://github.com/user-attachments/assets/b0082b1c-02e3-4dbe-9ec5-07ce25f27fb7)

* 1er tâche: Amine
* 2eme tâche: Amine et Nicolas
* 3eme tâche: Amine
* 4eme tâche: (manque d'espace dans la carte)
* Montage du pôt: Nicolas
