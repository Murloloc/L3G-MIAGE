//1. Écrire un sous-programme qui étant donné un mot rend le nombre de fois que la lettre
//« x » apparaît dans le mot

#include <stdio.h>
#include <string.h>

#define N 30

int compte_x(char *m) {

    int i, cpt;

    i = 0;
    cpt = 0;

    while (i < strlen(m)) {
        if (m[i] == 'x') {
            cpt++;
        }
        i++;
    }
    return cpt;
}

int main() {

    char mot[N];
    int res;

    printf("Donnez votre mot\n");
    fgets(mot, 30, stdin);

    res = compte_x(mot);
    printf("La lettre x apparait %d fois dans le mot %s\n", res, mot);


    return 0;
}

