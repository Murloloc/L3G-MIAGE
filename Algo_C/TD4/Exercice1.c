//1. Écrire un sous-programme qui étant donné un entier rend sa moitié. Écrire le
//programme principal (main) qui demande un entier au clavier,
// appelle le sousprogramme avec cet entier et affiche le résultat.

#include <stdio.h>

float rend_moitie(float n) {

    return n/2;
}

int main() {

    float a,res;

    printf("Saisissez un entier\n");
    scanf("%f", &a);
    res = rend_moitie(a);
    printf("%.1f", res);

    return 0;
}