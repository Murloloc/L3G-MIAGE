//11. Écrire un sous-programme en C qui remplit un tableau de n réels lus au clavier.
//Écrire un sous-programme qui étant donné un tableau de n réels calcule la
//moyenne des éléments du tableau. Utilisez ces sous-programmes dans un
//programme principal qui travaille sur les notes de 25 étudiants.

#include <stdio.h>
#define N 25

void rempli_tableau(int n){

    int i,t[i];

    i=0;
    while (i<N){
        printf("Donnez la valeur %d du tableau :\n",i+1);
        t[i]=n;
        i++;
    }
    return;
}

int main(){

    int t[N];




    return 0;
}