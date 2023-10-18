//9. On place un capital c à un taux mensuel t. Écrire un sous-programme en C qui
//indique au bout de combien de mois le capital aura dépassé une borne b
//(le sousprogramme doit utiliser une boucle et non pas une formule mathématique).
//Rappel : chaque mois, le capital augmente en fonction du taux.

#include <stdio.h>

int indique_borne(float c,float t,float b) {

    int m;
    m=0;

    while (c<b){
        c=c*t;
        m++;
    }
    return m;
}

int main() {

    float capital_initial,taux_mensuel,borne;
    int mois;

    printf("Quel est le capital initial ?\n");
    scanf("%f",&capital_initial);
    printf("Quel est le taux mensuel?\n");
    scanf("%f",&taux_mensuel);
    printf("Quelle est votre borne ?\n");
    scanf("%f",&borne);

    mois= indique_borne(capital_initial,taux_mensuel,borne);
    printf("Le capital aura depasse la borne au bout de %d mois\n",mois);

    return 0;
}