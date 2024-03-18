package tp5.exercice1.question1;

public class MainElementDePileGenerique {

    public static void main (String[] args){

        ElementDePileGenerique<Integer> pileA = ElementDePileGenerique.<Integer>creerPileVide();

        ElementDePileGenerique<Integer> pileB = ElementDePileGenerique.<Integer>creerPileVide();

        pileA = pileA.empiler(9);
        pileA = pileA.empiler(5);
        pileA = pileA.empiler(9);
        pileA = pileA.empiler(6);

        pileB = pileB.empiler(4);
        pileB = pileB.empiler(2);
        pileB = pileB.empiler(18);

        if (pileA.getDonnee() != null) {
            pileA.afficherElementDePileGenerique();
            System.out.println("La pile A contient " + pileA.compterNbElementsDePileEvoluee() + " elements");
        }
        System.out.println("------------");
        if (pileB.getDonnee() !=null) {
            pileB.afficherElementDePileGenerique();
            System.out.println("La pile B contient " + pileB.compterNbElementsDePileEvoluee() + " elements");
        }
        System.out.println("------------");

        while (pileA.getDonnee() !=null & pileB.getDonnee()!=null) {
            pileA = pileA.depiler();
            pileB = pileB.depiler();
        }
        if (pileA.getDonnee() != null) {
            pileA.afficherElementDePileGenerique();
            System.out.println("La pile A contient " + pileA.compterNbElementsDePileEvoluee() + " elements");
            System.out.println("------------");
        }
        if (pileB.getDonnee() !=null) {
            pileB.afficherElementDePileGenerique();
            System.out.println("La pile B contient " + pileB.compterNbElementsDePileEvoluee() + " elements");
            System.out.println("------------");
        }
    }

}