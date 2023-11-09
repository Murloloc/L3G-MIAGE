//Exercice 2 : Répartition du bénéfice d'une société. Sachant que les N actionnaires d'une société
//se partagent le bénéfice qu'elle a réalisé proportionnellement aux nombres d'actions qu'ils
//possèdent, on désire effectuer la répartition annuelle de ceux-ci.
//On rédigera les sous-programmes suivants :
//- remplit_tab : ce sous-programme lit au clavier les noms et les quantités d'actions
//possédées par chaque sociétaire.
//- calcule_nb_total_action : calcul du nombre total d'actions de la société
//- calcule_dividende : calcul des dividendes touchés par chacun des sociétaire sachant
//que : dividende = le bénéfice de la société * nombre d'actions possédées / Nombre
//total d'actions
//- classe_dividende : sous-programme qui ordonne les informations dans l'ordre
//décroissant du montant des dividendes
//- affichage : sous-programme d'affichage de l’ensemble des éléments.
//Vous définirez la structure de données qui vous semble adaptée, et le programme principal qui
//demande à l’utilisateur le bénéfice réalisée cette année par l’entreprise et affiche la liste des
//actionnaires classés

#include <stdio.h>

#define N 2

typedef struct {
    char nom[80];
    int nbAction;
    float dividende;
} ACTIONNAIRE;

void remplit_tab(ACTIONNAIRE *tab, int n) {

    int i;

    i = 1;
    while (i <= n) {
        printf("\nEnregistrement des informations des actionnaires\n");
        printf("\nVeuillez donner le nom de l'actionnaire %d : ", i);
        scanf("%s", tab[i].nom);
        printf("\nDonnez sa quantite d'action :");
        scanf("%d", &tab[i].nbAction);
        i++;
    }
    return;
}

int calcule_nb_total_action(ACTIONNAIRE *tab, int n) {

    int s, i;

    i = 1;
    s = 0;

    while (i <= n) {
        s = s + tab[i].nbAction;
        i++;
    }

    return s;
}

void calcule_dividende(ACTIONNAIRE *tab, int n, float benef) {

    float dividende;
    int i;

    i = 1;

    while (i <= n) {
        dividende = (benef * tab[i].nbAction) / calcule_nb_total_action(tab, n);
        tab[i].dividende = dividende;
        i++;
    }
    return;
}

void classe_dividende(ACTIONNAIRE *tab, int n) {

    int i, flag;
    ACTIONNAIRE ech;

    flag = 1;
    while (flag == 1) {
        flag = 0;
        i = 0;
        while (i < n - 1) {
            if (tab[i].dividende < tab[i + 1].dividende) {
                ech = tab[i];
                tab[i] = tab[i + 1];
                tab[i + 1] = ech;
                flag = 1;
            }
            i = i + 1;
        }
    }
    return;
}

void affichage(ACTIONNAIRE *tab, int n) {

    int i;

    printf("\nVoici le tableau des actionnaires range dans l'ordre decroissant de dividende :\n");
    i = 1;
    while (i <= n) {
        printf("Actionnaire %3d | ", i);
        printf("Nom actionnaire : %10s\t", tab[i].nom);
        printf("Nombre d'action : %3d\t", tab[i].nbAction);
        printf("Dividendes : %5.2f\t", tab[i].dividende);
        printf("\n");
        i++;
    }
    return;
}

int main() {

    ACTIONNAIRE t[N];
    int nombre_total_action;
    float benefice;

    printf("Donnez le benefice total de la societe : ");
    scanf("%f", &benefice);

    remplit_tab(t, N);

    nombre_total_action = calcule_nb_total_action(t, N);
    printf("\nLe nombre total d'action de la societe est : %d\n", nombre_total_action);

    calcule_dividende(t, N, benefice);

//    classe_dividende(t, N);

    affichage(t, N);

    return 0;
}