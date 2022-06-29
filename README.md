# My_RPG

[![forthebadge](http://forthebadge.com/images/badges/built-with-love.svg)](https://github.com/Gaetandrt)  [![forthebadge](https://forthebadge.com/images/badges/made-with-c.svg)](https://fr.wikipedia.org/wiki/C_(langage))  [![linkedin-](https://user-images.githubusercontent.com/91087072/175767199-5ecadc72-20a2-42dc-a24f-3a601bba5ddb.svg)](https://www.linkedin.com/in/gaetan-darrort/)

My_RPG alias 

## Qu'est qu'un RPG ?

Sokoban est un jeu vidéo de réflexion inventé au Japon en 1982 par [Hiroyuki Imabayashi](https://www.mobygames.com/developer/sheet/view/developerId,257256/).

Le joueur doit ranger des caisses sur des cases cibles. Il peut se déplacer dans les quatre directions, et pousser (mais pas tirer) une seule caisse à la fois.
Une fois toutes les caisses rangées (c'est parfois un vrai casse-tête), le niveau est réussi et le joueur passe au niveau suivant, plus difficile en général.
L'idéal est de réussir avec le moins de coups possibles (déplacements et poussées).

### Compétences travaillées

- Découverte de la libC Ncurses
- Une bonne gestion des hitbox et des déplacements
- Bien structurer son code, au risque de s'y perdre...

### Installation

Pour lancer le jeu, il vous faudra

Une map qui devra ressembler a quelque chose de semblable :

[![sokoban_command](https://user-images.githubusercontent.com/91087072/175766427-aa2ab1ad-28ad-422f-af8a-d658205d608a.PNG)](https://user-images.githubusercontent.com/91087072/175766427-aa2ab1ad-28ad-422f-af8a-d658205d608a.PNG)

Une fois que vous avez la map, il vous suffit de compiler le programme avec la commande "make".

Lancer ensuite le binaire suivi du chemin d'accès de votre map comme ceci :

[![sokoban_command](https://user-images.githubusercontent.com/91087072/175766428-a4d46fbe-8f9a-41fa-be6d-db907cdd8c66.png)](https://user-images.githubusercontent.com/91087072/175766428-a4d46fbe-8f9a-41fa-be6d-db907cdd8c66.png)

Une fois le programme lancé, vous pouvez commencer à jouer.

[![sokoban_map](https://user-images.githubusercontent.com/91087072/175766426-f4a858c0-89b2-42fa-a6d1-75420c887784.png)](https://user-images.githubusercontent.com/91087072/175766426-f4a858c0-89b2-42fa-a6d1-75420c887784.png)

## Touches

Pour vous déplacez, utiliser les croix directionnels.

Pour quitter, utiliser echap.

Rien de plus simple !

## Fabriqué avec

* [Visual Studio Code](https://code.visualstudio.com/) - Environnement de développement
* [C](https://fr.wikipedia.org/wiki/C_(langage)) - Langage de programmation
* [Ncurses](https://invisible-island.net/ncurses/man/ncurses.3x.html) - Librairie pour le language C
