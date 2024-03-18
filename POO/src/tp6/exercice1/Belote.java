package tp6.exercice1;

import java.util.Random;
import java.util.Stack;
import java.util.Vector;

public class Belote {
    private Stack<Carte> tasDistribution;
    private Vector<Stack<Carte>> mainsJoueurs;
    private Vector<Stack<Carte>> plisJoueurs;

    public Belote() {
        this.tasDistribution = new Stack<Carte>();
        this.mainsJoueurs = new Vector<Stack<Carte>>(4);
        this.plisJoueurs = new Vector<Stack<Carte>>(4);
        for (int i = 0; i < 4; i++) {
            this.mainsJoueurs.add(new Stack<Carte>());
            this.plisJoueurs.add(new Stack<Carte>());
        }
    }

    private void initialiserTasDistribution() throws CarteException {
        try {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 14; j++) {
                    if (j == 1 || (j >= 7 && j <= 13)) {
                        Carte nouveau = new Carte(i, j);
                        this.tasDistribution.push(nouveau);
                    }
                }
            }
        } catch (CarteException ce) {
            System.err.println(ce.getMessage());
            throw new CarteException();
        }
        System.out.println(this.tasDistribution);
    }

    private void couper() {
        Stack<Carte> tas1 = new Stack<Carte>();
        Stack<Carte> tas2 = new Stack<Carte>();
        Carte carte;
        Random random = new Random();
        int nbAleat = random.nextInt(31) + 1;
        for (int i = 1; i <= nbAleat; i++) {
            carte = tasDistribution.pop();
            tas1.push(carte);
        }
        while (!this.tasDistribution.empty()) {
            carte = tasDistribution.pop();
            tas2.push(carte);
        }
        while (!tas1.empty()) {
            carte = tas1.pop();
            tasDistribution.push(carte);
        }
        while (!tas2.empty()) {
            carte = tas2.pop();
            tasDistribution.push(carte);
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
            carte = this.tasDistribution.pop();
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
            this.tasDistribution.push(ech);
        }
    }

    private void donnerCartesAJoueur(int nbCarte, int numJoueur) {
        Carte carte;
        for (int i = 0; i < nbCarte; i++) {
            carte = tasDistribution.pop();
            mainsJoueurs.set(numJoueur, mainsJoueurs.get(numJoueur)).push(carte);
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
            System.out.println(mainsJoueurs.get(i));
        }
    }

    private void assemblerPlisJoueurs() {
        Carte carte;
        for (int i = 0; i < 4; i++) {
            while (!plisJoueurs.get(i).empty()) {
                carte = plisJoueurs.get(i).pop();
                tasDistribution.push(carte);
            }
        }
    }

    private void preparerPremiereManche() throws CarteException {
        try {
            initialiserTasDistribution();
        } catch (CarteException ce) {
            System.err.println("Erreur d'initialisation du tas à distribuer");
            throw new CarteException();
        }
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
        Stack<Carte> tasInter = new Stack<Carte>();
        Carte carte;
        Random random = new Random();
        for (int i = 0; i < 4; i++) {
            carte = mainsJoueurs.get(i).pop();
            tasInter.push(carte);
        }
        int joueurAleat = random.nextInt(4);
        for (int i = 0; i < 4; i++) {
            carte = tasInter.pop();
            plisJoueurs.set(joueurAleat, plisJoueurs.get(joueurAleat)).push(carte);
        }
        for (int i = 0; i < 4; i++) {
            System.out.println("-----------");
            System.out.println("Pli du joueur " + (i + 1) + " :");
            System.out.println(plisJoueurs.get(i));
        }
    }

    private void jouerManche(int numManche) {
        for (int i = 0; i < 8; i++) {
            jouerPli();
        }
        preparerMancheSuivante();
    }

    public void jouerPartie(int nbManche) throws CarteException {
        try {
            preparerPremiereManche();
        } catch (CarteException ce) {
            System.err.println("Erreur d'initialisation de la première manche");
            throw new CarteException();
        }

        for (int i = 0; i < nbManche; i++) {
            jouerManche(i);
        }
    }
}