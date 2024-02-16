package tp4.exercice1.question3;

public class ElementDePileEvoluee {
    private Integer donnee;
    private ElementDePileEvoluee dessous;

    private ElementDePileEvoluee(Integer arg) {
        this.donnee = arg;
        this.dessous = null;
    }

    private ElementDePileEvoluee() {
        this(null);
    }

    public static ElementDePileEvoluee creerPileVide() {
        return (new ElementDePileEvoluee(null));
    }

    public Integer getDonnee() {
        return this.donnee;
    }

    public boolean estVide() {
        return this.donnee == null;
    }

    public ElementDePileEvoluee empiler(Integer elem) {
        ElementDePileEvoluee nouveau = new ElementDePileEvoluee(elem);
        nouveau.dessous = this;
        return (nouveau);
    }

    public ElementDePileEvoluee depiler() {
        return this.dessous;
    }

    public int compterNbElementsDePileEvoluee() {
        if (this.dessous != null) {
            return 1 + this.dessous.compterNbElementsDePileEvoluee();
        } else {
            return 0;
        }
    }
    public void afficherElementDePileEvoluee() {
        System.out.println(this.donnee);
        if (this.donnee != null) {
            dessous.afficherElementDePileEvoluee();
        }
    }
}
