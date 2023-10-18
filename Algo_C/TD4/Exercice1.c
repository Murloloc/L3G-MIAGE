//1. Écrire un sous-programme qui étant donné un entier rend sa moitié. Écrire le
//programme principal (main) qui demande un entier au clavier,
// appelle le sousprogramme avec cet entier et affiche le résultat.

#include <stdio.h>

float divise_par_deux(float n) {

    n = n / 2;
    return n;
}

int main() {

    float a,res;

    printf("Saisissez un entier");
    scanf("%f", &a);
    res = divise_par_deux(a);
    printf("%.1f", res);

    return 0;
}