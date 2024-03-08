package tp5.exercice1.question3;

import tp5.exercice1.question1.ElementDePileGenerique;

import java.util.Random;
import java.util.Vector;

public class Belote {
    private ElementDePileGenerique<Carte> tasDistribution;
    private Vector<ElementDePileGenerique<Carte>> mainsJoueurs;
    private Vector<ElementDePileGenerique<Carte>> plisJoueurs;

    public Belote() {
        this.tasDistribution = ElementDePileGenerique.<Carte>creerPileVide();
        this.mainsJoueurs = new Vector<ElementDePileGenerique<Carte>>(4);
        this.plisJoueurs = new Vector<ElementDePileGenerique<Carte>>(4);
        for (int i = 0; i < 4; i++) {
            this.mainsJoueurs.add(ElementDePileGenerique.<Carte>creerPileVide());
            this.plisJoueurs.add(ElementDePileGenerique.<Carte>creerPileVide());
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
        tasDistribution.afficherElementDePileGenerique();
    }

    private void couper() {
        ElementDePileGenerique<Carte> tas1 = ElementDePileGenerique.<Carte>creerPileVide();
        ElementDePileGenerique<Carte> tas2 = ElementDePileGenerique.<Carte>creerPileVide();
        Carte carte;
        Random random = new Random();
        int nbAleat = random.nextInt(31) + 1;
        for (int i = 1; i <= nbAleat; i++) {
            carte = tasDistribution.getDonnee();
            tasDistribution = tasDistribution.depiler();
            tas1 = tas1.empiler(carte);
        }
        while (!tasDistribution.estVide()) {
            carte = tasDistribution.getDonnee();
            tasDistribution = tasDistribution.depiler();
            tas2 = tas2.empiler(carte);
        }
        while (!tas1.estVide()) {
            carte = tas1.getDonnee();
            tas1 = tas1.depiler();
            tasDistribution = tasDistribution.empiler(carte);
        }
        while (!tas2.estVide()) {
            carte = tas2.getDonnee();
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
            carte = tasDistribution.getDonnee();
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
            carte = tasDistribution.getDonnee();
            tasDistribution = tasDistribution.depiler();
            mainsJoueurs.set(numJoueur, mainsJoueurs.get(numJoueur).empiler(carte));
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
            mainsJoueurs.get(i).afficherElementDePileGenerique();
        }
    }

    private void assemblerPlisJoueurs() {
        Carte carte;
        for (int i = 0; i < 4; i++) {
            while (!plisJoueurs.get(i).estVide()) {
                carte = plisJoueurs.get(i).getDonnee();
                plisJoueurs.set(i, plisJoueurs.get(i).depiler());
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
        ElementDePileGenerique<Carte> tasInter = ElementDePileGenerique.<Carte>creerPileVide();
        Carte carte;
        Random random = new Random();
        for (int i = 0; i < 4; i++) {
            carte = mainsJoueurs.get(i).getDonnee();
            mainsJoueurs.set(i, mainsJoueurs.get(i).depiler());
            tasInter = tasInter.empiler(carte);
        }
        int joueurAleat = random.nextInt(4);
        for (int i = 0; i < 4; i++) {
            carte = tasInter.getDonnee();
            tasInter = tasInter.depiler();
            plisJoueurs.set(joueurAleat, plisJoueurs.get(joueurAleat).empiler(carte));
        }
        for (int i = 0; i < 4; i++) {
            System.out.println("-----------");
            System.out.println("Pli du joueur " + (i + 1) + " :");
            plisJoueurs.get(i).afficherElementDePileGenerique();
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
