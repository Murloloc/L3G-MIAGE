//Exercice 8 : Ecrire un programme qui simule l'évolution du contenu d'un bus d'un terminus à
//un autre. Les arrêts de bus sont numérotés de 0 à N. A chaque arrêt, les personnes qui montent
//donnent leur nom à l’ordinateur et le numéro de l’arrêt où elles descendront. A chaque arrêt,
//l’ordinateur appelle les personnes qui doivent descendre

#include <stdio.h>
#include <string.h>
#define MAX 7

typedef char STRING[80];

typedef struct{
    STRING nom[30];
    int cpt;
}ARRET;

int main(){

    STRING nom;



    return 0;
}