package tp4.exercice2.question1;


public class MainFile {
    public static void main(String[] args) {
        File file20 = new File(20);
        File file5 = new File(5);

        file20.ajouterQueue(14);
        file20.ajouterQueue(12);

        file5.ajouterQueue(8);
        file5.ajouterQueue(7);
        file5.ajouterQueue(1);
        file5.ajouterQueue(9);
        file5.ajouterQueue(14);
        file5.ajouterQueue(4);

        file20.afficherFile();
        System.out.println("----------");
        file5.afficherFile();

        while (!file5.estVide() && !file20.estVide()) {
            int x = file5.retirerTete();
            System.out.println(x + " a ete supprime");
            x = file20.retirerTete();
            System.out.println(x + " a ete supprime");
        }

        System.out.println("----------");
        file20.afficherFile();
        System.out.println("La pile 20 contient : " + file20.compterNbElementsDeFile() + " elements");
        System.out.println("----------");
        file5.afficherFile();
        System.out.println("La pile 5 contient : " + file5.compterNbElementsDeFile() + " elements");

    }
}

