//17. Écrire un sous-programme qui étant donnés deux tableaux de réels (pas
//obligatoirement de la même taille) indique lequel des deux a la moyenne la plus
//élevée

#include <stdio.h>

#define N1 5
#define N2 6

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

float rend_plus_grande_moyenne(float *tab1, float *tab2, int n1, int n2) {

    if (calcule_moyenne(tab1, n1) > calcule_moyenne(tab2, n2)) {
        return calcule_moyenne(tab1, n1);
    } else {
        return calcule_moyenne(tab2, n2);
    }

}

int main() {

    float t1[N1], t2[N2], res;

    rempli_tableau(t1, N1);
    rempli_tableau(t2, N2);

    res = rend_plus_grande_moyenne(t1, t2, N1, N2);
    printf("%f", res);

    return 0;
}