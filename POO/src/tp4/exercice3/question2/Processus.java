package tp4.exercice3.question2;

public class Processus {
    private static int nextIdentifiant = 0;
    private int identifiant;
    private int nbTachesAFaire;
    private int nbTachesEffectuees;

    public Processus(int arg) {
        this.identifiant = Processus.nextIdentifiant;
        Processus.nextIdentifiant++;
        this.nbTachesAFaire = arg;
        this.nbTachesEffectuees = 0;
    }

    public void executerTache() {
        this.nbTachesEffectuees++;
        afficherProcessus();
    }

    public boolean AFini() {
        return this.nbTachesEffectuees == this.nbTachesAFaire;
    }

    public void afficherProcessus() {
        System.out.println("Processus " + identifiant + " : " + nbTachesEffectuees + " sur " + nbTachesAFaire);
    }
}
