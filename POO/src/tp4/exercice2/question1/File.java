package tp4.exercice2.question1;

public class File {
    private int nbElem;
    private int maxElem;
    private int[] maFile;

    public File(int arg) {
        this.maxElem = arg;
        this.nbElem = 0;
        this.maFile = new int[this.maxElem];
        for (int i = 0; i < maxElem; i++) {
            this.maFile[i] = 0;
        }
    }

    public boolean estVide() {
        return nbElem == 0;
    }

    public boolean estPleine() {
        return nbElem == maxElem;
    }

    public void ajouterQueue(int elem) {
        if (this.estPleine()) {
            System.out.println("File pleine");
        } else {
            this.maFile[nbElem] = elem;
            nbElem++;
        }
    }

    public int retirerTete() {
        if (this.estVide()) {
            System.out.println("File vide");
            return 0;
        } else {
            int x = this.maFile[0];
            for (int i = 0; i < this.maxElem - 1; i++) {
                this.maFile[i] = this.maFile[i + 1];
            }
            this.nbElem--;
            return x;
        }
    }

    public int compterNbElementsDeFile() {
        return this.nbElem;
    }

    public void afficherFile() {
        if (this.estVide()) {
            System.out.println("La pile est vide");
        } else {
            for (int i = 0; i < this.nbElem; i++) {
                System.out.println("Element numero : " + (i + 1) + " = " + this.maFile[i]);
            }
        }
    }
}
