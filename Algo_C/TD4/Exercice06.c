//6. Utiliser le sous-programme défini dans l’exercice 5 pour dessiner un sapin de Noël
//comme ci-dessous :
//    *
//   ooo
//  *****
// ooooooo
// *********
//ooooooooooo
//   ***
//   ***

#include <stdio.h>

void affiche_nfoisc(int n, char c) {

    int i;
    i = 0;
    while (i < n) {
        printf("%c", c);
        i++;
    }
    return;
}

int main() {

    int i, nb_car, nb_ligne, nb_espace;
    char carac;

    printf("Combien de lignes voulez vous ?\n");
    scanf("%d", &nb_ligne);

    nb_car = 1;
    nb_espace = nb_ligne - 1;

    i = 0;

    while (i < nb_ligne) {

        affiche_nfoisc(nb_espace,' ');

        if (i % 2 == 0) {
            carac='*';
            affiche_nfoisc(nb_car, carac);
        } else {
            carac='o';
            affiche_nfoisc(nb_car, carac);
        }
        i++;
        printf("\n");
        nb_car = nb_car + 2;
        nb_espace = nb_espace - 1;
    }
    i = 0;
    while (i < 2) {
        carac='*';
        nb_espace = nb_ligne - 2;
        affiche_nfoisc(nb_espace, ' ');
        affiche_nfoisc(3, carac);
        printf("\n");
        i++;
    }
    return 0;
}