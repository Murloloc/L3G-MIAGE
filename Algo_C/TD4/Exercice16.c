//16. Écrire un sous-programme qui étant donnés un tableau de n réels et un réel, rend
//si le réel appartient ou pas au tableau et s’il appartient, rend le rang de sa première
//occurrence.

#include <stdio.h>

#define N 5

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

void cherche_valeur_et_rend_premiere_occurence(float *tab, int n, float x) {

    int i, indice, flag;

    i = 0;
    indice = 0;
    flag = 0;

    while (i < n && flag == 0) {
        if (tab[i] == x) {
            indice = i;
            flag = 1;
        }
        i++;
    }
    if (flag == 1) {
        printf("La valeur %.2f appartient au tab avec pour indice %d", x, indice);
    } else {
        printf("La valeur %.2f n appartient pas au tab", x);
    }
    return;
}

int main() {

    float t[N], valeur_cherchee;

    rempli_tableau(t, N);
    printf("Donnez la valeur cherchee dans le tableau\n");
    scanf("%f", &valeur_cherchee);
    cherche_valeur_et_rend_premiere_occurence(t, N, valeur_cherchee);


    return 0;
}