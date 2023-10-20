//13. Écrire un sous-programme qui étant donné un tableau de n réels rend la plus
//grande valeur du tableau

#include <stdio.h>

void rempli_tableau(float t[], int n) {

    int i;
    float x;

    i = 0;
    while (i < n) {
        printf("Donnez la valeur %d du tableau :\n", i + 1);
        scanf("%f", &x);
        t[i] = x;
        i++;
    }
    return;
}

float rend_max(float t[],int n){

    int i;
    float max;
    max=t[0];
    i=1;
    while (i<n){
        if (t[i]>max){
            max=t[i];
        }
        i++;
    }
    return max;
}

int main() {

    int nb;
    float max;

    printf("Combien de valeurs voulez vous ?\n");
    scanf("%d", &nb);
    while (nb < 1) {
        printf("Votre nombre doit etre strictement positif re donnez un autre nombre\n");
        scanf("%d", nb);
    }

    float t[nb];

    rempli_tableau(t,nb);
    max= rend_max(t,nb);
    printf("La valeur max du tableau est %.2f\n",max);

    return 0;
}

