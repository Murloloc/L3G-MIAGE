#include <stdio.h>
#include <string.h>

#define MAX 5

typedef char STRING[80];

void ajout_file(STRING *tab, int *nbv, STRING e) {

    strcpy(tab[*nbv], e);
    *nbv = *nbv + 1;
    return;
}

void supp_file(STRING *tab, int *nbv, STRING *val_sup) {

    int i;
    strcpy(*val_sup, tab[0]);

    i = 0;
    while (i < *nbv - 1) {
        strcpy(tab[i], tab[i + 1]);
        i++;
    }
    *nbv = *nbv - 1;
    return;
}

int plein(int nbv, int max) {
    return nbv == max;
}

int vide(int nbv) {
    return nbv == 0;
}

void affiche_file(STRING *tab, int nbv) {

    int i;
    i = 0;
    while (i < nbv) {
        printf("\n%d %s\n", i + 1, tab[i]);
        i++;
    }
}

int main() {

    STRING nom, t[MAX], nom_sup;
    int nbval, choix, valid_input;
    nbval = 0;

    do {
        printf("\nQue voulez vous faire ?\n");
        printf("1 : ajout d'un patient\n");
        printf("2 : suppression d'un patient\n");
        printf("3 : affichage file d'attente\n");
        printf("4 : rien, sortir du programme\n");

        valid_input = 0;

        while (valid_input == 0) {

            printf("\nQue voulez-vous faire : ");

            if (scanf("%d", &choix) != 1 || choix < 1 || choix > 4) {
                // La saisie n'est pas un entier entre 1 et 5
                printf("\nSaisie incorrecte. Veuillez entrer un nombre entier entre 1 et 4.\n");
                // Nettoie le tampon d'entrée
                while (getchar() != '\n');
            } else {
                valid_input = 1;
            }
        }
        if (choix == 1) {
            if (plein(nbval, MAX)) {
                printf("\nDesole la file est pleine\n");
            } else {
                printf("\nVeuillez entrer votre nom : ");
                scanf("%s", nom);
                ajout_file(t, &nbval, nom);
            }
        }
        if (choix == 2) {
            if (vide(nbval)) {
                printf("\nLa file est deja vide\n");
            } else {
                supp_file(t, &nbval, &nom_sup);
                printf("\n%s a ete supprime de la file\n", nom_sup);
            }
        }
        if (choix == 3) {

            if (vide(nbval)) {
                printf("\nLa file est vide\n");
            } else {
                affiche_file(t, nbval);
            }
        }
    } while (choix != 4);

    return 0;
}
