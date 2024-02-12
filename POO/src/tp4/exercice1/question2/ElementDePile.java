package tp4.exercice1.question2;

public class ElementDePile {

    private int donnee;
    private ElementDePile dessous;

    public ElementDePile(int arg) {
        this.donnee = arg;
        this.dessous = null;
    }

    public int getDonnee() {
        return this.donnee;
    }

    public ElementDePile empiler(int elem) {
        ElementDePile nouveau = new ElementDePile(elem);
        nouveau.dessous = this;
        return (nouveau);
    }

    public ElementDePile depiler() {
        return (this.dessous);
    }

    public int compterNbElementsDePile() {
        if (this.dessous != null) {
            return 1 + this.dessous.compterNbElementsDePile();
        } else {
            return 1;
        }
    }
    public void afficherElementDePile(){
        System.out.println(this.donnee);
        if(this.dessous != null){
            dessous.afficherElementDePile();
        }
    }
}
