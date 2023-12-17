//
#include <stdio.h>
#include <string.h>

typedef char STRING[80];

typedef struct {
    STRING marque;
    int ref;
    float prix;
    int disp;
} CAR;

#define MAX 1000

void initialisation(CAR *tab, int nbv) {

    int i;
    i = 0;
    while (i < nbv) {
        printf("\nDonnez la marque :");
        scanf("%s", tab[i].marque);
        printf("\nDonnez la ref :");
        scanf("%d", &tab[i].ref);
        printf("\nDonnez le prix :");
        scanf("%f", &tab[i].prix);
        printf("\nDonnez la disp :");
        scanf("%d", &tab[i].disp);
        i++;
    }
    return;
}

void ajout(CAR *tab, int *nbv) {

    int i;
    i = *nbv;
    *nbv = *nbv + 1;

    printf("\nDonnez la marque :");
    scanf("%s", tab[i].marque);
    printf("\nDonnez la ref :");
    scanf("%d", &tab[i].ref);
    printf("\nDonnez le prix :");
    scanf("%f", &tab[i].prix);
    printf("\nDonnez la disp :");
    scanf("%d", &tab[i].disp);
}

void affiche_car_disp_selon_marque(CAR *tab, int nbv, STRING mar) {

    int i;
    i = 0;
    while (i < nbv) {
        if (strcmp(tab[i].marque, mar) == 0 && tab[i].disp == 1) {
            printf("%s\n", tab[i].marque);
            printf("%d\n", tab[i].ref);
            printf("%f\n", tab[i].prix);
            printf("%d\n", tab[i].disp);
            printf("\n");
        }
        i++;
    }
    return;
}

float moyenne_loc(CAR *tab, int nbv) {

    int i;
    float s;

    i = 0;
    s = 0;

    while (i < nbv) {

        s = s + tab[i].prix;
        i++;
    }
    return s / nbv;
}

int disp_selon_ref(CAR *tab, int nbv, int refer, int *disp) {

    int i, flag;
    flag = 0;
    i = 0;
    while (i < nbv && flag == 0) {
        if (tab[i].ref == refer) {
            *disp = tab[i].disp;
            flag = 1;
        }
        i++;
    }
    return flag;
}

int reserve_car_selon_ref(CAR *tab, int nbv, int refer, int *dejares) {

    int i, flag;
    flag = 0;
    i = 0;
    while (i < nbv && flag == 0) {
        if (tab[i].ref == refer) {
            flag = 1;
            if (tab[i].disp == 0) {
                *dejares = 0;
            } else {
                tab[i].disp = 0;
            }
        }
        i++;
    }
    return flag;
}

void tri_car_decroissant(CAR *tab, int nbv) {

    int i, flag;
    CAR ech;
    flag = 1;
    while (flag == 1) {
        flag = 0;
        i = 0;
        while (i < nbv) {
            if (tab[i].ref < tab[i + 1].ref) {
                ech = tab[i];
                tab[i] = tab[i + 1];
                tab[i + 1] = ech;
            }
            i++;
        }
    }
    return;
}

int rend_ref_disp_moins_cher(CAR *tab, int nbv, int *refe) {

    int i, flag;
    float min;
    i = 0;

    while (i < nbv && flag == 0) {
        if (tab[i].disp) {
            min = tab[i].prix;
            *refe = tab[i].ref;
            flag = 1;
        }
    }
    while (i < nbv) {
        if (tab[i].disp && tab[i].prix < min) {
            min = tab[i].prix;
            *refe = tab[i].ref;
        }
        i++;
    }
    return flag;
}

int plein(int nbv, int max) {
    return nbv == max;
}

int vide(int nbv) {
    return nbv == 0;
}

int main() {

    int choix, nbval, reference, disponible, dejareserve;
    float res1;
    CAR t[MAX];
    STRING marque;

    printf("Combien de vehicules au départ : ");
    scanf("%d", &nbval);
    while (nbval < 0 || nbval > 1000) {
        printf("\nSaisie incorrecte reessayez : ");
        scanf("%d", &nbval);
    }

    initialisation(t, nbval);

    do {
        printf("\n1 : ajout ");
        printf("\n2 : affiche car dispo selon marque");
        printf("\n3 : moyenne prix location");
        printf("\n4 : disp selon ref");
        printf("\n5 : reserve selon ref");
        printf("\n6 : tri decroissant selon ref");
        printf("\n7 : ref car disp le moins cher");
        printf("\n8 : fin ");
        printf("\nQuel est votre choix : ");
        scanf("%d", &choix);
        while (choix < 0 || choix > 7) {
            printf("\nSaisie incorrecte reessayez : ");
            scanf("%d", &choix);
        }
        if (choix == 1) {
            if (plein(nbval, MAX)) {
                printf("\nLe tableau est plein impossible");
            } else {
                printf("\nVeuillez saisir les informations");
                ajout(t, &nbval);
            }
        }
        if (choix == 2) {
            printf("\nMarque : ");
            scanf("%s", marque);
            affiche_car_disp_selon_marque(t, nbval, marque);
        }
        if (choix == 3) {
            res1 = moyenne_loc(t, nbval);
            printf("\nLa moyenne est %f", res1);

        }
        if (choix == 4) {
            printf("\nReference : ");
            scanf("%d", &reference);
            if (disp_selon_ref(t, nbval, reference, &disponible)) {
                if (disponible) {
                    printf("\nLa voiture est disponible");
                } else {
                    printf("\nLa voiture n est pas disponible");
                }
            } else {
                printf("\nLa reference n'existe pas");
            }
        }
        if (choix == 5) {
            printf("\nReference : ");
            scanf("%d", &reference);
            if (reserve_car_selon_ref(t, nbval, reference, &dejareserve)) {
                if (dejareserve == 0) {
                    printf("\n Le vehicule est indisponible");
                } else {
                    printf("\nLe vehicule a ete reserve");
                }
            } else {
                printf("\nLa reference n'existe pas");
            }
        }
        if (choix == 6) {
            tri_car_decroissant(t, nbval);
        }
        if (choix == 7) {
            if (rend_ref_disp_moins_cher(t, nbval, &reference)) {
                printf("\nLa reference du vehicule disp le moins cher est %d", reference);
            } else {
                printf("\nAucun vehicule n'est disponible");
            }

        }
    } while (choix != 8);

    printf("\nFin du programme");

    return 0;
}