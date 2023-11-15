//SP

#include <stdio.h>

#define MAX 100

void ajout_non_ordonne(int *tab, int *nbv, int e) {

    tab[*nbv] = e;
    *nbv = *nbv + 1;

    return;
}


int main() {

    int t[MAX],nb_val,choix,elt;

    nb_val = 0;

    do {
        printf("1 ajout\n");
        printf("2 suppression\n");
        printf("3 affichage\n");
        printf("0 fin\n");

        printf("Tapez votre choix :");
        scanf("%d",&choix);

        if(choix==1){
            if(nb_val==MAX){
                printf("Désolé, plus de place\n");
            }else{
                printf("Quelle valeur ?\n");
                scanf("%d",&elt);
                ajout_non_ordonne(t,&nb_val,elt);
            }
        }

    } while (choix!=0);

    return 0;
}

