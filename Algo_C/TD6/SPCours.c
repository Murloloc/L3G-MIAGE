//SP

#include <stdio.h>

#define MAX 100

//SP cas non ordonné

void ajout_non_ordonne(int *tab, int *nbv, int e) {

    tab[*nbv] = e;
    *nbv = *nbv + 1;

    return;
}

int suppression_non_ordonne(int *tab, int *nbv, int e) {

    int i, flag;

    i = 0;
    flag = 0;
    while (i < *nbv && flag == 0) {
        if (tab[i] == e) {
            flag = 1;
        } else {
            i++;
        }
    }
    if (flag == 1) {
        tab[i] = tab[*nbv - 1];
        *nbv = *nbv - 1;
    }
    return flag;
}


int plein(int nbv, int max) {
    return nbv == max;
}

int vide(int nbv) {
    return nbv == 0;
}

//SP cas ordonné ordre croissant

void ajout_ordonne_croissant(int *tab, int *nbv, int e) {

    int i, flag, num_ajout;

    i = 0;
    flag = 0;

    while (i < *nbv && flag == 0) {
        if (tab[i] >= e) {
            flag = 1;
        } else {
            i++;
        }
    }
    num_ajout = i;
    i = *nbv;

    while (i > num_ajout) {
        tab[i] = tab[i - 1];
        i--;
    }
    tab[num_ajout] = e;
    *nbv = *nbv + 1;

    return;
}

int suppression_ordonne_croissant(int *tab, int *nbv, int e) {

    int i, flag, num_sup;
    i = 0;
    flag = 0;
    while (i < *nbv && flag == 0) {
        if (tab[i] == e) {
            flag = 1;
        } else {
            i++;
        }
    }
    num_sup = i;
    if (flag == 1) {
        while (i < *nbv - 1) {
            tab[i] = tab[i + 1];
        }
        *nbv = *nbv - 1;
    }

    return flag;
}

//File d'attente FIFO first in first out LILO last in last out (ex salle d'attende medecin)
//En tete pour FILE et PILE

void ajout_file(int *tab, int *nbv, int e) {

    tab[*nbv] = e;
    *nbv = *nbv + 1;
    return;
}

int supp_file(int *tab, int *nbv) {

    int val_sup, i;
    val_sup = tab[0];
    i = 0;
    while (i < *nbv - 1) {
        tab[i] = tab[i + 1];
        i++;
    }
    *nbv = *nbv - 1;

    return val_sup;
}

//vide et plein c est la meme

//Pile (ex pile d'assiette) FILO first in last out LIFO last in first out

void empiler(int *tab, int *nbv, int e) {

    tab[*nbv] = e;
    *nbv = *nbv + 1;
    return;
}

int depiler(int *tab, int *nbv) {

    int val_sup;
    val_sup = tab[*nbv - 1];
    *nbv = *nbv - 1;
    return val_sup;
}

//pareil pour vide et plein

//tourniquet

void affichage_tourniquet(int *tab, int nbv, int debut) {

    int i, c;
    i = debut;
    c = 0;
    while (c < nbv) {
        printf("%d\n", tab[i]);
        c++;
        i++;
        if (i == MAX) {
            i = 0;
        }
    }

}

int main() {

    int t[MAX], nb_val, choix, elt, res, val_sup;

    nb_val = 0;

    do {
        printf("1 ajout\n");
        printf("2 suppression\n");
        printf("3 affichage\n");
        printf("0 fin\n");

        printf("Tapez votre choix :");
        scanf("%d", &choix);

        if (choix == 1) {
            if (nb_val == MAX) {
                printf("Desole, plus de place\n");
            } else {
                printf("Quelle valeur ?\n");
                scanf("%d", &elt);
                ajout_non_ordonne(t, &nb_val, elt);
            }
        }
        if (choix == 2) {
            printf("Quelle valeur voulez vous supp : ");
            scanf("%d", val_sup);
            res = suppression_non_ordonne(t, &nb_val, val_sup);
            if (res == 0) {
                printf("Cette valeur n'est pas dans le tableau re essayez");
            }
        }
//menu pas fini
    } while (choix != 0);

    return 0;
}