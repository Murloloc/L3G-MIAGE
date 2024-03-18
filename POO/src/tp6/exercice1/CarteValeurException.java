package tp6.exercice1;

public class CarteValeurException extends CarteException {

    private static final String valeursAutorisees = "As = 1, 7 à 10 = leur valeur, Valet = 11, Dame = 12, Roi = 13";

    private int valeur;

    public CarteValeurException(String message, int valeur) {
        this.message = message;
        this.valeur = valeur;
    }

    public CarteValeurException(String message) {
        this(message, 0);
    }

    public String getMessage() {
        String chaine = this.message;
        if (!chaine.isEmpty()) {
            chaine += "\n";
        }
        chaine += "Erreur de valeur : " + this.valeur + "\n" + "Valeurs autorisées : " + CarteValeurException.valeursAutorisees;
        return chaine;
    }
}
