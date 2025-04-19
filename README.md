# simple_shell

## Description
`simple_shell` est une implémentation basique d'un shell Unix en langage C. Ce projet a été réalisé dans le cadre du cursus Holberton School, afin de mieux comprendre le fonctionnement interne des interpréteurs de commande.

Ce shell est capable de lire une commande depuis l’entrée standard, de l’analyser, et de créer un processus enfant pour exécuter cette commande.

## Fonctionnalités
- Exécution de commandes simples (ex: `ls`, `pwd`, `echo`)
- Gestion du chemin (`$PATH`)
- Redirections d’entrée et de sortie (basiques)
- Gestion des erreurs
- Commande `exit` pour quitter le shell
- Commande `env` pour afficher les variables d’environnement

## Compilation
```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh

