//Exercice 5 : GESTION D’UNE BIBLIOTHEQUE
// Une bibliothèque vous demande de créer un logiciel de gestion de ses abonnés, de ses livres et
//des emprunts.
//Chaque abonné est décrit par son nom, son code (un entier), sa date d’abonnement (par exemple
//Décembre 2007) et le nombre de livres que l’abonné a actuellement empruntés. Un abonné ne
//peut pas emprunter plus de 3 livres à la fois et son abonnement a une durée de 1 an.

//Chaque livre est décrit par son titre, son auteur, son code et un champ contenant le code de la
//personne qui l’a emprunté. Ce champ vaudra -1 si le livre n’est pas emprunté et permettra donc
//de savoir si le livre est disponible ou pas à un moment donné.
//Chaque retour de livre est décrit par le code du livre rendu.

//Ce logiciel comporte un menu principal qui permet d'accéder aux 4 fonctions suivantes :

//Un menu « gestion des abonnés » permettant
//- l'ajout d'un abonné
//- l'affichage dans l'ordre alphabétique des abonnés
//- l’affichage des abonnés dont l’abonnement a expiré.

//Un menu « gestion des livres » qui permet l’ajout d’un livre.

//Une fonctionnalité « emprunt ». Elle permettra à un abonné (dont on connaît le code)
//d’emprunter un livre (dont on connaît le code). Pour cela, vous devez vérifier :
//- Que le livre est disponible
//- Que l’abonné peut encore emprunter des livres (abonnement à jour et nombre de
//livres empruntés inférieur à 3)
//Si ces conditions sont remplies, les informations concernant le livre et l’abonné sont mises à
//jour.

//Une fonction « retour d’un livre ». Cette fonction permettra de mettre à jour les informations
//concernant le livre qui est revenu et l’abonné qui l’avait emprunté.

//Remarques :
//Pour les dates, je vous conseille un codage sous forme d’entier (par exemple, 07 12 2018 sera
//codé 20181207, 15 06 2019 sera codé 20190615). Ce codage permet de comparer les dates
//simplement. Si le passage d’une date à son codage vous pose des problèmes, vous pouvez
//supposer que l’utilisateur entre directement le codage de la date à la place de la date.
//Si vous en avez besoin, la date du jour sera demandée à l’utilisateur du programme.

//Vérifiez bien tous les cas particuliers (par exemple, si pour un emprunt, le code de l’abonné
//n’existe pas).
//On supposera qu’il y a au maximum 100 abonnés et 500 livres. On suppose qu’au démarrage
//du logiciel, il n’y a aucun abonné et aucun livre. Un ensemble de données initiales (base
//d’adhérents, base de livres) sera lu dans des fichiers.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXABO 100
#define MAXLIVRE 500

typedef char STRING[80];

typedef struct {
    STRING nom;
    int code_abo;
    long date;
    int nb_livre;
} ABONNE;

typedef struct {
    STRING titre;
    STRING auteur;
    int code_livre;
    int code_abo;
} LIVRE;

void remplit_tab_abo(ABONNE *tab, int *nbv) {

    int i;

    i=*nbv;
    *nbv = *nbv + 1;

    printf("\nEnregistrement des informations de l'abonne %d\n", *nbv);
    printf("\nVeuillez donner son nom : ");
    scanf("%s", tab[i].nom);
    printf("\nDonnez son code d'abonne : ");
    scanf("%d", &tab[i].code_abo);
    printf("\nDonnez sa date d'abonnement dans le format aaaammjj : ");
    scanf("%d", &tab[i].date);
    printf("\nCombien de livre actuellement emprunte ? (max 3) : ");
    scanf("%d", &tab[i].nb_livre);
    while (tab[i].nb_livre <0 || tab[i].nb_livre>3){
        printf("Saisie incorrecte le nombre doit etre compris entre 0 et 3");
        scanf("%d", &tab[i].nb_livre);
    }

    return;
}

void affichage_abo(ABONNE *tab, int nbv) {

    int i;

    printf("\nVoici le tableau des abonnes dans l'odre alphabetique : \n");
    i = 0;
    while (i < nbv) {
        printf("Nom : %10s\t", tab[i].nom);
        printf("Code : %7d\t", tab[i].code_abo);
        printf("Date : %10ld\t", tab[i].date);
        printf("Emprunt actuel : %d", tab[i].nb_livre);
        printf("\n");
        i++;
    }
    return;
}

void affichage_abo_expire(ABONNE *tab, int nbv, double date) {

    int i;

    printf("\nVoici les abonnes dont l'abonnement a expire : \n");
    i = 0;
    while (i < nbv) {
        if (tab[i].date < date) {
            printf("Nom : %10s\t", tab[i].nom);
            printf("Code : %7d\t", tab[i].code_abo);
            printf("Date : %10ld\t", tab[i].date);
            printf("Emprunt actuel : %d", tab[i].nb_livre);
            printf("\n");
        }
        i++;
    }
    return;
}

void tri_ordre_alpha(ABONNE *tab, int nbv) {

    int i, flag;
   ABONNE ech;

    flag = 1;
    while (flag == 1) {
        flag = 0;
        i = 0;
        while (i < nbv- 1) {
            if (strcmp(tab[i].nom,tab[i+1].nom)>0) {
                ech = tab[i];
                tab[i] = tab[i + 1];
                tab[i + 1] = ech;
                flag = 1;
            }
            i++;
        }
    }
    return;
}

int plein(int nbv, int max) {
    return nbv == max;
}

int vide(int nbv) {
    return nbv == 0;
}




int main() {

    ABONNE t1[MAXABO];
    LIVRE t2[MAXLIVRE];

    int choix, valid_input, nb_abo, nb_livre;
    long date_du_jour,date_expi;


    nb_abo = 0;
    nb_livre = 0;

    printf("Quelle est la date du jour ? (format aaaammjj)\n");
    scanf("%ld",&date_du_jour);
    date_expi = date_du_jour - 10000;


    do {
        printf("\n");
        printf("1 : Menu gestion des abonnes\n");
        printf("2 : Menu gestion des livres\n");
        printf("3 : Menu gestion des emprunts\n");
        printf("4 : Menu retour d'emprunt\n");
        printf("5 : Sortie du programme\n");

        valid_input = 0;

        while (valid_input == 0) {

            printf("\nQue voulez-vous faire : ");

            if (scanf("%d", &choix) != 1 || choix < 1 || choix > 5) {
                // La saisie n'est pas un entier entre 0 et 5
                printf("\nSaisie incorrecte. Veuillez entrer un nombre entier entre 0 et 4.\n");
                // Nettoie le tampon d'entrée
                while (getchar() != '\n');
            } else {
                valid_input = 1;
            }
        }

        if (choix == 1) {
            do {
                printf("\n");
                printf("1 : Ajouter un abonne\n");
                printf("2 : Afficher les abonnes dans l'odre alphabetique\n");
                printf("3 : Afficher les abonnes dont l'abonnement a expire\n");
                printf("0 : Sortir du menu gestion des abonnes\n");

                valid_input = 0;

                while (valid_input == 0) {

                    printf("\nQue voulez-vous faire : ");

                    if (scanf("%d", &choix) != 1 || choix < 0 || choix > 3) {
                        // La saisie n'est pas un entier entre 0 et 3
                        printf("\nSaisie incorrecte. Veuillez entrer un nombre entier entre 0 et 3.\n");
                        // Nettoie le tampon d'entrée
                        while (getchar() != '\n');
                    } else {
                        valid_input = 1;
                    }
                }
                if (choix == 1) {
                    if (plein(nb_abo, MAXABO)) {
                        printf("\nNombre maximum d'abonne atteint veuillez en supprimer avant d'en rajouter de nouveau\n");
                    } else {
                        remplit_tab_abo(t1, &nb_abo);
                    }
                }
                if (choix == 2){
                    if (vide(nb_abo)) {
                        printf("\nIl n'y a aucun abonne\n");
                    } else {
                        tri_ordre_alpha(t1, nb_abo);
                        affichage_abo(t1, nb_abo);
                    }
                }
                if (choix==3){
                    affichage_abo_expire(t1,nb_abo,date_expi);
                }

            } while (choix!=0);

        }
        if (choix == 2) {
            do {
                printf("\n");
                printf("1 : Ajouter un livre\n");
                printf("0 : Sortir du menu gestion des livres\n");

                valid_input = 0;

                while (valid_input == 0) {

                    printf("\nQue voulez-vous faire : ");

                    if (scanf("%d", &choix) != 1 || choix < 0 || choix > 1) {
                        // La saisie n'est pas un entier entre 0 et 1
                        printf("\nSaisie incorrecte. Veuillez entrer un nombre entier entre 0 et 1.\n");
                        // Nettoie le tampon d'entrée
                        while (getchar() != '\n');
                    } else {
                        valid_input = 1;
                    }
                }
                if (choix == 1){

                }
            } while (choix!=0);
        }
        if (choix == 3) {

        }
        if (choix == 4 ){

        }
    } while (choix != 5);


    return 0;
}