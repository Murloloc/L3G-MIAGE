//Exercice 2 : On propose d’écrire un programme qui effectue un certain nombre de
//traitements sur 5 notes obtenues par les étudiants d’une classe. Le nombre d’étudiants de
//la promotion sera demandé en début de programme à l’utilisateur, avec un maximum de
//50 étudiants. Chaque étudiant est décrit par :
//- son numéro d’étudiant
//- ses 5 notes
//Les informations de chaque étudiant seront stockées dans un enregistrement à 2 champs,
//l’un nommé « num_etu » de type entier long, l’autre nommé « tab_note_etu » de type
//tableau de 5 réels. La classe sera donc stockée dans un tableau d’enregistrements.
//Votre programme devra :
//- enregistrer les informations de chaque étudiant
//- afficher l’ensemble des informations de la classe
//- afficher le numéro et la moyenne des notes de tous les étudiants
//- afficher le numéro de l’étudiant ayant obtenu la meilleure note en Math (on
//considèrera que la note en Math est la première note de chaque étudiant)
//- afficher la moyenne de la classe en Informatique (on considèrera que la note
//en Informatique est la troisième note de chaque étudiant)

#include <stdio.h>

#define N 5
#define NE 50

int main() {

    int i, j, nbE, flag;
    struct {
        long num_etu;
        float tab_notes_etu[N];
    } t[NE];
    float moyenne, somme, max;

    //Demande du nombre d etudiant
    printf("Donnez le nombre d'eleves de la classe (compris entre 1 et 50)\n");
    scanf("%d", &nbE);

    while (nbE < 1 || nbE > 50) {
        printf("Ce nombre d'eleves n'est pas accepte, re donnez un nombre compris entre 1 et 50\n");
        scanf("%d", &nbE);
    }

    //Remplissage des informations de chaque etudiant avec num etu et leurs 5 notes
    i = 0;
    while (i < nbE) {
        printf("Donnez le NUMERO ETUDIANT de l'etudiant %d\n", i + 1);
        scanf("%ld", &t[i].num_etu);
        j = 0;
        while (j < N) {
            printf("tapez la NOTE numero %d de l'etudiant %i\n", j + 1, i + 1);
            scanf("%f", &t[i].tab_notes_etu[j]);
            j = j + 1;
        }
        i = i + 1;
    }

    //Affichage de toutes les infos (j'ai fait le max pour ce que soit beau)

    printf("Voici les informations que vous avez donne\n");
    i = 0;
    while (i < nbE) {
        printf("NUM_ETU : %10ld", t[i].num_etu);
        j = 0;
        printf("\tNOTES:");
        while (j < N) {
            printf("%4d) %5.2f", j + 1, t[i].tab_notes_etu[j]);
            j = j + 1;
        }
        i = i + 1;
        printf("\n");
    }

    //calcul moyenne
    printf("\nVoici le numero et la moyenne des notes de tous les etudiants\n");
    i = 0;
    while (i < nbE) {
        somme = 0;
        j = 0;
        while (j < N) {
            somme = somme + t[i].tab_notes_etu[j];
            j = j + 1;
        }
        moyenne = somme / N;
        printf("NUM_ETU : %10ld", t[i].num_etu);
        printf("\tMoyenne : %5.2f\n", moyenne);
        i = i + 1;
    }

    //Meilleure note en math

    /*
     * D'abord recherche de la note maximale puis ensuite pour chaque etudiant ayant eu la note maximale on affiche
     * son numero etudiant
     * J'ai utilisé un flag afin de changer le message qui s'affiche après avoir afficher le premier etudiant dans le
     * cas ou plusieurs étudiants ont la meilleure note
     */

    i = 0;
    max = t[i].tab_notes_etu[0];
    while (i < nbE) {
        if (t[i].tab_notes_etu[0] > max) {
            max = t[i].tab_notes_etu[0];
        }
        i = i + 1;
    }
    i = 0;
    flag = 0;
    while (i < nbE) {
        if (t[i].tab_notes_etu[0] == max && flag == 0) {
            printf("\nL'etudiant %ld a la meilleure note en math avec une valeur de %.2f\n", t[i].num_etu, max);
            flag = 1;
        } else if (t[i].tab_notes_etu[0] == max && flag == 1) {
            printf("L'etudiant %ld a aussi eu la meilleure note\n", t[i].num_etu);
        }
        i=i+1;
    }
    i = 0;
    somme = 0;
    while (i < nbE) {
        somme = somme + t[i].tab_notes_etu[2];
        i = i + 1;
    }
    moyenne = somme / nbE;

    printf("\n La moyenne de la classe en informatique est de %.2f", moyenne);

    return 0;
}