package tp5.exercice1.question2;

public class ElementDeFileGenerique<T> {
    private T donnee;
    private ElementDeFileGenerique<T> suivant = null;

    //Constructeurs
    public ElementDeFileGenerique(T donnee) {
        this.donnee = donnee;
        this.suivant = null;
    }

    private ElementDeFileGenerique() {
        this(null);
    }

    public T getDonnee() {
        return (this.donnee);
    }

    //Creation de file vide
    public static <U> ElementDeFileGenerique<U> creerFileVide() {
        return (new ElementDeFileGenerique<U>());
    }

    public boolean estVide() {
        return (this.donnee == null);
    }

    //Ajout d'un element en queue de file
    public ElementDeFileGenerique<T> ajouterQueue(T donnee) {
        if (this.estVide()) {
            ElementDeFileGenerique<T> nouveau = new ElementDeFileGenerique<T>(donnee);
            nouveau.suivant = this;
            return (nouveau);
        } else {
            this.suivant = this.suivant.ajouterQueue(donnee);
            return (this);
        }
    }

    public ElementDeFileGenerique<T> retirerTete() {
        if (!this.estVide())
            return (this.suivant);
        else
            return (this);
    }

    public void afficherElementDeFileGenerique() {
        if (!this.estVide()) {
            System.out.println("Element courant : " + this.donnee);
            this.suivant.afficherElementDeFileGenerique();
        }
    }

    public int compterNbElementsDeFileGenerique() {
        if (this.estVide())
            return (0);
        else
            return (1 + this.suivant.compterNbElementsDeFileGenerique());
    }
}
