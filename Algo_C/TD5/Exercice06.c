//6. Écrire un sous-programme étant donné un caractère, rend 1 si c’est un chiffre, 0 sinon

#include <stdio.h>

int estChiffre(char c) {

    if (c >= '0' && c <= '9') {
        return 1;
    } else {
        return 0;
    }
}

int main() {

    char carac;

    printf("Donnez votre caractere :\n");
    scanf("%c", &carac);

    if (estChiffre(carac)==1){
        printf("Le caractere est un chiffre\n");
    }else{
        printf("Le caractere n est pas un chiffre\n");
    }
        return 0;
}