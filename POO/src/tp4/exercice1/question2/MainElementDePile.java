package tp4.exercice1.question2;

public class MainElementDePile {

    public static void main(String[] args) {

        ElementDePile pileA = new ElementDePile(7);
        ElementDePile pileB = new ElementDePile(4);


        pileA = pileA.empiler(9);

        pileA = pileA.empiler(5);

        pileA = pileA.empiler(9);

        pileA = pileA.empiler(6);


        pileB = pileB.empiler(4);

        pileB = pileB.empiler(2);

        pileB = pileB.empiler(18);

        if (pileA != null) {
            pileA.afficherElementDePile();

            System.out.println("La pile A contient " + pileA.compterNbElementsDePile() + " elements");
        }
        System.out.println("------------");
        if (pileB !=null) {
            pileB.afficherElementDePile();
            System.out.println("La pile B contient " + pileB.compterNbElementsDePile() + " elements");
        }
        System.out.println("------------");

        while (pileA !=null & pileB!=null) {
            pileA = pileA.depiler();
            pileB = pileB.depiler();
        }
        if (pileA != null) {
            pileA.afficherElementDePile();
            System.out.println("La pile A contient " + pileA.compterNbElementsDePile() + " elements");
            System.out.println("------------");
        }
        if (pileB !=null) {
            pileB.afficherElementDePile();
            System.out.println("La pile B contient " + pileB.compterNbElementsDePile() + " elements");
            System.out.println("------------");
        }
    }
}
