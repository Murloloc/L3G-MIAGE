//Exercice 6 :
//Gestion de stock d’un magasin de bricolages. On vous demande d’écrire un programme qui
//gère le stock d’un magasin de bricolage. Le stock contient au plus 1000 objets. Chaque objet
//correspond à un modèle d’outil qui est décrit par les informations suivantes :
//• La référence (un entier)
//• Le nom du modèle (par exemple, Clé à molette)
//• Le prix hors taxe à l’unité
//• Le nombre d’outils de ce modèle présentes dans le stock.
//Les sous-programmes suivants seront proposés au choix au manager du magasin et utilisables
//dans l’ordre que le manager souhaite, autant de fois qu’il le souhaite :
//- Ajouter un modèle dans le stock
//- Ajouter des unités d’un modèle d’outils déjà présent dans le stock
//- Calculer le coût moyen des outils présents dans le stock
//- Effectuer une commande d’un client en 3 étapes : remplir le panier, trier le panier,
//afficher le panier.
//Ce sous-programme devra demander au client quel produit (nom du modèle) il veut acheter, en
//quelle quantité, et cela tant que le client veut continuer à ajouter des produits dans son panier.
//Si le client ajoute un produit déjà présent dans son panier, c’est la quantité présente dans le
//panier qui est modifiée. Pour chaque produit acheté, le programme vérifiera que le modèle et le
//nombre d’unités demandé sont bien présents dans le stock.
//Lorsque le client a fini de remplir son panier, le programme lui demande de le valider et s’il le
//valide, le stock est diminué de tout ce qui se trouve dans le panier. Si le nombre d’unités d’un
//modèle tombe à 0 dans le stock, le modèle est supprimé du stock.
//Ensuite, le panier est trié dans l’ordre croissant des prix et affiché ainsi que le montant total
//TTC de la commande.
//Attention : une attention particulière doit être portée aux cas particuliers. N’hésitez pas à définir
//des sous-programmes supplémentaires si besoin pour rendre le code plus clair, par exemple un
//sous-programme de suppression.
//Vous ferez les déclarations nécessaires et écrirez le programme principal qui contiendra le menu
//permettant d’utiliser chacune des fonctionnalités à volonté, la saisie des informations au clavier
//chaque fois que nécessaire, l’appel aux sous-programmes qui effectueront les fonctionnalités et
//l’affichage des résultats si nécessaire.

//Pas commencer


#include <stdio.h>
#include <string.h>
#define MAX 5

typedef char STRING[80];

void ajout_non_ordonne(int *tab, int *nbv, int e){

    tab[*nbv]=e;
    *nbv=*nbv+1;
    return;
}

int suppression_non_ordonne(int *tab, int *nbv, int e) {

    int i, flag;

    i = 0;
    flag = 0;

    while (i < *nbv && flag == 0) {
        if (tab[i] == e) {
            flag = 1;
        } else {
            i++;
        }
    }

    if (flag) {
        tab[i] = tab[*nbv - 1];
        *nbv = *nbv - 1;
    }
    return flag;
}

int plein(int nbv, int max){
    return nbv==max;
}

int vide(int nbv){
    return nbv==0;
}

void affiche(int *tab, int nbv){

    int i;
    i=0;

    while (i<nbv){
        printf("%d\n",tab[i]);
        i++;
    }
}

int main(){

    int choix,nbval,val,t[MAX];

    nbval=0;

    do {
        printf("\n1 : ajout\n");
        printf("2 : suppression\n");
        printf("3 : affichage\n");
        printf("4 : FIN\n");
        printf("\nQuel est votre choix ? : ");
        scanf("%d", &choix);
        while (choix<1 || choix >4){
            printf("\nSaisie incorecte reassayez : ");
            scanf("%d",&choix);
        }
        printf("\n");

        if (choix == 1) {
            if (plein(nbval, MAX)) {
                printf("Le tableau est plein\n");
            } else {
                printf("\nQuelle valeur voulez vous ajouter ? : ");
                scanf("%d", &val);
                ajout_non_ordonne(t, &nbval, val);
            }
        }
        if (choix == 2) {
            if (vide(nbval)) {
                printf("Le tableau est vide\n");
            } else {
                printf("Quelle valeur voulez vous supprimer ? : ");
                scanf("%d", &val);
                if (suppression_non_ordonne(t, &nbval, val)) {
                    printf("\n%d a ete supprime\n",val);
                } else {
                    printf("\n%d n est pas dans le tableau\n",val);
                }
            }
        }
        if(choix==3){
            if(vide(nbval)){
                printf("\nLe tableau est vide\n");
            } else{
                affiche(t,nbval);
            }
        }
    } while (choix!=4);

    printf("FIN du programme");

    return 0;
}