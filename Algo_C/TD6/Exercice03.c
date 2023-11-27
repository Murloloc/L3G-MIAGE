//Exercice 3 : On veut écrire un programme qui permette de stocker et de consulter les notes en
//informatique des étudiants de L3 Gestion. Le programme devra pouvoir :
//- afficher la note d'un étudiant en fonction de son nom.
//- afficher l’étudiant ayant eu la plus mauvaise note
//- afficher la moyenne des notes
//- afficher tous les étudiants ayant obtenu une note inférieure à 5
//Les opérations seront réalisées dans des sous-programmes, le programme principal appellera
//les sous-programmes et affichera les résultats.
//Vous programmerez le main sous la forme d’un système de menu qui permet à l’utilisateur de
//choisir n’importe quelle opération dans n’importe quel ordre et autant de fois qu’il le souhaite.

//NB : On rappelle que sauf exception, les données sont lues dans le main et les résultats sont
//affichés dans le main. L’exception concerne essentiellement le sous-programme de remplissage
//de tableau (qui contient des scanf) et le sous-programme d’affichage d’un tableau (qui contient
//des printf).

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 1

typedef struct {
    char nom[80];
    float note;
} NOTEINFO;

void remplit_tab(NOTEINFO *tab, int n) {

    int i;

    i = 0;
    while (i < n) {
        printf("\nEnregistrement des informations des eleves\n");
        printf("\nVeuillez donner le nom de l'eleve %d : ", i + 1);
        scanf("%s", tab[i].nom);
        printf("\nDonnez sa note en informatique :");
        scanf("%f", &tab[i].note);
        i++;
    }
    return;
}

int rend_note_en_fonction_du_nom(NOTEINFO *tab, int n, char m[80], float *mark) {

    float note;
    int i, flag;

    i = 0;
    flag = 0;

    while (i < n && flag == 0) {
        if (strcmp(m, tab[i].nom) == 0) {
            note = tab[i].note;
            flag = 1;
        }
        i++;
    }
    if (flag == 0) {
        return 0;
    } else {
        *mark = note;
        return 1;
    }
}

char *rend_etu_ayant_note_min(NOTEINFO *tab, int n) {

    int i;
    float min;
    char *nomMin;

    min = tab[0].note;
    nomMin = strdup(tab[0].nom);
    i = 1;
    while (i < n) {
        if (tab[i].note < min) {
            min = tab[i].note;
            free(nomMin);
            nomMin = strdup(tab[i].nom);
        }
        i++;
    }
    return nomMin;
}

float calcule_moyenne(NOTEINFO *tab, int n) {

    int i;
    float s;

    i = 0;
    s = 0;
    while (i < n) {
        s = s + tab[i].note;
        i++;
    }
    return s / n;
}

char *noms_note_inferieure_5(NOTEINFO *tab, int n) {

    int i;
    char *noms;

    noms = malloc(80 * n);
    noms[0] = '\0';
    i = 0;

    while (i < n) {
        if (tab[i].note < 5.0) {
            strcat(noms, tab[i].nom);
            strcat(noms, " ");
        }
        i++;
    }
    return noms;
}

int main() {

    NOTEINFO t[N];
    int choix, valid_input, drapeau;
    float note, moyenne;
    char nom[80], nomsInf5[80];


    remplit_tab(t, N);

    printf("\nTapez 1 si vous voulez consulter consulter la note d'un etudiant en fonction de son nom\n");
    printf("Tapez 2 si vous voulez afficher l'etudiant ayant eu la plus mauvaise note\n");
    printf("Tapez 3 si vous voulez afficher la moyenne des notes\n");
    printf("Tapez 4 si vous voulez afficher tous les etudiants ayant eu une note inferieure a 5\n");
    printf("Tapez 5 si vous voulez sortir\n");


    do {

        valid_input = 0;

        while (valid_input == 0) {

            printf("\n\nQue voulez-vous faire : ");

            if (scanf("%d", &choix) != 1 || choix < 1 || choix > 5) {
                // La saisie n'est pas un entier entre 1 et 5
                printf("\nSaisie incorrecte. Veuillez entrer un nombre entier entre 1 et 5.\n");
                // Nettoie le tampon d'entrée
                while (getchar() != '\n');
            } else {
                valid_input = 1;
            }
        }

        if (choix == 1) {
            printf("\nDonnez le nom de l'etudiant dont vous voulez connaitre la note :");
            scanf("%s", nom);
            drapeau = rend_note_en_fonction_du_nom(t, N, nom, &note);
            if (drapeau == 0) {
                printf("\nLe nom saisi n'existe pas");
            } else {
                printf("\nSa note est %.2f", note);
            }
        }
        if (choix == 2) {
            printf("\nL'etudiant ayant eu la plus mauvaise note est %s", rend_etu_ayant_note_min(t, N));
        }

        if (choix == 3) {
            moyenne = calcule_moyenne(t, N);
            printf("\nLa moyenne de la classe est : %.2f", moyenne);
        }
        if (choix == 4) {
            strcpy(nomsInf5, noms_note_inferieure_5(t, N));
            printf("\nVoici le ou les etudiants ayant une note inferieure a 5: %s", nomsInf5);
            free(nomsInf5);
        }
    } while (choix != 5);

    printf("\nVous avez decide de sortir, fin du programme");

    return 0;
}


