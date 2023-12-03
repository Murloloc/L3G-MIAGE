//Exercice 4 : Une imprimante en réseau reçoit des travaux d’un ensemble d’ordinateurs et elle
//doit donc gérer un ordre de passage pour les demandes qu’elle reçoit. On va supposer que
//l’ordre choisi par l’imprimante est le suivant :
//- Les travaux courts (moins de 10 pages) passent toujours devant les autres (les
//« longs »), et ils passent en fonction de leur taille (les plus courts passent en
//premier). Deux travaux de même taille passent en fonction de leur ordre d’arrivée.
//- Les travaux longs sont traités en fonction de leur ordre d’arrivée.
//On vous demande d’écrire un programme qui gère l’arrivée des demandes d’impression et
//présente le document suivant à l’imprimante quand celle-ci est libre. Chaque document est
//identifié par le nom du fichier qui le contient (une chaîne de caractères).
//1°) Décrivez précisément en français comment vous envisagez d’organiser les informations
//nécessaires à ce programme et quelles sont les opérations que vous prévoyez et comment elles
//se déroulent sur cette organisation des données.
//2°) Décrivez les structures informatiques que vous allez utiliser et montrer comment marchent
//sur ces structures les opérations que vous avez citées précédemment. N’hésitez pas à faire des
//dessins. Si vous utilisez des structures de données abstraites connues, citez-les.
//3°) Ecrivez le programme complet comportant deux choix principaux : « un nouveau
//document arrive » et « l’imprimante est libre ».

#include<stdio.h>
#include<string.h>

#define MAX 10

typedef char STRING[80];

typedef struct {
    STRING nom_fichier;
    int nb_page;
} TRAVAUX;

int plein(int nbv, int max) {
    return nbv == max;
}

int vide(int nbv) {
    return nbv == 0;
}

void ajout_file(TRAVAUX *tab, int *nbv, TRAVAUX e) {

    tab[*nbv] = e;
    *nbv = *nbv + 1;
    return;
}

void ajout_ordonne_croissant(TRAVAUX *tab, int *nbv, TRAVAUX e) {

    int i, flag, num_ajout;

    i = 0;
    flag = 0;

    while (i < *nbv && flag == 0) {
        if (tab[i].nb_page > e.nb_page) {
            flag = 1;
        } else {
            i++;
        }
    }
    num_ajout = i;
    i = *nbv;

    while (i > num_ajout) {
        tab[i] = tab[i - 1];
        i--;
    }
    tab[num_ajout] = e;
    *nbv = *nbv + 1;

    return;
}

void supp_file(TRAVAUX *tab, int *nbv, TRAVAUX *val_supp) {

    int i;

    *val_supp = tab[0];
    i = 0;
    while (i < *nbv - 1) {
        tab[i] = tab[i + 1];
        i = i + 1;
    }
    *nbv = *nbv - 1;
    return;
}

void affiche_tab(TRAVAUX *tab, int nbv) {

    int i;
    i = 0;

    while (i < nbv) {
        printf("\nNom : %10s ", tab[i].nom_fichier);
        printf(" Nombre page : %3d", tab[i].nb_page);
        i++;
    }
    return;
}

int main() {

    TRAVAUX tcourt[MAX], tlong[MAX], t[2];

    int nb_page, valid_input, choix, i, prio, nonprio, valeur_supp;

    prio = 0;
    nonprio = 0;

    do {
        printf("\n");
        printf("1: un nouveau document arrive \n");
        printf("2: l'impression est libre\n");
        printf("3: voir la file d'attente \n");
        printf("4: FIN \n");

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
            if (plein(prio + nonprio, MAX)) {
                printf("Il n'y a plus de place dans la file d'attente\n ");
            } else {
                printf("\nTapez le nom : ");
                scanf("%s", t[0].nom_fichier);
                printf("\nCombien de page : ");
                scanf("%d", &t[0].nb_page);
                if (t[0].nb_page < 10) {
                    ajout_ordonne_croissant(tcourt, &prio, t[0]);
                } else {
                    ajout_file(tlong, &nonprio, t[0]);
                }
            }
        }
        if (choix == 2) {
            if (vide(prio + nonprio)) {
                printf("\nLa file est vide\n");
            } else if (prio != 0) {
                supp_file(tcourt, &prio, &t[1]);
                printf("\n%s a ete imprime", t[1].nom_fichier);
            } else {
                supp_file(tlong, &nonprio, &t[1]);
                printf("\n%s a ete imprime", t[1].nom_fichier);
            }
        }
        if (choix == 3) {
            if (vide(prio + nonprio)) {
                printf("\nLa file est vide");
            } else {
                printf("\nVoici la file d'attente des prioritaires\n");
                affiche_tab(tcourt, prio);
                printf("\nVoici la file d'attente des non prioritaires\n");
                affiche_tab(tlong, nonprio);
            }
        }

    } while (choix != 4);

    if (vide(prio + nonprio)) {
        printf("\nla file est vide");
    } else {
        i = 0;
        while (i < prio + 1) {
            supp_file(tcourt, &prio, &t[1]);
            printf("\n%s est sortie\n", t[1].nom_fichier);
            i++;
        }
        i = 0;
        while (i < nonprio + 1) {
            supp_file(tlong, &nonprio, &t[1]);
            printf("\n%s est sortie\n", t[1].nom_fichier);
            i++;
        }
    }
    return 0;

}

