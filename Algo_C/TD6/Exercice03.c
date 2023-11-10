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

#define N 2

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

float rend_note_en_fonction_du_nom(NOTEINFO *tab, int n, char m[80]) {

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
        return -1;
    } else {
        return note;
    }
}

char rend_etu_ayant_note_min(NOTEINFO *tab, int n) {

    int i, flag;
    char nomMin[80];




    return nomMin[80];
}

int main() {

    NOTEINFO t[N];
    int choix;
    float note;
    char nom[80];

    remplit_tab(t, N);

    printf("\nTapez 1 si vous voulez consulter consulter la note d'un etudiant en fonction de son nom\n");
    printf("Tapez 2 si vous voulez afficher l'etudiant ayant eu la plus mauvaise note\n");
    printf("Tapez 3 si vous voulez afficher la moyenne des notes\n");
    printf("Tapez 4 si vous voulez afficher tous les etudiants ayant eu une note inferieure a 5\n");
    printf("Tapez 5 si vous voulez sortir\n");

    printf("\n Que voulez vous faire : ");
    scanf("%d", &choix);

    while (choix < 1 || choix > 5) {
        printf("\nVotre choix n'est pas valide re donnez votre choix :");
        scanf("%d", &choix);
    }

    while (choix != 5) {

        if (choix == 1) {
            printf("\nDonnez le nom de l'etudiant dont vous voulez connaitre la note :");
            scanf("%s", nom);
            note = rend_note_en_fonction_du_nom(t, N, nom);
            if (note == -1) {
                printf("Le nom saisi n'existe pas");
            } else {
                printf("\n Sa note est %.2f", note);
            }
        }
//        if (choix == 2) {
//
//        }
//        if (choix == 3) {
//
//        }
//        if (choix == 4){
//
//        }
        printf("\nQue voulez vous faire maintenant : ");
        scanf("%d", &choix);
    }


    return 0;
}