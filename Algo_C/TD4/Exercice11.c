//11. Écrire un sous-programme en C qui remplit un tableau de n réels lus au clavier.
//Écrire un sous-programme qui étant donné un tableau de n réels calcule la
//moyenne des éléments du tableau. Utilisez ces sous-programmes dans un
//programme principal qui travaille sur les notes de 25 étudiants.

#include <stdio.h>

#define N 25

void rempli_tableau(float t[], int n) {

    int i;
    float x;

    i = 0;
    while (i < n) {
        printf("Donnez la valeur %d du tableau :\n", i + 1);
        scanf("%f", &t[i]);
        i++;
    }
    return;
}

//void affiche_tableau(float t[], int n) {
//
//    int i;
//
//    printf("Voici le tableau que vous avez rempli :\n");
//    i = 0;
//    while (i < n) {
//        printf("%.2f\n", t[i]);
//        i++;
//    }
//    return;
//}

float calcule_moyenne(float t[], int n) {

    int i;
    float m;

    i = 0;
    m = 0;
    while (i < n) {
        m = m + t[i];
        i++;
    }
    return m / n;
}

int main() {

    int nb;
    float t[N], moyenne;

    printf("Quelle est la taille du tableau ?\n");
    scanf("%d", &nb);
    while (nb < 1 || nb > 25) {
        printf("La taille du tableau doit etre comprise entre 1 et 25 donnez une nouvelle valeur\n");
        scanf("%d", &nb);
    }

    rempli_tableau(t, nb);
    //affiche_tableau(t, nb);
    moyenne = calcule_moyenne(t, nb);
    printf("La moyenne du tableau est de %.2f\n", moyenne);


    return 0;
}