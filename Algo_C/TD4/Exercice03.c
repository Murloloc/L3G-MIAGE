//3. Écrire un sous-programme qui étant donné un entier rend son factoriel. Écrire le
//programme principal (main) qui demande un entier au clavier,
// appelle le sousprogramme pour cet entier et affiche le résultat.

#include <stdio.h>

long calcule_factoriel(int n) {

    int i;
    long p;

    p = 1;
    i = 1;
    while (i <= n) {
        p = p * i;
        i++;
    }
    return p;
}

int main() {

    int a;
    long res;

    printf("Saisissez un entier\n");
    scanf("%d", &a);
    res = calcule_factoriel(a);
    printf("Le factoriel de %d est %ld", a, res);

    return 0;
}
