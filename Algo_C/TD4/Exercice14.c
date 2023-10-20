//14. Écrire un sous-programme qui étant donné un tableau de n réels rend l’indice de
//la plus grande valeur du tableau. Utiliser ce sous-programme pour ré-écrire le tri
//par permutation

#include <stdio.h>

void rempli_tableau(float t[], int n) {

    int i;

    i = 0;
    while (i < n) {
        printf("Donnez la valeur %d du tableau :\n", i + 1);
        scanf("%f", &t[i]);
        i++;
    }
    return;
}

int rend_indice_plus_grande_valeur(float t[],int n){

    int i,indice;
    float max;
    max=t[0];
    i=1;
    while (i<n){
        if (t[i]>max){
            max=t[i];
            indice=i;
        }
        i++;
    }
    return indice;
}


int main() {

    int nb,indice;

    printf("Combien de valeurs voulez vous ?\n");
    scanf("%d", &nb);
    while (nb < 1) {
        printf("Votre nombre doit etre strictement positif re donnez un autre nombre\n");
        scanf("%d",&nb);
    }

    float t[nb];

    rempli_tableau(t,nb);
    indice=rend_indice_plus_grande_valeur(t,nb);
    printf("La plus grande valeur du tableau est a l'indice : %d\n",indice);

    return 0;
}