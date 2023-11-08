//9. Écrire un programme qui affiche une chaîne qui contient les mêmes caractères qu’une
//chaîne lue au clavier mais inversés. Ainsi par exemple, "zorglub" deviendra "bulgroz".

#include <stdio.h>
#include <string.h>

int main() {

    char mot[80], motInv[80],rc;
    int i, j;

    printf("Donnez votre mot\n");
    fgets(mot, 80, stdin);

    i = 0;
    j = strlen(mot); //avec scanf c'est j=strlen(mot)-1; mais pas de phrase possible

    while (i < strlen(mot)) {
        motInv[j] = mot[i];
        i++;
        j--;
    }
    printf("%s", motInv);
    return 0;
}
