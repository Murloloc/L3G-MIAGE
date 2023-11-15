//Exercice 4 : Soit un tableau T dont les éléments sont constitués d'un nom, d'un lieu d'habitation
//(le nom de la ville), du sexe (1 ou 2) et de la situation de famille (M, C, V, D). Ce tableau
//comporte 1000 cases et le nombre de personnes sera deamndé à l’utilisateur au clavier dans le
//main. Ecrire les sous-programmes qui :
//- étant donné le nombre nb permet à l'utilisateur de remplir le tableau.
//- étant donné le nom d'une ville rend le nombre d'éléments du tableau habitant dans cette
//ville.
//- étant donné le nom d'une personne renvoie son sexe
//- donne le nombre de personnes mariées qui habitent à Aix.
//Ecrire un programme contenant un menu qui gère les appels aux différents sous programmes.

#include <stdio.h>
#include <string.h>

#define N 1000

typedef struct {
    char nom[80];
    char ville[80];
    int sexe;
    char situation;
} INFOS;

void remplit_tab(INFOS *tab, int n) {

    int i;
    char rc;

    i = 0;
    while (i < n) {
        printf("\nEnregistrement des informations de la personne %d\n", i + 1);
        printf("\nVeuillez donner son nom : ");
        scanf("%s", tab[i].nom);
        printf("\nDonnez son lieu d'habitation : ");
        scanf("%s", tab[i].ville);
        printf("\nQuel est son sexe ? Tapez 1 pour HOMME  2 pour FEMME: ");
        scanf("%d", &tab[i].sexe);
        printf("\nQuelle est sa situation familiale ? Tapez M, C, V ou D : ");
        scanf("%c", &rc);
        scanf("%c", &tab[i].situation);
        i++;
    }
    return;
}

int rend_nombre_habitant_selon_ville(INFOS *tab, int n, char *v,int *cpt) {

    int i,flag;

    i = 0;
    cpt = 0;
    flag = 0;

    while (i < n) {
        if (strcmp(tab[i].ville, v) == 0) {
            cpt++;
            flag = 1;
        }
        i++;
    }
    if (flag == 0) {
        return 0;
    } else {
        *cpt;
        return 1;
    }
}

int rend_sexe_selon_nom(INFOS *tab, int n, char *name,int *genre) {

    int i, flag, sexe;

    i = 0;
    sexe = 0;
    flag = 0;

    while (i < n) {
        if (strcmp(tab[i].nom, name) == 0) {
            sexe = tab[i].sexe;
            flag = 1;
        }
        i++;
    }
    if (flag == 0) {
        return 0;
    } else {
        *genre=sexe;
        return 1;
    }
}

int rend_nombre_maries_aix(INFOS *tab, int n) {

    int i, cpt;

    i = 0;
    cpt = 0;

    while (i < n) {
        if (strcmp(tab[i].ville, "aix") == 0 && (tab[i].situation == 'M' || tab[i].situation == 'm')) {
            cpt++;
        }
        i++;
    }
    return cpt;
}

int main() {

    INFOS t[N];
    int nb, valid_input, choix,res3,drapeau1,drapeau2,compteur1,sexe;
    char ville[80], nom[80];


    printf("Donnez le nombre de personnes : ");
    scanf("%d", &nb);

    while (nb < 1 || nb > 1000) {
        while (getchar() != '\n');
        printf("\nCe nombre de personne n'est pas accepte, re donnez un nombre compris entre 1 et 1000 :");
        scanf("%d", &nb);
    }

    remplit_tab(t, nb);

    printf("\n\nTapez 1 si vous voulez savoir le nombre d'habitant d'une ville \n");
    printf("Tapez 2 si vous voulez connaitre le sexe d'une personne\n");
    printf("Tapez 3 si vous voulez connaitre le nombre de personne maries qui habitent Aix\n");
    printf("Tapez 4 si vous voulez sortir  \n");


    do {

        valid_input = 0;

        while (valid_input == 0) {

            printf("\n\nQue voulez-vous faire : ");

            if (scanf("%d", &choix) != 1 || choix < 1 || choix > 4) {
                // La saisie n'est pas un entier entre 1 et 5
                printf("\nSaisie incorrecte. Veuillez entrer un nombre entier entre 1 et 4.\n");
                // Nettoie le tampon d'entrée
                while (getchar() != '\n');
            } else {
                valid_input = 1;
            }
        }
        if (choix == 1) {
            printf("\nDe quelle ville voulez vous connaitre le nombre d'habitant : ");
            scanf("%s", ville);
            drapeau1 = rend_nombre_habitant_selon_ville(t, nb, ville,&compteur1);
            if (drapeau1==0) {
                printf("\nCette ville n'a pas ete saisie lors de l'enregistrement des donnees");
            } else {
                printf("\nIl y a %d habitant dans %s", compteur1, ville);
            }
        }
        if (choix == 2) {
            printf("\nDonnez le nom de la personne dont vous voulez connaitre le sexe : ");
            scanf("%s", nom);
            drapeau2 = rend_sexe_selon_nom(t, nb, nom,&sexe);
            if (drapeau2 == 0) {
                printf("\nCe nom n'est pas dans les informations fournies");
            } else if (sexe == 1) {
                printf("\n%s est un homme", nom);
            } else {
                printf("\n%s est une femme", nom);
            }
        }
        if (choix == 3) {
            res3 = rend_nombre_maries_aix(t, nb);
            printf("\nIl y a %d personne(s) marie(s) habitant Aix", res3);
        }
    } while (choix != 4);

    printf("\nVous avez decide de sortir, fin du programme");

    return 0;
}


