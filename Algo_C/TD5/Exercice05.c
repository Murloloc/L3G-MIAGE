//5. Écrire un sous-programme étant donné une chaîne de caractères détermine si elle
//contient ou pas la lettre « z ».

#include <stdio.h>
#include <string.h>

#define N 30

int contientZ(char *m) {

    int i, flag;

    i = 0;
    flag = 0;

    while (i < strlen(m) && flag == 0) {
        if (m[i] == 'z') {
            flag = 1;
        }
        i++;
    }
    return flag;
}

int main() {

    char mot[N];

    printf("Donnez votre mot\n");
    fgets(mot,30,stdin);

    if (contientZ(mot) == 1) {
        printf("Le mot contient le caractere z\n");
    } else {
        printf("Le mot ne contient pas le caractere z");
    }
    return 0;
}

