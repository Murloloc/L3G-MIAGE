//1. Écrire un sous-programme qui étant donné un mot rend le nombre de fois que la lettre
//« x » apparaît dans le mot

#include <stdio.h>
#include <string.h>

#define N 30

int rendNombreOccurenceLettre(char *m, char l) {

    int i, cpt;

    i = 0;
    cpt = 0;

    while (i < strlen(m)) {
        if (m[i] == l) {
            cpt++;
        }
        i++;
    }
    return cpt;
}

int main() {

    char mot[N], lettre, rc;
    int res;

    printf("Donnez votre mot\n");
    fgets(mot,30,stdin);
    printf("Quelle lettre cherchez vous ?\n");
    scanf("%c", &rc);
    scanf("%c", &lettre);

    res = rendNombreOccurenceLettre(mot, lettre);
    printf("La lettre %c apparait %d fois dans le mot %s\n", lettre, res, mot);


    return 0;
}

