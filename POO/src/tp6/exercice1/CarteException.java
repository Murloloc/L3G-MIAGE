package tp6.exercice1;

public class CarteException extends Exception {

    protected String message;

    public CarteException(String message) {
        this.message = message;
    }

    protected CarteException() {
        this("");
    }

    public String getMessage() {
        String chaine = this.message;
        if (!chaine.isEmpty()) {
            chaine += "\n";
        }
        chaine += "Erreur non spécifiée de valeur ou de couleur de carte.";
        return chaine;
    }
}
