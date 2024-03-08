package tp4.exercice2.question3;

public class MainElementDeFileEvoluee {
    public static void main(String[] args){
        //Creation de 2 files
        ElementDeFileEvoluee fileA = ElementDeFileEvoluee.creerFileVide();
        ElementDeFileEvoluee fileB = ElementDeFileEvoluee.creerFileVide();

        //Affichage de chacune des files (normalement vides).
        System.out.println("Affichage des files après initialisation :");
        System.out.println("------------------------------------------");
        System.out.println("Contenu de la fileA : actuellement " + fileA.compterNbElementsDeFileEvoluee() + " elements.");
        fileA.afficherElementDeFileEvoluee();
        System.out.println("Contenu de la fileB : actuellement " + fileB.compterNbElementsDeFileEvoluee() + " elements.");
        fileB.afficherElementDeFileEvoluee();

        //Ajout de nouvelles valeurs en queue des files
        for(int cpt = 1; cpt < 10; cpt++)
        {
            fileA = fileA.ajouterQueue(cpt);
            fileB = fileB.ajouterQueue(cpt);
        }

        //Affichage de chacune des files (maintenant non-vides).
        System.out.println("---------------------------------------------");
        System.out.println("Affichage des files après ajouts d'elements :");
        System.out.println("---------------------------------------------");
        System.out.println("Contenu de la fileA : actuellement " + fileA.compterNbElementsDeFileEvoluee() + " elements.");
        fileA.afficherElementDeFileEvoluee();
        System.out.println("Contenu de la fileB : actuellement " + fileB.compterNbElementsDeFileEvoluee() + " elements.");
        fileB.afficherElementDeFileEvoluee();

        //Suppression d'elements depuis la tête
        while ((fileA.compterNbElementsDeFileEvoluee() >= 2) && (fileB.compterNbElementsDeFileEvoluee() >= 1))
        {
            System.out.println("Valeur ôtee en tête de fileA : " + fileA.getDonnee());
            fileA = fileA.retirerTete();
            System.out.println("Valeur ôtee en tête de fileB : " + fileB.getDonnee());
            fileB = fileB.retirerTete();
        }

        //Affichage de chacune des files.
        System.out.println("----------------------------------------");
        System.out.println("Affichage des files après suppressions :");
        System.out.println("----------------------------------------");
        System.out.println("Contenu de la fileA : actuellement " + fileA.compterNbElementsDeFileEvoluee() + " elements.");
        fileA.afficherElementDeFileEvoluee();
        System.out.println("Contenu de la fileB : actuellement " + fileB.compterNbElementsDeFileEvoluee() + " elements.");
        fileB.afficherElementDeFileEvoluee();
    }
}

