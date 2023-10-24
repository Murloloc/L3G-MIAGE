//12. Écrire un sous-programme qui étant donné un tableau de n réels calcule l’écart type des éléments de ce tableau.
// On utilisera le sous-programme moyenne de l’exercice précédent.

#include <stdio.h>
#include <math.h>

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

float calcule_moyenne(float *t, int n) {

    int i;
    float m;

    i = 0;
    m = 0;
    while (i < n) {
        m = m + t[i];
        i++;
    }
    return m / n;
}

float calcule_ecart_type(float *t,int n){

    int i;
    float ecart_moyenne,variance;

    i = 0;
    ecart_moyenne = 0;
    while (i < n) {
        ecart_moyenne = ecart_moyenne + ((t[i] - calcule_moyenne(t,n)) * (t[i] - calcule_moyenne(t,n)));
        i = i + 1;
    }
    variance = ecart_moyenne / n;
    return sqrt(variance);

}

int main(){

    int nb;
    float ecart_type;

    printf("Combien de valeurs voulez vous ?\n");
    scanf("%d",&nb);
    while (nb<1){
        printf("Votre nombre doit etre strictement positif re donnez un autre nombre\n");
        scanf("%d",&nb);
    }

    float t[nb];

    rempli_tableau(t,nb);
    ecart_type= calcule_ecart_type(t,nb);
    printf("L'ecart type est de %.2f\n",ecart_type);

    return 0;
}
