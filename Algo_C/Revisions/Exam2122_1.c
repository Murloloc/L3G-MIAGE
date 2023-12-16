//
// Created by laure on 07/12/2023.
//

#include <stdio.h>


int main() {

    int a, b, c, n, i;
    a = 0;
    b = 4;
    n = 0;

    printf(" i : ");
    scanf("%d", &i);
    while (n <= i - 2) {
        c = -n * a + 5 * b + 5;
        a = b;
        b = c;
        n++;
    }

    printf("%d", c);
    return 0;
}


ETU rend_etu(ETU *tab, int ne, int num_mat) {

    int i, flag, rang_max;
    float max;

    max = tab[0].note[num_mat];
    rang_max = 0;
    i = 1;
    while (i < ne) {
        if (tab[i].notes[num_mat] > max) {
            max = tab[i].notes[num_mat];
            rang_max = i;
        }
        i++;
    }
    return tab[rang_max];

}

float rend_moyenne_mat(ETU *tab,int ne, int num){

    int i;
    float s;
    i=0;
    s=0;
    while (i<ne){
        s=s+tab[i].notes[num];
        i++;
    }
    return s/ne;
}

int rend_mat_meilleure(ETU *tab, int nbn,int ne){
    int i,rang;
    float max;

    max= rend_moyenne_mat(tab,ne,0);
    i=1;
    while (i<nbn){
        if(max< rend_moyenne_mat(tab,ne,i)){
           max= rend_moyenne_mat(tab,ne,i);
           rang=i;
        }
        i++;
    }
    return rang;
}

void insere(int *tab, int *BS, int e) {

    int i, flag, num_ajout;

    i = 0;
    flag = 0;

    while (i < *BS && flag == 0) {
        if (tab[i] >= e) {
            flag = 1;
        } else {
            i++;
        }
    }
    num_ajout = i;
    i = *BS+1;

    while (i > num_ajout) {
        tab[i] = tab[i - 1];
        i--;
    }
    tab[num_ajout] = e;
    *BS = *BS + 1;
    return;
}

void tri_par_insertion(int *tab, int nbv){

    int BS;

    BS=0;
    while (BS<nbv){
        insere(tab,&BS,tab[BS+1]);
    }
    return;
}