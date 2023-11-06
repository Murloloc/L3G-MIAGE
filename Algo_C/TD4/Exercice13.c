//13. Écrire un sous-programme qui étant donné un tableau de n réels rend la plus
//grande valeur du tableau

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

float rend_max(float *tab, int n) {

    int i;
    float max;
    max = tab[0];
    i = 1;
    while (i < n) {
        if (tab[i] > max) {
            max = tab[i];
        }
        i++;
    }
    return max;
}

int main() {

    int nb;
    float max, t[N];

    printf("Combien de valeurs voulez vous ?\n");
    scanf("%d", &nb);
    while (nb < 1 || nb > N) {
        printf("Votre nombre doit etre strictement positif re donnez un autre nombre\n");
        scanf("%d", &nb);
    }

    rempli_tableau(t, nb);
    max = rend_max(t, nb);
    printf("La valeur max du tableau est %.2f\n", max);

    return 0;
}

