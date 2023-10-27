//16. Écrire un sous-programme qui étant donnés un tableau de n réels et un réel, rend
//si le réel appartient ou pas au tableau et s’il appartient, rend le rang de sa première
//occurrence.

int cherche_vaeleur(float *tab, int n, int x) {

    int i, indice;

    i = 0;
    while (i < n) {
        if (tab[i] == x) {
            indice = i;
        }
        i++;
    }
    return indice;
}

int main() {


    return 0;
}