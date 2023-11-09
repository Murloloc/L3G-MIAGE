//11. Écrire un programme qui demande à l’utilisateur sa date de naissance sous la forme
//"04/12/2000". Le programme testera si la date donnée comprend bien 10 caractères dont
//le 3ème et le 6ème sont des "/", puis récupèrera le mois de naissance pour afficher un
//texte du style "vous êtes né en décembre".

#include <stdio.h>
#include <string.h>
#define N 50
int main() {

    char date[11];
    char Listemois[12][10] = { "janvier", "février", "Mars", "avril", "mai", "juin", "juillet", "août", "septembre", "octobre", "novembre", "décembre"};
    char mois[3];

    printf("Donnez votre date de naissance dans le format jj/mm/aaaa \n");
    scanf("%s", date);

    while (date[2] != '/' || date[5] != '/' || strlen(date) != 10) {
        printf("Le format n'est pas bon re essayez :\n");
        scanf("%s", date);
    }

    mois[0] = date[3];
    mois[1] = date[4];
    mois[2] = '\0';

    while ((strcmp(mois, "01") < 0 || strcmp(mois, "12") > 0)) {
        printf("Le mois n'est pas bon re essayez :\n");
        scanf("%s", date);
        mois[0] = date[3];
        mois[1] = date[4];
        mois[2] = '\0';
    }

    if (strcmp(mois, "01") == 0) {
        printf("Vous etes ne en janvier\n");
    } else if (strcmp(mois, "02") == 0) {
        printf("Vous etes ne en fevrier\n");
    } else if (strcmp(mois, "03") == 0) {
        printf("Vous etes ne en mars\n");
    } else if (strcmp(mois, "04") == 0) {
        printf("Vous etes ne en avril\n");
    } else if (strcmp(mois, "05") == 0) {
        printf("Vous etes ne en mai\n");
    } else if (strcmp(mois, "06") == 0) {
        printf("Vous etes ne en juin\n");
    } else if (strcmp(mois, "07") == 0) {
        printf("Vous etes ne en juillet\n");
    } else if (strcmp(mois, "08") == 0) {
        printf("Vous etes ne en aout\n");
    } else if (strcmp(mois, "09") == 0) {
        printf("Vous etes ne en septembre\n");
    } else if (strcmp(mois, "10") == 0) {
        printf("Vous etes ne en octobre\n");
    } else if (strcmp(mois, "11") == 0) {
        printf("Vous etes ne en novembre\n");
    } else if (strcmp(mois, "12") == 0) {
        printf("Vous etes ne en decembre\n");
    }
    return 0;
}