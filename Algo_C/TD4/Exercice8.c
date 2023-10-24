//8. On peut calculer le nombre de combinaison de p éléments parmi n en utilisant la
//formule suivante : Cn,p=n!/(p!(n-p)!), pour tout n>=p>=0. Cela permet de savoir
//par exemple combien il y a de combinaisons possibles au loto. Écrire un
//programme en C qui demande à l’utilisateur les valeurs de n et de p, vérifie que
//n>=p>=0 et le cas échéant affiche le résultat en utilisant le sous-programme
//factoriel.

#include <stdio.h>

long calcule_factoriel(int x) {

    int i;
    long P;

    P = 1;
    i = 1;
    while (i <= x) {
        P = P * i;
        i++;
    }
    return P;
}

int main() {

    int p, n;

    printf("Combien d elements ?\n");
    scanf("%d", &p);
    printf("parmi combien ?\n");
    scanf("%d", &n);

    while (n < 0 || p < 0 || n < p) {
        printf("Re donnez les valeurs il faut que n>=p>=0\n");
        printf("Combien d elements ?\n");
        scanf("%d", &p);
        printf("parmi combien ?\n");
        scanf("%d", &n);
    }

    printf("%ld\n", calcule_factoriel(n) / (calcule_factoriel(p) * calcule_factoriel(n - p)));

    return 0;
}