package tp4.exercice2.question2;

public class ElementDeFile {
    private int donnee;
    private ElementDeFile suivant;

    public ElementDeFile(int arg) {
        this.donnee = arg;
        this.suivant = null;
    }

    public int getDonnee() {
        return this.donnee;
    }

    public ElementDeFile ajouterQueue(int elem) {
        ElementDeFile nouveau = new ElementDeFile(elem);
        ElementDeFile queue = this;
        while (queue.suivant != null) {
            queue = queue.suivant;
        }
        queue.suivant = nouveau;
        return (this);
    }

    public ElementDeFile retirerTete() {
        return (this.suivant);
    }

    public int compterNbElementsDeFile() {
        if (this.suivant != null) {
            return 1 + this.suivant.compterNbElementsDeFile();
        } else {
            return 1;
        }
    }

    public void afficherElementDeFile() {
        System.out.println(this.donnee);
        if (this.suivant != null) {
            suivant.afficherElementDeFile();
        }
    }
}
