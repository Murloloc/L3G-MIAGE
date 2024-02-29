package tp4.exercice3.question1;

public class ElementDeTas {
    private Carte carte;
    private ElementDeTas dessous;

    private ElementDeTas(Carte card) {
        this.carte = card;
        this.dessous = null;
    }

    private ElementDeTas() {
        this(null);
    }

    public static ElementDeTas creerTasVide() {
        return (new ElementDeTas(null));
    }

    public Carte getCarte() {
        return this.carte;
    }

    public boolean estVide() {
        return this.carte == null;
    }

    public ElementDeTas empiler(Carte card) {
        ElementDeTas nouveau = new ElementDeTas(card);
        nouveau.dessous = this;
        return nouveau;
    }

    public ElementDeTas depiler() {
        if (!this.estVide()) {
            return this.dessous;
        } else {
            return this;
        }
    }

    public int compterNbCartesDeTas() {
        if (this.estVide()) {
            return 0;
        } else {
            return 1 + this.dessous.compterNbCartesDeTas();
        }
    }
    public void afficherElementDeTas() {
        if (this.estVide()) {
            System.out.println("Pile vide");
        } else {
            this.getCarte().afficherCarte();
            if (this.dessous != null) {
                this.dessous.afficherElementDeTas();
            }
        }
    }
}

