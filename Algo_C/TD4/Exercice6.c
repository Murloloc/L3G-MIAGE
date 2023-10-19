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
    char c1, c2,c3;

    printf("Combien de lignes voulez vous ?\n");
    scanf("%d", &nb_ligne);

    i = 0;
    nb_car = 1;
    nb_espace = nb_ligne - 1;
    c1 = '*';
    c2 = 'o';
    c3 = ' ';

    while (i < nb_ligne) {

        affiche_nfoisc(nb_espace,c3);

        if (i % 2 == 0) {
            affiche_nfoisc(nb_car, c1);
            printf("\n");
            nb_car = nb_car + 2;
            nb_espace = nb_espace - 1;
        } else {
            affiche_nfoisc(nb_car, c2);
            printf("\n");
            nb_car = nb_car + 2;
            nb_espace = nb_espace - 1;
        }
        i++;
    }
    i = 0;
    while (i < 2) {
        nb_espace = nb_ligne-2;
        affiche_nfoisc(nb_espace,c3);
        affiche_nfoisc(3, c1);
        printf("\n");
        i = i + 1;
    }
    return 0;
}