package tp4.exercice1.question1;

public class MainPile {
    public static void main(String[] args) {

        Pile pile20 = new Pile(20);
        Pile pile5 = new Pile(5);

        pile20.empiler(14);
        pile20.empiler(12);

        pile5.empiler(8);
        pile5.empiler(7);
        pile5.empiler(1);
        pile5.empiler(9);
        pile5.empiler(14);
        pile5.empiler(4);

        pile20.afficherPile();
        System.out.println("----------");
        pile5.afficherPile();

        while (!pile5.estVide() && !pile20.estVide()) {
            int x =pile5.depiler();
            System.out.println(x + " a ete supprime");
            x = pile20.depiler();
            System.out.println(x + " a ete supprime");
        }

        System.out.println("----------");
        pile20.afficherPile();
        System.out.println("La pile 20 contient : " + pile20.compterNbElementsDePile() + " elements");
        System.out.println("----------");
        pile5.afficherPile();
        System.out.println("La pile 5 contient : " + pile5.compterNbElementsDePile() + " elements");

    }
}
