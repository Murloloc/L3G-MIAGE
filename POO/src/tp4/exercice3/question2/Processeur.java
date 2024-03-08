package tp4.exercice3.question2;

public class Processeur {
    public ElementDeTourniquet tourniquet;

    public Processeur() {
        this.tourniquet = ElementDeTourniquet.creerTourniquetVide();
    }

    public void ajouterProcessusATraiter(Processus arg) {
        tourniquet = tourniquet.ajouterQueue(arg);
    }

    public void executerProcessuDuTourniquet() {
        Processus temp;
        while (!this.tourniquet.estVide()) {
            temp = tourniquet.getProcessus();
            tourniquet = tourniquet.retirerTete();
            temp.executerTache();
            if (!temp.AFini()) {
                tourniquet = tourniquet.ajouterQueue(temp);
            }
        }
    }

    public void afficherTourniquet() {
            tourniquet.afficherElementDeTourniquet();
    }
}
