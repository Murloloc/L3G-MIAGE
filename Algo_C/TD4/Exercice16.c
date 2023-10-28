//16. Écrire un sous-programme qui étant donnés un tableau de n réels et un réel, rend
//si le réel appartient ou pas au tableau et s’il appartient, rend le rang de sa première
//occurrence.

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

int cherche_valeur(float *tab, int n, float x) {

    int i, indice;

    i = 0;
    while (i < n) {
        if (tab[i] == x) {
            indice = i;
        }
        i++;
    }
    return indice;
}

int main() {

    float t[N],valeur_cherchee;

    rempli_tableau(t,N);
    printf("Donnez la valeur cherchee dans le tableau");
    scanf("%f",&valeur_cherchee);
    printf("La premiere occurence de cette valeur %d",cherche_valeur(t,N,valeur_cherchee));



    return 0;
}