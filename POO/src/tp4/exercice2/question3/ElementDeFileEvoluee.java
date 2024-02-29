package tp4.exercice2.question3;


public class ElementDeFileEvoluee
{
    private Integer donnee;
    private ElementDeFileEvoluee suivant = null;

    //Constructeurs
    private ElementDeFileEvoluee()
    {
        this(null);
    }

    public ElementDeFileEvoluee(Integer donnee)
    {
        this.donnee = donnee;
        this.suivant = null;
    }

    //Creation de file vide
    public static ElementDeFileEvoluee creerFileVide()
    {
        return(new ElementDeFileEvoluee());
    }

    //Test file vide
    public boolean estVide()
    {
        return(this.donnee == null);
    }

    //Ajout d'un element en queue de file
    public ElementDeFileEvoluee ajouterQueue(Integer donnee)
    {
        if(this.estVide())
        {
            ElementDeFileEvoluee nouveau = new ElementDeFileEvoluee(donnee);

            nouveau.suivant = this;
            return(nouveau);
        }
        else
            return(this.suivant.ajouterQueue(donnee));
    }

    //Suppression d'un element en tête de file
    public ElementDeFileEvoluee retirerTete()
    {
        if(!this.estVide())
            return(this.suivant);
        else
            return(this);
    }

    //Affichage de la file
    public void afficherElementDeFile()
    {
        if(!this.estVide())
        {
            System.out.println("Element courant : " + this.donnee.intValue());
            this.suivant.afficherElementDeFile();
        }
    }

    //Comptage du nombre d'elements dans la file
    public int compterNbElementsDeFile()
    {
        if(this.estVide())
            return(0);
        else
            return(1 + this.suivant.compterNbElementsDeFile());
    }

    //Assesseur
    public Integer getDonnee()
    {
        return(this.donnee);
    }
}