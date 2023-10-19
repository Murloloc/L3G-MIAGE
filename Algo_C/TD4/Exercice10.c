//10. Écrire un sous-programme en C qui détermine si un nombre entier positif est
//premier ou pas. Rappel : un nombre premier est un nombre divisible uniquement
//par 1 et lui-même. Utiliser ce sous-programme pour écrire un programme qui
//affiche tous les nombres premiers inférieurs à 1000.

#include <stdio.h>

void est_premier(int n) {

    int i, flag;

    i = 2;
    flag = 0;
    while (i < n && flag != 1) {
        if (n % i == 0) {
            flag = 1;
        }
        i++;
    }
    if (flag == 1) {
        printf("%d n'est pas premier\n", n);
    } else {
        printf("%d est premier\n", n);
    }
    return;
}

int main(){

    int nb;

    printf("Donnez un nombre dont vous voulez savoir s'il est premier ou pas\n");
    scanf("%d",&nb);
    est_premier(nb);

    return 0;
}