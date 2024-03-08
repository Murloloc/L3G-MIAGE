package tp4.exercice3.question2;

public class ElementDeTourniquet {
    private Processus process;
    private ElementDeTourniquet suivant;

    private ElementDeTourniquet(Processus arg) {
        this.process = arg;
        this.suivant = null;
    }

    private ElementDeTourniquet() {
        this(null);
    }

    public static ElementDeTourniquet creerTourniquetVide() {
        return (new ElementDeTourniquet(null));
    }

    public Processus getProcessus() {
        return this.process;
    }

    public boolean estVide() {
        return this.suivant == null;
    }

    public ElementDeTourniquet ajouterQueue(Processus arg) {
        if (this.estVide()) {
            ElementDeTourniquet nouveau = new ElementDeTourniquet(arg);
            nouveau.suivant = this;
            return nouveau;
        } else {
            this.suivant = this.suivant.ajouterQueue(arg);
            return (this);
        }
    }

    public ElementDeTourniquet retirerTete() {
        if (!this.estVide()) {
            return this.suivant;
        } else {
            return this;
        }
    }

    public int compterNbProcessusDeTourniquet() {
        if (this.estVide()) {
            return (0);
        } else {
            return (1 + this.suivant.compterNbProcessusDeTourniquet());
        }
    }

    public void afficherElementDeTourniquet() {
        if (this.estVide()) {
            System.out.println("File vide");
        } else {
            this.getProcessus().afficherProcessus();
            if (this.suivant != null) {
                this.suivant.afficherElementDeTourniquet();
            }
        }
    }
}
