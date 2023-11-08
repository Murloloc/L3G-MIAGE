//13. Écrire un programme en C qui demande à l’utilisateur de taper "oui" ou "non" et qui
//redemande la saisie tant que l’utilisateur se trompe. A la fin, le programme affichera la
//dernière chaîne tapée par l’utilisateur.

#include <stdio.h>
#include <string.h>

int main() {

    char mot[80];

    printf("Ecrivez 'oui' ou 'non' \n");
    scanf("%s", mot);

    while (strcmp(mot, "oui") != 0 && strcmp(mot, "non") != 0) {
        printf("Vous vous etes trompe. Ecrivez 'oui' ou 'non' \n");
        scanf("%s", mot);
    }

    printf("%s", mot);

    return 0;
}
