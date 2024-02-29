package tp4.exercice3.question1;

import java.util.Random;

public class Belote {
    private ElementDeTas tasDistribution;
    private ElementDeTas[] mainsJoueurs;
    private ElementDeTas[] plisJoueurs;

    public Belote() {
        this.tasDistribution = ElementDeTas.creerTasVide();
        this.mainsJoueurs = new ElementDeTas[4];
        for (int i = 0; i < 4; i++) {
            this.mainsJoueurs[i] = ElementDeTas.creerTasVide();
        }
        this.plisJoueurs = new ElementDeTas[4];
        for (int i = 0; i < 4; i++) {
            this.plisJoueurs[i] = ElementDeTas.creerTasVide();
        }
    }

    private void initialiserTasDistribution() {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 14; j++) {
                if (j == 1 || (j >= 7 && j <= 13)) {
                    Carte nouveau = new Carte(i, j);
                    tasDistribution = tasDistribution.empiler(nouveau);
                }
            }
        }
        tasDistribution.afficherElementDeTas();
    }

    private void couper() {
        ElementDeTas tas1 = ElementDeTas.creerTasVide();
        ElementDeTas tas2 = ElementDeTas.creerTasVide();
        Carte carte;
        Random random = new Random();
        int nbAleat = random.nextInt(31) + 1;
        for (int i = 1; i <= nbAleat; i++) {
            carte = tasDistribution.getCarte();
            tasDistribution = tasDistribution.depiler();
            tas1 = tas1.empiler(carte);
        }
        while (!tasDistribution.estVide()) {
            carte = tasDistribution.getCarte();
            tasDistribution = tasDistribution.depiler();
            tas2 = tas2.empiler(carte);
        }
        while (!tas1.estVide()) {
            carte = tas1.getCarte();
            tas1 = tas1.depiler();
            tasDistribution = tasDistribution.empiler(carte);
        }
        while (!tas2.estVide()) {
            carte = tas2.getCarte();
            tas2 = tas2.depiler();
            tasDistribution = tasDistribution.empiler(carte);
        }
    }

    private void melanger(int valeur) {
        Carte[] tab = new Carte[32];
        Carte carte;
        Random random = new Random();
        int nbAleat1 = 0;
        int nbAleat2 = 0;
        Carte ech;
        for (int i = 0; i < 32; i++) {
            carte = tasDistribution.getCarte();
            tasDistribution = tasDistribution.depiler();
            tab[i] = carte;
        }
        for (int i = 0; i < valeur; i++) {
            for (int j = 0; j < 32; j++) {
                while ((nbAleat1 = random.nextInt(31)) == (nbAleat2 = random.nextInt(31))) {
                }
                ech = tab[nbAleat1];
                tab[nbAleat1] = tab[nbAleat2];
                tab[nbAleat2] = ech;
            }
        }
        for (int i = 0; i < 32; i++) {
            ech = tab[i];
            tasDistribution = tasDistribution.empiler(ech);
        }
    }

    private void donnerCartesAJoueur(int nbCarte, int numJoueur) {
        Carte carte;
        for (int i = 0; i < nbCarte; i++) {
            carte = tasDistribution.getCarte();
            tasDistribution = tasDistribution.depiler();
            mainsJoueurs[numJoueur] = mainsJoueurs[numJoueur].empiler(carte);
        }
    }

    private void distribuer() {
        for (int i = 0; i < 4; i++) {
            donnerCartesAJoueur(3, i);
        }
        for (int i = 0; i < 4; i++) {
            donnerCartesAJoueur(2, i);
        }
        for (int i = 0; i < 4; i++) {
            donnerCartesAJoueur(3, i);
            System.out.println("------------");
            System.out.println("Main du joueur " + (i + 1) + " : ");
            mainsJoueurs[i].afficherElementDeTas();
        }
    }

    private void assemblerPlisJoueurs() {
        Carte carte;
        for (int i = 0; i < 4; i++) {
            while (!plisJoueurs[i].estVide()) {
                carte = plisJoueurs[i].getCarte();
                plisJoueurs[i] = plisJoueurs[i].depiler();
                tasDistribution = tasDistribution.empiler(carte);
            }
        }
    }

    private void preparerPremiereManche() {
        initialiserTasDistribution();
        melanger(2);
        couper();
        distribuer();

    }

    private void preparerMancheSuivante() {
        assemblerPlisJoueurs();
        couper();
        distribuer();
    }

    private void jouerPli() {
        ElementDeTas tasInter = ElementDeTas.creerTasVide();
        Carte carte;
        Random random = new Random();
        for (int i = 0; i < 4; i++) {
            carte = mainsJoueurs[i].getCarte();
            mainsJoueurs[i] = mainsJoueurs[i].depiler();
            tasInter = tasInter.empiler(carte);
        }
        int joueurAleat = random.nextInt(4);
        for (int i = 0; i < 4; i++) {
            carte = tasInter.getCarte();
            tasInter = tasInter.depiler();
            plisJoueurs[joueurAleat] = plisJoueurs[joueurAleat].empiler(carte);
            System.out.println("-----------");
            System.out.println("Pli du joueur " + (i + 1) + " :");
            plisJoueurs[i].afficherElementDeTas();

        }
    }

    private void jouerManche(int numManche) {
        for (int i = 0; i < 8; i++) {
            jouerPli();
        }
        preparerMancheSuivante();
    }

    public void jouerPartie(int nbManche) {
        preparerPremiereManche();
        for (int i = 0; i < nbManche; i++) {
            jouerManche(i);
        }
    }
}
