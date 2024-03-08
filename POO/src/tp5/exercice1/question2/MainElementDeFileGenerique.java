package tp5.exercice1.question2;


public class MainElementDeFileGenerique {
    public static void main(String[] args) {
        //Creation de 2 files
        ElementDeFileGenerique<Integer> fileA = ElementDeFileGenerique.<Integer>creerFileVide();
        ElementDeFileGenerique<Integer> fileB = ElementDeFileGenerique.<Integer>creerFileVide();

        //Affichage de chacune des files (normalement vides).
        System.out.println("Affichage des files après initialisation :");
        System.out.println("------------------------------------------");
        System.out.println("Contenu de la fileA : actuellement " + fileA.compterNbElementsDeFileGenerique() + " elements.");
        fileA.afficherElementDeFileGenerique();
        System.out.println("Contenu de la fileB : actuellement " + fileB.compterNbElementsDeFileGenerique() + " elements.");
        fileB.afficherElementDeFileGenerique();

        //Ajout de nouvelles valeurs en queue des files
        for (int cpt = 1; cpt < 10; cpt++) {
            fileA = fileA.ajouterQueue(cpt);
            fileB = fileB.ajouterQueue(cpt);
        }

        //Affichage de chacune des files (maintenant non-vides).
        System.out.println("---------------------------------------------");
        System.out.println("Affichage des files après ajouts d'elements :");
        System.out.println("---------------------------------------------");
        System.out.println("Contenu de la fileA : actuellement " + fileA.compterNbElementsDeFileGenerique() + " elements.");
        fileA.afficherElementDeFileGenerique();
        System.out.println("Contenu de la fileB : actuellement " + fileB.compterNbElementsDeFileGenerique() + " elements.");
        fileB.afficherElementDeFileGenerique();

        //Suppression d'elements depuis la tête
        while ((fileA.compterNbElementsDeFileGenerique() >= 2) && (fileB.compterNbElementsDeFileGenerique() >= 1)) {
            System.out.println("Valeur ôtee en tête de fileA : " + fileA.getDonnee());
            fileA = fileA.retirerTete();
            System.out.println("Valeur ôtee en tête de fileB : " + fileB.getDonnee());
            fileB = fileB.retirerTete();
        }

        //Affichage de chacune des files.
        System.out.println("----------------------------------------");
        System.out.println("Affichage des files après suppressions :");
        System.out.println("----------------------------------------");
        System.out.println("Contenu de la fileA : actuellement " + fileA.compterNbElementsDeFileGenerique() + " elements.");
        fileA.afficherElementDeFileGenerique();
        System.out.println("Contenu de la fileB : actuellement " + fileB.compterNbElementsDeFileGenerique() + " elements.");
        fileB.afficherElementDeFileGenerique();
    }
}
