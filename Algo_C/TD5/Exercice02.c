//2. Écrire un programme qui étant donné un mot lu au clavier affiche un mot contenant les
//3 premiers caractères du mot

#include <stdio.h>

#define N 30

int main() {

    char mot[N];

    printf("Donnez votre mot\n");
    fgets(mot,30,stdin);
    printf("Voici les 3 premieres lettre de votre mot : %.3s",mot);

    return 0;
}