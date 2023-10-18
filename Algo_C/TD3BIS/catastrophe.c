//2. Écrire un sous-programme qui étant donné un entier n affiche les entiers pairs
//inférieurs à n. Écrire le programme principal (main) qui demande un entier au
//clavier et appelle le sous-programme pour cet entier.

#include <stdio.h>

void affiche_entiers_pairs_inf(int n) {

    while (n>0){
        if (n%2==0){
            n=n-2;
            printf("%d\n",n);
        } else{
            n=n-1;
            printf("%d\n",n);
        }

    }

}

int main() {

    int a;

    printf("Saisissez un entier\n");
    scanf("%d", &a);
    affiche_entiers_pairs_inf(a);


    return 0;
}