//7. Écrire un sous-programme étant donné un caractère, rend 1 si c’est une majuscule, 0
//sinon.

#include <stdio.h>

int estMajuscule(char c) {

    if (c >= 'A' && c <= 'Z') {
        return 1;
    } else {
        return 0;
    }
}

int main() {

    char carac;

    printf("Donnez votre caractere :\n");
    scanf("%c", &carac);

    if (estMajuscule(carac)==1){
        printf("Le caractere est une majuscule\n");
    }else{
        printf("Le caractere n est pas une majuscule\n");
    }
    return 0;
}