# Sokoban

## Principe du jeu

Sokoban est un jeu de puzzle dans lequel le joueur doit déplacer des caisses sur des cibles en utilisant les touches de direction. Le joueur incarne un déménageur qui doit déplacer des caisses pour les mettre sur des cibles spécifiques. Le but est de résoudre tous les niveaux en utilisant un minimum de mouvements.

## Compétences acquises

J'ai réalisé le jeu Sokoban en langage C, un jeu de réflexion où le joueur doit pousser des caisses vers des emplacements spécifiques sur un plateau de jeu. Mon implémentation a couvert les fonctionnalités suivantes :

- Affichage du plateau de jeu en utilisant des caractères ASCII pour représenter les murs, les caisses, le personnage et les emplacements vides.
- Déplacement du personnage sur le plateau de jeu en utilisant les touches directionnelles du clavier.
- Vérification des mouvements valides du personnage et des caisses, en prenant en compte les murs et les obstacles.
- Gestion des interactions entre le personnage, les caisses et les emplacements vides pour déterminer si le joueur a gagné la partie.
- Possibilité de charger des niveaux à partir de fichiers texte pour jouer à des configurations de plateau différentes.

J'ai veillé à écrire un code propre et bien commenté, en suivant les conventions d'écriture du langage C pour assurer la lisibilité du code. Des tests approfondis ont été effectués pour garantir la validité du jeu dans différentes situations.

Ce projet a renforcé mes compétences en programmation en langage C, notamment dans la manipulation des tableaux, la gestion des entrées utilisateur et la logique du jeu. Il m'a également apporté une meilleure compréhension des algorithmes de déplacement et des mécanismes de jeu.

## Compilation

Pour compiler le projet en mode console, utilisez la commande `make` puis `./sokoban <numéro du niveau> (level<numéro du niveau>.txt)`.
Pour compiler le projet en mode graphique, utilisez la commande `make` puis `./sokoban --sdl2 <numéro du niveau> (level<numéro du niveau>.txt)`.

## Version de gcc

gcc version 9.3.0

