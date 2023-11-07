//3. Écrire un programme qui étant donné un mot lu au clavier affiche un mot qui contient
//les 2 derniers caractères du mot


#include <stdio.h>
#include <string.h>

#define N 30

int main() {

    char mot[30];

    printf("Donnez votre mot\n");
    fgets(mot,30,stdin);
    printf("%c%c", mot[strlen(mot) - 3], mot[strlen(mot) - 2]);
    //avec scanf -2 -1

    return 0;
}