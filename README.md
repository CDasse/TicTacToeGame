# TicTacToe Game

## Description

Une version simple du jeu du morpion, où deux joueurs humains s’affrontent sur le même terminal/console.

Le code est écrit en C, et utilise un makefile pour la compilation.

## Prérequis

* Un compilateur C (ex. : gcc)
* Les outils GNU standards (make, etc.)
* Un système d’exploitation capable d’exécuter des programmes C
(Linux, macOS, ou Windows avec un environnement adapté)

## Installation

```
git clone https://github.com/CDasse/TicTacToeGame.git
cd TicTacToeGame
make
./bin/tictactoegame 
```
Cela compilera le projet et générera l’exécutable dans le répertoire bin.

## Guide d'utilisation

Suivez les instructions affichées à l’écran.

Choisissez un joueur pour commencer (« X »).

Entrez les coordonnées de votre coup (ligne et colonne) quand demandé.

Le jeu détecte automatiquement la victoire.

Pour recommencer, relancez simplement l’exécutable.

## Structure du projet

```
├── TicTacToeGame/
│   ├── tictactoegame.c       # Fichier source du projet
├── Makefile                  # Compilation avec 'make'
└── bin/                      # Exécutable généré
```

## Astuces & remarques

* Supprimer l’exécutable généré :
```
make clean
```

## Contribution

Auteur : @CDasse
