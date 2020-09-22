# STRUCIT, UN MINI COMPILATEUR C
*PROJET DE COMPILATION L3 INFORMATIQUE - UCA*
Chloé Dubas et June Rousseau


## I - QU'EST-CE QUE STRUCIT ?
Strucit est un compilateur qui traduit un dialecte du C vers un autre dialecte du C, plus proche de la machine, en code 3 adresses.
Ce projet contient les fichiers sources du compilateur, ainsi qu'une batterie de tests fournie initialement avec le sujet.
De plus, il dispose d'un script bash qui permet d'automatiser la compilation des tests avec strucit.


## II - COMMENT COMPILER STRUCIT ?
Il faut se rendre à la racine du projet et executer la commande make. Cela compile la partie frontend et la partie backend de strucit.


Dans les parties suivante, il faut remplacer $fichier par le nom du fichier que vous souhaitez utiliser.

## III - COMMENT UTILISER LA PARTIE FRONTEND DU COMPILATEUR STRUCIT
Il faut se rendre dans le dossier ./sources/frontend et executer la commande:  
`./structfe.out < $fichier_entree > $fichier_sortie`


## IV - COMMENT UTILISER LA PARTIE BACKEND DU COMPILATEUR STRUCIT
Il faut se rendre dans le dossier ./sources/backend et executer la commande:  
`./structbe.out < $fichier_entree`


## V - UTILISATION AUTOMATIQUE DU COMPILATEUR AVEC DES FICHIERS DE TEST
Un script bash est mis à votre disposition afin d'automatiser les tests présents dans le dossier ./Tests . Pour cela, vous pouvez utiliser la commande suivante:  
`./better_than_gcc.sh`

Vous pouvez egalement compiler des tests particuliers avec la commande suivante:  
`./better_than_gcc.sh $fichier1 $fichier2 ...`

**/!\ Attention**, avec la derniere commande, il faut que les fichiers se trouvent dans le dossier ./Tests . /!\
Les fichiers de sorties sont generes dans le dossier ./outputs et se nomment $fichier_3.c .


## VI - NETTOYER LES FICHIERS GENERES
Pour nettoyer les fichiers generes:
- la commande `make clean` supprime les fichiers generes lors de la compilation de strucit (les fichiers objets et les fichiers C generes par Yacc)
- la commande `make mrproper` supprime egalement les executables et les tests generes dans ./outputs(fichier_3.c)


## VII - EN CAS DE PROBLEME POUR LA COMPILATION DE STRUCIT:
Se rendre dans le dossier ./sources/frontend et compiler avec `make`. Sinon, compiler manuellement la partie frontend via la commande suivante:

`flex ANSI-frontend. && bison -v -d structfe.y && gcc lex.yy.c structfe.tab.c strucit_type.c strucit_utils.c strucit_symbols.c strucit_errors.c -o structfe.out -lfl`

Puis se rendre dans le dossier ./sources/backend et compiler avec `make`. Sinon, compiler manuellement la partie backend via la commande suivante:

`flex ANSI-backend.l && bison -v -d structbe.y && gcc lex.yy.c structbe.tab.c -o structbe.out -lfl`
