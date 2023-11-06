//2. Écrire un programme qui étant donné un mot lu au clavier affiche un mot contenant les
//3 premiers caractères du mot

#include <stdio.h>
#include <string.h>

#define N 30

int main() {

    char mot[N], abv[3];

    printf("Donnez votre mot\n");
    scanf("%s", mot);

    printf("Voici les 3 premieres lettre de votre mot : %s", abv);

    return 0;
}