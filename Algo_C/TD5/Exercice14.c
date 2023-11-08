//14. Écrire un sous-programme en C qui étant donné une phrase rend le nombre d’articles
//présents dans la phrase (on rappelle que les articles sont les mots : le, la, les, un, une,
//des).

#include <stdio.h>
#include <string.h>

//après 4 heures 30 de bataille contre les forces du mal voici l'exo 14 version completement hors consigne mais
// essentiel qui marche et qui fait sens au lieu de  faire du cas par cas là ça marche pour n importe quel mot

//apres avoir vu la correction 2 de cet exo bah c est quand meme mieux, tout en 1sp et on peut compter n importe
//quel mot

int rendNombreMot(char *phr, char *mot) {

    int i, cpt, j;

    i = 0;
    j = 0;
    cpt = 0;

    while (i + j < strlen(phr)) {
        if (j == strlen(mot)) {
            if ((i == 0 || phr[i - 1] == ' ') && (i + j == strlen(phr) - 1 || phr[i + j] == ' ')) {
                cpt++;
                j = 0;
                i++;
            }
        }
        if (phr[i + j] == mot[j]) {
            j++;
        } else {
            i++;
            j = 0;
        }
    }
    return cpt;
}

int main() {

    int res;
    char phrase[80];

    printf("Donnez votre mot \n");
    fgets(phrase, 80, stdin);

    res = rendNombreMot(phrase, "le") + rendNombreMot(phrase, "la") + rendNombreMot(phrase, "les") +
          rendNombreMot(phrase, "un") + rendNombreMot(phrase, "une") + rendNombreMot(phrase, "des");
    printf("%d", res);

    return 0;
}

//corrigé de la prof

//#include <stdio.h>
//#include <string.h>
//
//typedef char STRING[80];
//
//int compte_article(STRING s) {
//    int i, a, cpt;
//    STRING s_temp;
//    cpt = 0;
//    strcpy(s_temp, s);
//    strcat(s_temp, ".");
//    i = 0;
//    while (i < strlen(s_temp) - 2) {
//        if (s[i] == ' ' || i == 0) {
//            if (i == 0) { a = 0; } else { a = i + 1; }
//            if (s_temp[a] == 'u') {
//                a = a + 1;
//                if (s_temp[a] == 'n') {
//                    a = a + 1;
//                    if (s_temp[a] == 'e') {
//                        a = a + 1;
//                        if (s_temp[a] == ' ' || a == strlen(s_temp) - 1) {
//                            cpt = cpt + 1;
//                        }
//                    } else {
//                        if (s_temp[a] == ' ' || a == strlen(s_temp) - 1) {
//                            cpt = cpt + 1;
//                        }
//                    }
//                }
//            } else {
//                if (s_temp[a] == 'l') {
//                    a = a + 1;
//                    if (s_temp[a] == 'e') {
//                        a = a + 1;
//                        if (s_temp[a] == ' ' || a == strlen(s_temp) - 1) {
//                            cpt = cpt + 1;
//                        } else {
//                            if (s_temp[a] == 's') {
//                                a = a + 1;
//                                if (s_temp[a] == ' ' || a == strlen(s_temp) - 1) {
//                                    cpt = cpt + 1;
//                                }
//                            }
//                        }
//                    } else {
//                        if (s_temp[a] == 'a') {
//                            a = a + 1;
//                            if (s_temp[a] == ' ' || a == strlen(s_temp) - 1) {
//                                cpt = cpt + 1;
//                            }
//
//                        }
//                    }
//                } else {
//                    if (s_temp[a] == 'd') {
//                        a = a + 1;
//                        if (s_temp[a] == 'e') {
//                            a = a + 1;
//                            if (s_temp[a] == 's') {
//                                a = a + 1;
//                                if (s_temp[a] == ' ' || a == strlen(s_temp) - 1) {
//                                    cpt = cpt + 1;
//                                }
//                            }
//                        }
//                    }
//                }
//            }
//        }
//        i = i + 1;
//    }
//    return cpt;
//}
//
//int main() {
//    STRING phrase;
//    printf("\nTapez une phrase : ");
//    fgets(phrase, 80, stdin);
//    phrase[strlen(phrase) - 1] = '\0';
//    printf("\nLe nombre d'article dans la phrase est : %d\n\n", compte_article(phrase));
//    return 0;
//}