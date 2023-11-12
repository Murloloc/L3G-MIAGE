//Exercice 1 : On veut traiter un ensemble de clients d’une entreprise de distribution d’eau. Pour
//chaque client, on stockera les informations suivantes :
//- Le numéro du client : un entier
//- Le nombre de personnes habitant le foyer du client : un entier
//- Le numéro du département du client : un entier
//- Le montant de la dernière facture du client : un réel
//L’entreprise a N clients (N défini en constante). Les informations seront stockées dans un
//tableau d’enregistrements.
//On vous demande d’écrire le programme en C qui réalise les opérations suivantes :
//- Enregistrer les informations des clients. La saisie se fera au clavier
//- Afficher les informations stockées dans le tableau
//- Afficher la moyenne des factures
//- Afficher le montant de la facture des clients habitant dans les Bouches-du-Rhône
//- Afficher la moyenne des factures des personnes dont le foyer contient moins de 3
//personnes
//- Afficher la plus petite facture des clients ayant au moins 2 personnes dans leur foyer
//- Enregistrer les informations des clients pour l’année dernière dans un autre tableau,
//calculez les moyennes des factures pour les deux années, et indiquez quelle année a la
//moyenne la plus élevée.

#include <stdio.h>
#include <string.h>

#define N 5

typedef struct {
    int numClient;
    int nbFoyer;
    int numDep;
    float montFact;
} ENREGISTREMENT;

void rempli_enregistrement(ENREGISTREMENT *tab, int n) {

    int i;

    i = 0;
    while (i < n) {
        printf("\nDonnez les informations de l'enregistement %d:\n", i + 1);
        printf("\nNumero du client : ");
        scanf("%d", &tab[i].numClient);
        printf("\nNombre d'habidant dans le foyer : ");
        scanf("%d", &tab[i].nbFoyer);
        printf("\nNumero du departement : ");
        scanf("%d", &tab[i].numDep);
        printf("\nMontant de la derniere facture du client : ");
        scanf("%f", &tab[i].montFact);

        i++;
    }
    return;
}

void affiche_enregistrement(ENREGISTREMENT *tab, int n) {

    int i;

    printf("\nVoici le tableau d'enregistrement :\n");
    i = 0;
    while (i < n) {
        printf("Enregistrement %3d | ", i + 1);
        printf("Numero de client : %6d\t", tab[i].numClient);
        printf("Habitants foyer : %3d\t", tab[i].nbFoyer);
        printf("Departement : %4d\t", tab[i].numDep);
        printf("Facture : %6.2f", tab[i].montFact);
        printf("\n");
        i++;
    }
    return;
}

void affiche_montant_bouches_du_rhone(ENREGISTREMENT *tab, int n) {

    int i;
    i = 0;
    while (i < n) {
        if (tab[i].numDep == 13) {
            printf("\nLe client numero %d habitant des Bouches du Rhone a une facture de %f euros", i + 1,
                   tab[i].montFact);
        }
        i++;
    }
    return;
}

float calcule_moyenne(ENREGISTREMENT *tab, int n) {

    int i;
    float s;

    i = 0;
    s = 0;
    while (i < n) {
        s = s + tab[i].montFact;
        i++;
    }
    return s / n;
}

float calcule_moyenne_foyer_moins_de_3(ENREGISTREMENT *tab, int n) {

    int i, cpt;
    float s;

    i = 0;
    s = 0;
    cpt = 0;
    while (i < N) {
        if (tab[i].nbFoyer < 3) {
            s = s + tab[i].montFact;
            cpt++;
        }
        i++;
    }
    if (cpt == 0) {
        return 0;
    } else {
        return s / cpt;
    }
}


void affiche_min_au_moins_2(ENREGISTREMENT *tab, int n) {

    int i, flag;
    float min;
    i = 0;
    flag = 0;
    while (i < n && flag == 0) {
        if (tab[i].nbFoyer >= 2) {
            min = tab[i].montFact;
            flag=1;
        }
        i++;
    }
    while (i < n) {
        if (tab[i].montFact < min && tab[i].nbFoyer >= 2) {
            min = tab[i].montFact;
        }
        i++;
    }
    if (flag == 0) {
        printf("\nIl n'y a pas de foyer ou il y a au moins 2 personnes\n");
    } else {
        printf("\nLa plus petite facture des clients ayant au moins 2 personnes dans leur foyer est de %.2f\n", min);
    }
    return;
}

int main() {

    ENREGISTREMENT t[N], t2[N];
    float moyenne, moyenneFactureFoyerMoinsDe3;


    rempli_enregistrement(t, N);
    affiche_enregistrement(t, N);
    moyenne = calcule_moyenne(t, N);
    printf("\nLa moyenne des factures est de %.2f\n", moyenne);

    affiche_montant_bouches_du_rhone(t, N);

    moyenneFactureFoyerMoinsDe3 = calcule_moyenne_foyer_moins_de_3(t, N);
    if (moyenneFactureFoyerMoinsDe3==0){
        printf("Il n'y a aucun foyer de moins de 3 personnes");
    } else {
        printf("\nLa moyenne des factures des foyers de moins de 3 personnes est : %.2f\n",
               moyenneFactureFoyerMoinsDe3);
    }

    affiche_min_au_moins_2(t, N);

    printf("\n Veuillez maintenant remplir les informations pour l'annee precedente \n");

    rempli_enregistrement(t2, N);

    if (calcule_moyenne(t, N) > calcule_moyenne(t2, N)) {
        printf("\nLa moyenne la plus elevee est celle de cette annee : %.2f\n", calcule_moyenne(t, N));
    } else if (calcule_moyenne(t, N) < calcule_moyenne(t2, N)) {
        printf("\nLa moyenne la plus elevee est celle de l'annee derniere : %.2f\n", calcule_moyenne(t2, N));
    } else {
        printf("\nLes deux moyennes des deux annes sont egales et valent %.2f\n", calcule_moyenne(t, N));
    }

    return 0;
}