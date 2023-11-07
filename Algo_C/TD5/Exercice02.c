//2. Écrire un programme qui étant donné un mot lu au clavier affiche un mot contenant les
//3 premiers caractères du mot

#include <stdio.h>

#define N 30

int main() {

    char mot[N];

    printf("Donnez votre mot\n");
    fgets(mot, 30, stdin);
    printf("%.3s", mot);
    //ou un while mais nul
    //ou on crée mot2 et mot2[0]=mot[0] ... mot2[3]="/0"

    return 0;
}