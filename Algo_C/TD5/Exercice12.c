//12. Écrire un sous-programme en C qui vérifie qu’une chaîne de caractères est un nombre
//en binaire

#include <stdio.h>
#include <string.h>

void estBinaire(char *b) {

    int i, flag;

    i = 0;
    flag = 0;
    while (i < strlen(b) && flag != 1) {
        if (b[i] != '0' && b[i] != '1') {
            flag = 1;
        }
        i++;
    }
    if (flag == 1) {
        printf("La chaine de caractere n'est pas un nombre en binaire\n");
    } else {
        printf("La chaine de caractere est un nombre en binaire\n");
    }
    return;
}

int main() {

    char binaire[80];

    printf("Donnez un nombre en binaire \n");
    scanf("%s", binaire);
    estBinaire(binaire);

    return 0;
}
