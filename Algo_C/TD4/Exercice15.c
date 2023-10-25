
#include <stdio.h>

#define N 10

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

void tri_a_bulle(float *tab, int n) {

    int i, flag;
    float ech;

    flag = 1;
    while (flag == 1) {
        flag = 0;
        i = 0;
        while (i < n - 1) {
            if (tab[i] < tab[i + 1]) {
                ech = tab[i];
                tab[i] = tab[i + 1];
                tab[i + 1] = ech;
                flag = 1;
            }
            i = i + 1;
        }
    }
    return;
}


float calcule_moyenne(float *tab, int n) {

    int i;
    float m;

    i = 0;
    m = 0;
    while (i < n) {
        m = m + tab[i];
        i++;
    }
    return m / n;
}

float rend_max_et_son_rang(float *tab, int n, int *p) {

    int i, rang_max;
    float max;

    max = tab[0];
    rang_max = 0;
    i = 1;
    while (i < n) {
        if (tab[i] > max) {
            max = tab[i];
            rang_max = i;
        }
        i++;
    }
    *p=rang_max;
    return max;
}

int main() {

    float t[N];
    int ind;

    rempli_tableau(t, N);
    affiche_tab(t, N);
    printf("La moyenne est %.2f\n", calcule_moyenne(t, N));
    printf("L'indice %d du tableau a pour valeur max du %.2f\n",ind,rend_max_et_son_rang(t, N,&ind));


    return 0;
}


