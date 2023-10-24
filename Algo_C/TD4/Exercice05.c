//5. Écrire un sous-programme qui étant donné un entier n et un caractère c affiche
//une ligne formée de n fois le caractère c. Utiliser ce sous-programme pour dessiner
//la même forme que ci-dessus, mais qui demande à l’utilisateur le nombre de lignes
//souhaitées et le caractère à afficher et appelle le sous-programme

#include <stdio.h>

void affiche_nfoisc(int n,char c) {

    int i;
    i=0;
    while (i<n){
        printf("%c",c);
        i++;
    }
    return;
}

int main() {

    int i,nb_ligne;
    char carac,rc;

    printf("Combien de lignes voulez vous ?\n");
    scanf("%d",&nb_ligne);
    printf("Donnez le caractere que vous souhaitez dessiner\n");
    scanf("%c",&rc);
    scanf("%c",&carac);

    i=1;

    while (i <= nb_ligne) {
        affiche_nfoisc(i, carac);
        i++;
        printf("\n");
    }
    return 0;
}