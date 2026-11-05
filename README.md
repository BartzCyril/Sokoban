# Sokoban en C

> Jeu de réflexion Sokoban écrit en C, jouable dans le terminal ou en fenêtre graphique avec la bibliothèque SDL2, avec des niveaux chargés depuis des fichiers texte.

![C](https://img.shields.io/badge/C-A8B9CC?logo=c&logoColor=black)
![SDL2](https://img.shields.io/badge/SDL2-1E3A8A)
![Make](https://img.shields.io/badge/Makefile-6D00CC?logo=gnu&logoColor=white)

## Sujet

Projet universitaire (licence informatique). Le joueur incarne un déménageur qui doit pousser toutes les caisses sur les emplacements cibles. Une caisse ne peut être que poussée, jamais tirée, et on ne peut pas en pousser deux à la fois.

## Fonctionnalités

- **Chargement des niveaux** depuis un fichier texte (`level1.txt` : dimensions, nombre de cibles, puis la grille)
- **Deux modes d'affichage** : terminal (caractères ASCII) ou fenêtre graphique SDL2
- Déplacement du joueur, poussée des caisses, collisions avec les murs et les autres caisses
- Détection de la victoire quand toutes les cibles sont couvertes

| Symbole | Signification |
| --- | --- |
| `#` | Mur |
| `@` | Joueur |
| `$` | Caisse |
| `.` | Cible |

## Compétences acquises

- **Langage C** : structures, allocation et libération de la mémoire, lecture de fichiers
- **Pointeurs de fonction** pour choisir l'affichage (terminal ou SDL2) et la gestion des entrées sans dupliquer la boucle de jeu
- **Programmation modulaire** : séparation grille / joueur / affichage en fichiers `.c` / `.h`
- **Bibliothèque graphique SDL2** : fenêtre, rendu, gestion des événements clavier
- **Compilation** avec un Makefile (règles par module, compilation de SDL2 depuis les sources)
- **Documentation** du code générée avec Doxygen

## Compiler et jouer

Prérequis : gcc et make (Linux).

```bash
make sdl2        # compile la SDL2 fournie dans le dossier SDL2/ (une seule fois)
make             # compile le jeu
```

```bash
./sokoban 1          # mode terminal, charge level1.txt
./sokoban --sdl2 1   # mode graphique
```

En mode terminal : `h` gauche, `j` bas, `k` haut, `l` droite, `q` pour quitter (valider avec Entrée).

Autres règles du Makefile : `make doc` (documentation Doxygen), `make clean`.
