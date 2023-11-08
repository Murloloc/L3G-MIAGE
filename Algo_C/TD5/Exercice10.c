//10. En partant de l'exercice précédent, écrire un programme qui détermine si une chaîne de
//caractères donnée est un palindrome (c'est-à-dire une chaîne qui peut se lire
//indifféremment dans les deux sens), comme par exemple "radar" ou "s.o.s".

#include <stdio.h>
#include <string.h>

int main() {

    char mot[80];
    int i, j, flag;

    printf("Donnez votre mot\n");
    fgets(mot, 80, stdin);
//  scanf("%s",mot);

    i = 0;
    j = strlen(mot)-2; //avec scanf c'est j=strlen(mot)-1; mais pas de phrase possible
    flag = 0;
    while (i < j && flag!=1) {
        if (mot[i] != mot[j]) {
            flag = 1;
        }
        i++;
        j--;
    }
    if (flag == 1) {
        printf(" n'est pas un palindrome\n");
    } else {
        printf("est un palindrome\n");
    }
    return 0;
}