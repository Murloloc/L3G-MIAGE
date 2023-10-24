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

void affiche_ligne_etoile(int n) {

    int i;

    i=0;
    while (i<n){
        printf("*");
        i++;
    }
    printf("\n");
    return;
}

int main() {

    int nb_ligne,i;

    printf("Donnez le nombre d'entier voulu\n");
    scanf("%d", &nb_ligne);

    i=1;
    while (i<=nb_ligne){
        affiche_ligne_etoile(i);
        i++;
    }
    return 0;
}
