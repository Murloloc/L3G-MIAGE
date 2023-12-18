//Exercice 6 : Gestion d'un péage autoroutier. Le programme que vous devez écrire doit gérer
//un péage autoroutier comportant N guichets. Le seul but est de gérer au mieux le péage en
//indiquant à chaque voiture qui arrive à quel guichet elle doit se mettre. Le guichet choisi sera
//celui comportant le moins de voitures. Dans la réalité, le programme fonctionnerait avec des
//capteurs positionnés à chaque guichet pour savoir quelle voiture part, à quel guichet. Dans
//notre simulation, c'est l'utilisateur qui informera le programme au clavier des arrivées et des
//départs. On suppose que les arrivées sont traitées au fur et à mesure et que les automobilistes
//suivent le choix que leur propose la machine.
//Le cœur de l’algorithme a cette allure :
//faire
//ecrire('taper 1 si une voiture quitte un guichet, ')
//ecrire('taper 2 si une voiture arrive au péage, ')
//ecrire('taper 3 si fin du programme : ')
//lire(choix)
//si choix=1 alors .............
//si choix=2 alors ...............
//tant que choix≠3
//Voila un exemple d'exécution dans le cas où il y aurait 2 guichets (ce qui est en gras est écrit à
//l'écran par le programme, le reste est tapé par l'utilisateur). On suppose qu'au début, le péage
//est vide.
//*Taper 1 si une voiture quitte un guichet, taper 2 si une voiture arrive au péage, taper 3 si fin
//du programme :
//2
//La voiture doit se rendre au guichet n°1
//*Taper 1 si une voiture quitte un guichet, taper 2 si une voiture arrive au péage, taper 3
//si fin du programme :
//2
//La voiture doit se rendre au guichet n°2
//*Taper 1 si une voiture quitte un guichet, taper 2 si une voiture arrive au péage, taper 3
//si fin du programme :
//1
//*A quel guichet se trouvait la voiture qui part ?
//2
//Taper 1 si une voiture quitte un guichet, taper 2 si une voiture arrive au péage, taper 3 si fin
//du programme :
//2
//la voiture doit se rendre au guichet n°2
//etc............
//1°) Quelle structure de données allez-vous utiliser ? Décrivez précisément sa forme, son
//contenu et son fonctionnement. Montrez comment elle fonctionne sur un exemple d'une
//dizaine de voitures avec 3 guichets.
//2°) Vous écrirez les algorithmes correspondant aux fonctions de base du système. Ces
//        algorithmes doivent fonctionner quelque soit le nombre N de guichets. Vous écrirez ensuite
//        l’algorithme complet.
//3°) Et si au lieu d'un péage, votre programme devait gérer un parking ayant N étages chaque
//étage pouvant contenir k voitures ? Le but là serait d'indiquer à une voiture entrant quel est
//l'étage le plus haut (si c'est un parking souterrain) où il reste de la place. Décrivez la structure
//        que vous utiliseriez et son fonctionnement en cours d'exécution. On ne vous demande pas
//d'écrire les sous-programmes mais d'être très précis dans vos explications. Faites des dessins
//        si nécessaires

#include <stdio.h>
#include <string.h>

#define MAX 100

void initialisation(int *tab, int n) {

    int i;
    i = 0;
    while (i < n) {
        tab[i] = 0;
        i++;
    }
    return;
}

int rend_rang_min(int *tab, int n) {

    int i, min, rang;
    min = tab[0];
    rang = 0;
    i = 1;
    while (i < n) {
        if (tab[i] < min) {
            min = tab[i];
            rang = i;
        }
        i++;
    }
    return rang;
}

void ajout(int *tab, int e) {

    tab[e] = tab[e] + 1;

    return;
}

void supp(int *tab, int e) {

    tab[e-1] = tab[e-1] - 1;

    return;
}

int main() {

    int valid_input, choix, t[MAX], guichet, nb_guichet;

    printf("Combien de guichet : ");
    scanf("%d", &nb_guichet);

    while (nb_guichet < 0 || nb_guichet > 100) {
        printf("Saisie incorrecte\n");
        scanf("%d", &nb_guichet);
    }

    initialisation(t, nb_guichet);

    do {
        printf("\n");
        printf("1: Une voiture quitte le guichet \n");
        printf("2: Une voiture arrive au peage\n");
        printf("3: FIN \n");


        valid_input = 0;
        while (valid_input == 0) {

            printf("\n\nQue voulez-vous faire : ");

            if (scanf("%d", &choix) != 1 || choix < 1 || choix > 3) {
                printf("\nSaisie incorrecte. Veuillez entrer un nombre entier entre 1 et 3.\n");
                while (getchar() != '\n');
            } else {
                valid_input = 1;
            }
        }
        if (choix == 1) {
            printf("\nQuel guichet se vide : ");
            scanf("%d", &guichet);
            supp(t, guichet);
        }
        if (choix == 2) {
            printf("rdv au guichet numero %d", rend_rang_min(t, nb_guichet) + 1);
            ajout(t, rend_rang_min(t, nb_guichet));

        }

    }while (choix != 3);


    return 0;
}


