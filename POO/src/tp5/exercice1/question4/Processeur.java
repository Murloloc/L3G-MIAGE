package tp5.exercice1.question4;

import tp5.exercice1.question2.ElementDeFileGenerique;

public class Processeur {
    public ElementDeFileGenerique<Processus> tourniquet;

    public Processeur() {
        this.tourniquet = ElementDeFileGenerique.<Processus>creerFileVide();
    }

    public void ajouterProcessusATraiter(Processus arg) {
        tourniquet = tourniquet.ajouterQueue(arg);
    }

    public void executerProcessuDuTourniquet() {
        Processus temp;
        while (!this.tourniquet.estVide()) {
            temp = tourniquet.getDonnee();
            tourniquet = tourniquet.retirerTete();
            temp.executerTache();
            if (!temp.AFini()) {
                tourniquet = tourniquet.ajouterQueue(temp);
            }
        }
    }

    public void afficherTourniquet() {
        tourniquet.afficherElementDeFileGenerique();
    }
}
