package tp4.exercice2.question2;


public class MainElementDeFile {
    public static void main(String[] args) {

        ElementDeFile fileA = new ElementDeFile(7);
        ElementDeFile fileB = new ElementDeFile(4);


        fileA = fileA.ajouterQueue(9);

        fileA = fileA.ajouterQueue(5);

        fileA = fileA.ajouterQueue(9);

        fileA = fileA.ajouterQueue(6);


        fileB = fileB.ajouterQueue(4);

        fileB = fileB.ajouterQueue(2);

        fileB = fileB.ajouterQueue(18);

        if (fileA != null) {
            fileA.afficherElementDeFile();

            System.out.println("La file A contient " + fileA.compterNbElementsDeFile() + " elements");
        }
        System.out.println("------------");
        if (fileB !=null) {
            fileB.afficherElementDeFile();
            System.out.println("La file B contient " + fileB.compterNbElementsDeFile() + " elements");
        }
        System.out.println("------------");

        while (fileA !=null & fileB!=null) {
            fileA = fileA.retirerTete();
            fileB = fileB.retirerTete();
        }
        if (fileA != null) {
            fileA.afficherElementDeFile();
            System.out.println("La file A contient " + fileA.compterNbElementsDeFile() + " elements");
            System.out.println("------------");
        }
        if (fileB !=null) {
            fileB.afficherElementDeFile();
            System.out.println("La file B contient " + fileB.compterNbElementsDeFile() + " elements");
            System.out.println("------------");
        }
    }
}
