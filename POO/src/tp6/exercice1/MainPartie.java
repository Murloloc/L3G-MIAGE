package tp6.exercice1;

public class MainPartie {
    public static void main(String[] args) {
        Belote partie = new Belote();
        try {
            partie.jouerPartie(4);
        } catch (CarteException ce){
            System.err.println("Erreur lors de la partie.");
            ce.printStackTrace(System.err);
        }

    }
}
