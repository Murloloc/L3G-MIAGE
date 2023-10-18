//4. Écrire un sous-programme qui étant donné un entier n affiche une ligne de n
//étoiles. Utiliser ce sous-programme pour dessiner la forme suivante :
//*
//**
//***
//****
//*****
//******
//*******

#include <stdio.h>

void affiche_etoiles(int n) {

    int i,j,nb_etoile;

    i=0;
    nb_etoile=1;

    while (i<=n){
        j=0;
        while (j<nb_etoile){
            printf("*");
            j++;
        }
        printf("\n");
        nb_etoile++;
        i++;
    }
}

int main() {

    int a;

    printf("Saisissez un entier\n");
    scanf("%d", &a);
    affiche_etoiles(a);

    return 0;
}
