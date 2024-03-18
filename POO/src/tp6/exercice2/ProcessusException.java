package tp6.exercice2;

public class ProcessusException extends Exception {

    private static final String nbTachesAutorises = "Le nombre de tâches à exécuter par un processus doit être strictement positif";
    private String message;
    private int nbTaches;

    public ProcessusException(String message, int nbTaches) {
        this.message = message;
        this.nbTaches = nbTaches;
    }

    public ProcessusException(int nbTaches) {
        this("", nbTaches);
    }

    public String getMessage() {
        String chaine = this.message;
        if (!chaine.isEmpty()) {
            chaine += "\n";
        }
        chaine += ProcessusException.nbTachesAutorises + "\n" + "Nombre de tâches demandées : " + this.nbTaches;
        return chaine;
    }
}
