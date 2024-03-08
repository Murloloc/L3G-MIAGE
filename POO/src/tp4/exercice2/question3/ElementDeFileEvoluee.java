package tp4.exercice2.question3;


public class ElementDeFileEvoluee {
    private Integer donnee;
    private ElementDeFileEvoluee suivant = null;

    //Constructeurs
    public ElementDeFileEvoluee(Integer donnee) {
        this.donnee = donnee;
        this.suivant = null;
    }

    private ElementDeFileEvoluee() {
        this(null);
    }

    public Integer getDonnee() {
        return (this.donnee);
    }

    //Creation de file vide
    public static ElementDeFileEvoluee creerFileVide() {
        return (new ElementDeFileEvoluee());
    }

    //Test file vide
    public boolean estVide() {
        return (this.donnee == null);
    }

    //Ajout d'un element en queue de file
    public ElementDeFileEvoluee ajouterQueue(Integer donnee) {
        if (this.estVide()) {
            ElementDeFileEvoluee nouveau = new ElementDeFileEvoluee(donnee);
            nouveau.suivant = this;
            return (nouveau);
        } else {


            this.suivant = this.suivant.ajouterQueue(donnee);
            return (this);
        }
    }

    //Suppression d'un element en tête de file
    public ElementDeFileEvoluee retirerTete() {
        if (!this.estVide())
            return (this.suivant);
        else
            return (this);
    }

    //Affichage de la file
    public void afficherElementDeFileEvoluee() {
        if (!this.estVide()) {
            System.out.println("Element courant : " + this.donnee.intValue());
            this.suivant.afficherElementDeFileEvoluee();
        }
    }

    //Comptage du nombre d'elements dans la file
    public int compterNbElementsDeFileEvoluee() {
        if (this.estVide())
            return (0);
        else
            return (1 + this.suivant.compterNbElementsDeFileEvoluee());
    }
}