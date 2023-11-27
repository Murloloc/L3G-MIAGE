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


#include <stdio.h>
#define N 5

#include <stdio.h>
#include <string.h>
#define MAX 5

typedef char STRING[80];

int plein(int nbv, int max)
{
    int i, flag;
    flag = 0;
    i = 0;
    if (nbv == max)
    {
        flag = 1;
    }
    else
    {
        flag = 0;
    }
    return flag;
}

int vide (int nbv)
{
    int flag;
    flag = 0;
    if (nbv == 0)
    {
        flag = 1;
    }
    else
    {
        flag = 0;
    }
    return flag;
}

void ajout_file (STRING *tab, int *nbv, STRING e)
{
    strcpy(tab[*nbv],e);
    *nbv = *nbv +1;
    return;
}

void supp_file (STRING *tab, int *nbv, STRING *val_supp)
{
    int i;
    strcpy(*val_supp, tab[0]);
    i =0;
    while (i< *nbv-1)
    {
        strcpy(tab[i],tab[i+1]);
        i = i+1;
    }
    *nbv = *nbv-1;
    return;
}

void affiche_tab (STRING *tab, int nbv)
{
    int i;
    i = 0;

    while (i< nbv)
    {
        printf("nom: %s", tab[i]);
        i = i+1;
    }
    return;
}


int main ()
{
    STRING t[MAX], nom, valeur_supp;
    int nbval, valid_input, choix;

    nbval = 0;

    do {

        printf("1: un nouveau patient arrive\n");
        printf("2: le doctuer est libre\n");
        printf("3: voir la file d'attente \n");
        printf("0: FIN \n");

        while (valid_input == 0)
        {

            printf("\n\nQue voulez-vous faire : ");

            if (scanf("%d", &choix) != 1 || choix < 1 || choix > 4)
            {
                // La saisie n'est pas un entier entre 1 et 5
                printf("\nSaisie incorrecte. Veuillez entrer un nombre entier entre 1 et 4.\n");
                // Nettoie le tampon d'entrée
                while (getchar() != '\n');
            }
            else
            {
                valid_input = 1;
            }
        }

        if(choix == 1)
        {
            if(plein(nbval, MAX))
            {
                printf("Il n'y a plus de place dans la file d'attente\n ");
            }
            else
            {
                printf("Tapez votre nom\n");
                scanf("%s", nom);
                ajout_file (t, &nbval, nom);
            }
        }

        if (choix == 2)
        {
            if (vide( nbval))
            {
                printf("La file est vide\n");
            }
            else
            {
                supp_file (t, &nbval, &valeur_supp);
                printf("%s vous pouvez venir", valeur_supp);
            }
        }

        if (choix == 3)
        {
            affiche_tab(t, nbval);
        }

    }while (choix != 0);
    return 0;
}
