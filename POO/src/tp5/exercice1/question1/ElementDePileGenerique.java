package tp5.exercice1.question1;


public class ElementDePileGenerique<T> {

    private T donnee;
    private ElementDePileGenerique<T> dessous;

    private ElementDePileGenerique(T arg) {
        this.donnee = arg;
        this.dessous = null;
    }

    private ElementDePileGenerique() {
        this(null);
    }

    public static <U> ElementDePileGenerique<U> creerPileVide() {
        return (new ElementDePileGenerique<U>(null));
    }

    public T getDonnee() {
        return this.donnee;
    }

    public boolean estVide() {
        return this.donnee == null;
    }

    public ElementDePileGenerique<T> empiler(T elem) {
        ElementDePileGenerique<T> nouveau = new ElementDePileGenerique<T>(elem);
        nouveau.dessous = this;
        return (nouveau);
    }

    public ElementDePileGenerique<T> depiler() {
        return this.dessous;
    }

    public int compterNbElementsDePileEvoluee() {
        if (this.dessous != null) {
            return 1 + this.dessous.compterNbElementsDePileEvoluee();
        } else {
            return 0;
        }
    }

    public void afficherElementDePileGenerique() {
        System.out.println(this.donnee);
        if (this.donnee != null) {
            dessous.afficherElementDePileGenerique();
        }
    }
}
