# Plant-Link

Ce projet est réalisé dans le cadre du module Communication Sans Fil en Licence 1 à l’Université Nice Côte D'Azur
![ChatGPT Image 22 mai 2025, 16_19_22](https://github.com/user-attachments/assets/4abf768d-c1f6-4122-a66b-7bd9a429cee8)

# Description 
Plant link aura pour but de rendre votre pot de plante connécté comme son nom l'indique.

le système est tres simple le pot de plante est fournis d'un boitié exterieur directement fixé qui a pour but de 
contenir la carte UCA fournis par l'université, laissant notament de la place pour un écran oled et un capteur d'humidité.

Et donc son objectif principale sera de vous envoyer un mail quand le taux d'humidié de votre plante est inferieur a 40%.

# L'envoye du mail

l'envoye du mail se fait par une communication LoRa ou comme vous pouvait le voir juste ici 
![image](https://github.com/user-attachments/assets/0e3d62cb-ebc1-4456-a3c2-2370ffaa7d1e)

Si la valeur dépasse en dessous des 40% il va envoyer un message a un application crée sur ThethingNetwork.

lien du site utilisé : https://www.thethingsnetwork.org/

Et puis ensuite grace a un webook crée nous un pouvont crée lien que quand le message et reçu nous envoyont un mail 
directment saisi sur le webook avec comme mon message "attention ta plante a soif, va l'arroser vite" 
