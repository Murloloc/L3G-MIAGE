//7. Écrire un sous-programme qui étant donné un réel x et un entier n >=0 rend x^^n
//Écrire le programme principal (main) qui affiche les valeurs de a^^a pour tous les
//entiers a de 1 à 10.

#include <stdio.h>

float calcule_puissance(float x, int n) {

    float res;
    int i;

    i = 0;
    res = 1;

    while (i < n) {
        res = res * x;
        i++;
    }
    return res;
}

int main() {

    int a;
    float res1;

    a = 1;

    while (a <= 10) {
        res1 = calcule_puissance(a, a);
        printf("%.2f\n", res1);
        a++;
    }
    return 0;
}