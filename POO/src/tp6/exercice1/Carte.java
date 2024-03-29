package tp6.exercice1;

public class Carte {
    public int couleur;
    public int valeur;

    public Carte(int color, int value) throws CarteException {
        if (color < 0 || color > 3) {
            throw new CarteCouleurException("Erreur d'initialisation lors de la création d'une carte.", color);
        } else if (value < 1 || (value >= 2 && value <= 6) || value > 13) {
            throw new CarteValeurException("Erreur d'initialisation lors de la création d'une carte.", value);
        } else {
            this.couleur = color;
            this.valeur = value;
        }
    }

    public String toString() {
        String col;
        switch (this.couleur) {
            case 0:
                col = "Pique";
                break;
            case 1:
                col = "Coeur";
                break;
            case 2:
                col = "Carreau";
                break;
            case 3:
                col = "Trefle";
                break;
            default:
                col = "Erreur";
        }
        String val;
        switch (this.valeur) {
            case 1:
                val = "As";
                break;
            case 7:
                val = "7";
                break;
            case 8:
                val = "8";
                break;
            case 9:
                val = "9";
                break;
            case 10:
                val = "10";
                break;
            case 11:
                val = "Valet";
                break;
            case 12:
                val = "Dame";
                break;
            case 13:
                val = "Roi";
                break;
            default:
                val = "Erreur";
        }
        return (val + " de " + col);
    }

    public void afficherCarte() {
        System.out.println(this.toString());
    }
}

