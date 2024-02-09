package tp4.exercice1.question1;

public class Pile {
    private int nbElem;
    private int maxElem;
    private int[] maPile;

    public Pile(int arg) {
        this.nbElem = 0;
        this.maxElem = arg;
        this.maPile = new int[this.maxElem];
        for (int i = 0; i < this.maxElem; i++) {
            this.maPile[i] = 0;
        }
    }

    public boolean estVide() {
        return this.nbElem == 0;
    }

    public boolean estPleine() {
        return this.nbElem == this.maxElem;
    }

    public void empiler(int elem) {
        if (this.estPleine()) {
            System.out.println("Pile pleine");
        } else {
            this.maPile[this.nbElem] = elem;
            this.nbElem++;
        }
    }

    public int depiler() {
        if (this.estVide()) {
            System.out.println("Pile vide");
            return 0;
        } else {
            int x = this.maPile[this.nbElem-1];
            this.nbElem--;
            return x;
        }
    }

    public int compterNbElementsDePile() {
        return this.nbElem;
    }

    public void afficherPile() {
        if (this.estVide()){
            System.out.println("La pile est vide");
        } else {
            for (int i = 0; i < this.nbElem; i++) {
                System.out.println("Element numéro : " + (i + 1) + " = " + this.maPile[i]);
            }
        }
    }
}
