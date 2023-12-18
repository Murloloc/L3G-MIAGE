//Exam 21/22 session 1 Exo 3
//Exercice 3 (5 points) : Utilisation d’une pile pour calculer une expression en notation polonaise
//inversée (NPI). Une expression arithmétique en NPI présente d’abord les opérandes puis le ou
//les opérateurs qui s’appliqueront sur ces opérandes. Par exemple, 3 4 + est l’expression en NPI
//qui correspond à l’expression 3+4. 3 4 5 + x est l’expression en NPI qui correspond à
//l’expression 3 x (4 + 5). Et l’expression en NPI 3 4 + 5 x correspond à l’expression (3 + 4 ) x
//5. Un opérateur s’applique donc aux 2 opérandes qui le précède.
//Pour écrire un programme qui calcule une expression en NPI, on utilise une pile. On lit
//l’expression de gauche à droite. Chaque fois qu’on rencontre un chiffre, on l’empile, chaque
//fois qu’on rencontre un opérateur, on dépile deux nombres, on applique l’opérateur et on empile
//le résultat. A la fin de la lecture de l’expression, la pile contient un seul élément qui est le
//résultat du calcul.
//1) Décrivez avec des dessins le fonctionnement de la pile pour l’expression 3 4 5 + x puis
//pour l’expression 3 4 + 5 x
//2) Écrivez le programme qui calcule la valeur d’une expression écrite en NPI. Pour
//simplifier le programme, on considérera :
//a. Que l’expression ne comprend que des chiffres de 0 à 9 et les opérateurs + et x
//(par exemple 5 8 9 + x 1 +)
//b. Que l’expression est tapée par l’utilisateur en une seule saisie que l’on rangera
//dans une chaîne de caractères. Chaque case contiendra donc soit un chiffre soit
//un opérateur, sous la forme d’un caractère. On considèrera que l’expression est
//juste (elle ne contient pas d’erreurs de saisie).
//c. Si le caractère correspond à un chiffre, vous le convertirez en entier (si c est la
//variable caractère i = c – 48 vous donne l’entier correspondant). Si le caractère
//correspond à un opérateur, vous effectuerez l’opération correspondante.
//Nota bene : vous utiliserez bien sûr les sous-programmes empiler et dépiler vu en cours.


#include <stdio.h>
#include <string.h>

typedef char STRING[80];


void empiler(STRING *tab, int *nbv, STRING e) {

    strcpy(tab[*nbv],e);
    *nbv = *nbv + 1;
    return;
}

void depiler(STRING *tab, int *nbv, STRING *val_sup) {

    strcpy(*val_sup, tab[*nbv - 1]);
    *nbv = *nbv - 1;
    return;
}

int main(){

    char t[10];
    STRING polonaise;

    printf("\nDonnez l'operation NPI : ");
    scanf("%s",polonaise);






    return 0;
}

