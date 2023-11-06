//4. Écrire un programme qui étant donné un mot lu au clavier affiche le même mot avec
//une lettre sur deux en majuscule. On utilisera l’opération de cast qui permet de changer
//le type d’une information : (char)(65) vaut ‘A’, (int)(‘A’) vaut 65 car 65 est le code
//ASCII de ‘A’.

#include <stdio.h>
#include <string.h>

int main(){

    char mot[30];

    printf("Donnez votre mot\n");
    fgets(mot,30,stdin);



    return 0;
}