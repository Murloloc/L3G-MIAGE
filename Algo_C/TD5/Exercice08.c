//8. Écrire un programme qui étant donné une chaîne de caractères lue au clavier affiche une
//chaîne en insérant des astérisques entre les caractères. Ainsi par exemple, "gaston" devra
//devenir "g*a*s*t*o*n"

#include <stdio.h>
#include <string.h>

int main() {

    char mot[80];
    int i;

    printf("Donnez votre mot\n");
    scanf("%s", mot);

    i = 0;
    while (i < strlen(mot)) {
        printf("%c", mot[i]);
        if (i < strlen(mot) - 1) {
            printf("*");
        }
        i++;
    }
    return 0;
}

