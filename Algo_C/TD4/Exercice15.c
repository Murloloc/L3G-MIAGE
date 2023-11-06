//15. Écrire un sous-programme qui étant donnés un tableau de n réels et un réel, rend
//le nombre de fois que le réel apparaît dans le tableau. Utiliser ce sous-programme
//pour vérifier si deux tableaux contiennent les mêmes éléments ou pas (sans tenir
//compte de l’ordre).

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

int nombre_occurence_x(float *tab, int n, float x) {

    int i, cpt;

    i = 0;
    cpt = 0;
    while (i < n) {
        if (tab[i] == x) {
            cpt++;
        }
        i++;
    }
    return cpt;
}

int main() {

    int i, flag;
    float t1[N], t2[N];

    rempli_tableau(t1, N);
    rempli_tableau(t2, N);

    i = 0;
    flag = 0;
    while (i < N && flag == 0) {
        if (nombre_occurence_x(t1, N, t1[i]) != nombre_occurence_x(t2, N, t1[i])) {
            flag = 1;
        }
        i++;
    }
    if (flag == 1) {
        printf("Les tab sont pas egaux");
    } else {
        printf("Les tab sont egaux");
    }

    return 0;
}