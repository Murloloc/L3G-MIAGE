package tp3;

public class MainWithClone{
	public static void main(String[] args) throws CloneNotSupportedException
	{
		OperationsArithmetiquesWithClone opArith1 = new OperationsArithmetiquesWithClone(5,14);
		OperationsArithmetiquesWithClone opArith2 = new OperationsArithmetiquesWithClone(3,17);
		

		System.out.println("Resultat de l'addition entre " + opArith1.getOperande1() + " et " + opArith1.getOperande2() + " = " + opArith1.sommeOperandes());
		System.out.println("Resultat de la difference entre " + opArith1.getOperande1() + " et " + opArith1.getOperande2() + " = " + opArith1.diffOperandes());
		System.out.println("Resultat du produit entre " + opArith1.getOperande1() + " et " + opArith1.getOperande2() + " = " + opArith1.prodOperandes());
		System.out.println("Resultat de la division entre " + opArith1.getOperande1() + " et " + opArith1.getOperande2() + " = " + opArith1.divOperandes());

		System.out.println("Resultat de l'addition entre " + opArith2.getOperande1() + " et " + opArith2.getOperande2() + " = " + opArith2.sommeOperandes());
		System.out.println("Resultat de la difference entre " + opArith2.getOperande1() + " et " + opArith2.getOperande2() + " = " + opArith2.diffOperandes());
		System.out.println("Resultat du produit entre " + opArith2.getOperande1() + " et " + opArith2.getOperande2() + " = " + opArith2.prodOperandes());
		System.out.println("Resultat de la division entre " + opArith2.getOperande1() + " et " + opArith2.getOperande2() + " = " + opArith2.divOperandes());

		System.out.println("avant: opArith1("+opArith1+")/ opArith2 (" +opArith2+")");

		opArith1 = (OperationsArithmetiquesWithClone)opArith2.clonage();

		System.out.println("apres: opArith1("+opArith1+")/ opArith2 (" +opArith2+")");
		
}
}