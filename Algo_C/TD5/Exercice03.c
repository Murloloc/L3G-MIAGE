//3. Écrire un programme qui étant donné un mot lu au clavier affiche un mot qui contient
//les 2 derniers caractères du mot


#include <stdio.h>
#include <string.h>

#define N 30

int main() {

    char mot[N];

    printf("Donnez votre mot\n");
    fgets(mot,30,stdin);
    printf("Voici les 2  dernieres lettres de votre mot : %c%c",mot[strlen(mot)-1],mot[strlen(mot)-2]);

    return 0;
}