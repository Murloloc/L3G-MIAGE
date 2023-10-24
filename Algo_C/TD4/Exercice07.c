//7. Écrire un sous-programme qui étant donné un réel x et un entier n >=0 rend x^^n
//Écrire le programme principal (main) qui affiche les valeurs de a^^a pour tous les
//entiers a de 1 à 10.

#include <stdio.h>

float calcule_puissance(float x, int n) {

    float P;
    int i;

    i = 0;
    P = 1;

    while (i < n) {
        P = P * x;
        i++;
    }
    return P;
}

int main() {

    int i;
    float res;

    i = 1;

    while (i <= 10) {
        res = calcule_puissance(i, i);
        printf("%d exposant %d vaut %.2f\n", i, i, res);
        i++;
    }
    return 0;
}