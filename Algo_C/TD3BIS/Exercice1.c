//Exercice 1. On propose d’écrire un programme qui effectue un certain nombre de
//traitements sur la note de mathématique des étudiants de deux classes A et B. Le
//nombre d’étudiants des deux promotions n’est pas obligatoirement le même, il sera
//demandé en début de programme à l’utilisateur avec un maximum de 50 étudiants par
//promotion.
//Votre programme devra :
//- enregistrer les notes des étudiants de chaque classe
//- afficher quelle classe a obtenu la meilleure moyenne
//- afficher quelle classe a obtenu la meilleure note
//- afficher quelle classe a l’écart-type le plus important
//- afficher les notes de chaque classe dans l’ordre décroissant
//- afficher quelle classe a obtenu la note médiane la plus faible

#include <stdio.h>
#include <math.h>

#define NA 50
#define NB 50

int main() {

    int nbA, nbB, i, flag;
    float classeA[NA],classeB[NB];
    float somme, moyenneA, moyenneB, maxA, maxB, ecart_moyenneA, ecart_moyenneB;
    float varianceA, varianceB, ecart_typeA, ecart_typeB, ech, medianeA, medianeB, milieu1, milieu2;


    //Demande le nombre d etudiant en classe A

    printf("Donnez le nombre d'eleves de la classe A\n");
    scanf("%d", &nbA);

    while (nbA < 1 || nbA > 50) {
        printf("Ce nombre d'eleve n'est pas accepte, re donnez un nombre compris entre 1 et 50\n");
        scanf("%d", &nbA);
    }

    //Demande le nombre d etudiant en classe B

    printf("Donnez le nombre d'eleves de la classe B\n");
    scanf("%d", &nbB);


    while (nbB < 1 || nbB > 50) {
        printf("Ce nombre d'eleve n'est pas accepte, re donnez un nombre compris entre 1 et 50\n");
        scanf("%d", &nbB);
    }

    //Enregistrement des notes classe A
    i = 0;
    while (i < nbA) {
        printf("Donnez la note de l etudiant numero %d de la classe A\n", i + 1);
        scanf("%f", &classeA[i]);
        i = i + 1;
    }

    //Enregistrement des notes classe B
    i = 0;
    while (i < nbB) {
        printf("Donnez la note de l etudiant numero %d de la classe B\n", i + 1);
        scanf("%f", &classeB[i]);
        i = i + 1;
    }

    //Calcul moyenne et max classe A
    i = 0;
    maxA = classeA[i];
    somme = 0;
    while (i < nbA) {
        somme = somme + classeA[i];
        if (classeA[i] > maxA) {
            maxA = classeA[i];
        }
        i = i + 1;
    }
    moyenneA = somme / nbA;

    //Calcul moyenne et max classe B
    i = 0;
    maxB = classeB[i];
    somme = 0;
    while (i < nbB) {
        somme = somme + classeB[i];
        if (classeB[i] > maxB) {
            maxB = classeB[i];
        }
        i = i + 1;
    }
    moyenneB = somme / nbB;

    //Affichage meilleure moyenne
    //Je sais que les \n ne sont pas des balises je let met au début et à la fin pour sauter une ligne au début et à la fin
    if (moyenneA > moyenneB) {
        printf("\nLa meilleure moyenne est la classe A avec une moyenne de : %.2f\n", moyenneA);
    } else if (moyenneA < moyenneB) {
        printf("\nLa meilleure moyenne est la classe B avec une moyenne de : %.2f\n", moyenneB);
    } else {
        printf("\nLes deux moyennes sont egales et valent %.2f\n", moyenneA);
    }
    //Affichage meilleure note
    if (maxA > maxB) {
        printf("\nLa meilleure note appartient a la classe A avec une valeur de : %.2f\n", maxA);
    } else if (maxA < maxB) {
        printf("\nLa meilleure note appartient a la classe B avec une valeur de : %.2f\n", maxB);
    } else {
        printf("\nLes meilleures notes de la classe A et de la B sont égales et valent %.2f\n", maxA);
    }

    //calcul de l'écart type classe A

    //on commence par calculer les ecarts a la moyenne

    i = 0;
    ecart_moyenneA = 0;
    while (i < nbA) {
        ecart_moyenneA = ecart_moyenneA + ((classeA[i] - moyenneA) * (classeA[i] - moyenneA));
        i = i + 1;
    }

    //maintenant on calcule la variance : c'est la moyenne des carres des ecarts a la moyenne
    varianceA = ecart_moyenneA / nbA;

    //ecart type racine carree de la variance
    ecart_typeA = sqrt(varianceA);


    //calcul de l'écart type classe B

    i = 0;
    ecart_moyenneB = 0;
    while (i < nbB) {
        ecart_moyenneB = ecart_moyenneB + ((classeB[i] - moyenneB) * (classeB[i] - moyenneB));
        i = i + 1;
    }

    //maintenant on calcule la variance : c'est la moyenne des carres des ecarts a la moyenne
    varianceB = ecart_moyenneB / nbB;

    //ecart type racine carree de la variance
    ecart_typeB = sqrt(varianceB);

    if (ecart_typeA > ecart_typeB) {
        printf("\nLa classe A a l ecart type le plus important avec une valeur de :%.2f\n", ecart_typeA);
    } else if (ecart_typeA < ecart_typeB) {
        printf("\nLa classe B a l ecart type le plus important avec une valeur de :%.2f\n", ecart_typeB);
    } else {
        printf("\nLes deux classes ont le meme ecart type avec une valeur de %.2f\n", ecart_typeA);
    }

    //Affichage des notes de la classe A dans l'odre décroissant avec le tri à bulles

    i = 0;
    flag = 1;
    while (flag == 1) {
        flag = 0;
        i = 0;
        while (i < nbA - 1) {
            if (classeA[i] < classeA[i + 1]) {
                ech = classeA[i];
                classeA[i] = classeA[i + 1];
                classeA[i + 1] = ech;
                flag = 1;
            }
            i = i + 1;
        }
    }
    i = 0;
    printf("\nVoici le tableau de notes de la classe A dans l'odre decroissant\n");
    while (i < nbA) {
        printf("%.2f\n", classeA[i]);
        i = i + 1;
    }

    //Affichage des notes de la classe B dans l'odre décroissant avec le tri à bulles

    i = 0;
    flag = 1;
    while (flag == 1) {
        flag = 0;
        i = 0;
        while (i < nbB - 1) {
            if (classeB[i] < classeB[i + 1]) {
                ech = classeB[i];
                classeB[i] = classeB[i + 1];
                classeB[i + 1] = ech;
                flag = 1;
            }
            i = i + 1;
        }
    }
    i = 0;
    printf("\nVoici le tableau de notes de la classe B dans l'odre decroissant\n");
    while (i < nbB) {
        printf("%.2f\n", classeB[i]);
        i = i + 1;
    }

    //calcul de la médiane classe A

    if (nbA % 2 == 0) {
        milieu1 = classeA[(nbA - 1) / 2];
        milieu2 = classeA[nbA / 2];
        medianeA = (milieu1 + milieu2) / 2;
    } else {
        medianeA = classeA[nbA / 2];
    }

    //calcul de la médiane classe B

    if (nbB % 2 == 0) {
        milieu1 = classeB[(nbB - 1) / 2];
        milieu2 = classeB[nbB / 2];
        medianeB = (milieu1 + milieu2) / 2;
    } else {
        medianeB = classeB[nbB / 2];
    }

    //affichage mediane la plus faible

    if (medianeA < medianeB) {
        printf("\nLa classe A a la mediane la plus faible avec une valeur de : %.2f\n", medianeA);
    } else if (medianeA > medianeB) {
        printf("\nLa classe B a la mediane la plus faible avec une valeur de : %.2f\n", medianeB);
    } else {
        printf("\nLes deux classes ont la meme mediane la plus faible avec une valeur de %.2f\n", medianeA);
    }

    return 0;
}

