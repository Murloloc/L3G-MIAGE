package tp6.exercice1;

public class CarteCouleurException extends CarteException {

    private static final String couleursAutorisees = "Pique = 1, Cœur = 2, Carreau = 3, Trèfle = 4";

    private int couleur;

    public CarteCouleurException(String message, int couleur ){
        this.message = message;
        this.couleur = couleur;
    }

    public CarteCouleurException(String message){
        this(message,0);
    }

    public String getMessage(){
        String chaine = this.message;
        if (!chaine.isEmpty()) {
            chaine += "\n";
        }
        chaine += "Erreur de couleur : " + this.couleur + "\n" + "Couleurs autorisées : " + CarteCouleurException.couleursAutorisees;
        return chaine;
    }
}
