//14. Écrire un sous-programme qui étant donné un tableau de n réels rend l’indice de
//la plus grande valeur du tableau. Utiliser ce sous-programme pour ré-écrire le tri
//par permutation

#include <stdio.h>

#define N 10

void rempli_tableau(float *tab, int n) {

    int i;

    i = 0;
    while (i < n) {
        printf("Donnez la valeur %d du tableau :\n", i + 1);
        scanf("%f", &tab[i]);
        i++;
    }
    return;
}

void affiche_tab(float *tab, int n) {

    int i;

    printf("Voici le tableau :\n");
    i = 0;

    while (i < n) {
        printf("%.2f", tab[i]);
        i++;
        printf("\n");
    }
    return;
}

int rend_indice_plus_grande_valeur(float *tab, int n) {

    int i, ind;
    float max;

    ind = 0;
    max = tab[0];
    i = 1;
    while (i < n) {
        if (tab[i] > max) {
            max = tab[i];
            ind = i;
        }
        i++;
    }
    return ind;
}


void tri_permutation(float *tab, int n) {

    int i, bi, bmax;
    float ech;

    bi = 0;
    while (bi < N - 1) {
        bmax = rend_indice_plus_grande_valeur(tab, n);
        i = bi;
        while (i < N) {
            if (tab[bmax] > tab[i]) {
                bmax = i;
            }
            i++;
        }
        ech = tab[bmax];
        tab[bmax] = tab[bi];
        tab[bi] = ech;

        bi++;
    }
    return;
}

int main() {

    int indice;
    float t[N];

    rempli_tableau(t, N);
    indice = rend_indice_plus_grande_valeur(t, N);
    printf("La plus grande valeur du tableau est a l'indice : %d\n", indice);
    affiche_tab(t, N);
    tri_permutation(t, N);
    affiche_tab(t, N);

    return 0;
}