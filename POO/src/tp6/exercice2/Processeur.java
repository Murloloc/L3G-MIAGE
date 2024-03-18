package tp6.exercice2;

import java.util.LinkedList;

public class Processeur {

    public LinkedList<Processus> tourniquet;

    public Processeur() {
        this.tourniquet = new LinkedList<Processus>();
    }

    public void ajouterProcessusATraiter(Processus arg) {
        this.tourniquet.add(arg);
    }

    public void executerProcessuDuTourniquet() {
        Processus temp;
        while (!this.tourniquet.isEmpty()) {
            temp = this.tourniquet.poll();
            temp.executerTache();
            if (!temp.AFini()) {
                this.tourniquet.add(temp);
            }
        }
    }

    public void afficherTourniquet() {
        System.out.println(this.tourniquet);
    }
}


