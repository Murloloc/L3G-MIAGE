package exo2_5;

public class MainWithEquals{
	public static void main(String[] args)
	{
		OperationsArithmetiquesWithEquals opArith1 = new OperationsArithmetiquesWithEquals(5);
		OperationsArithmetiquesWithEquals opArith2 = new OperationsArithmetiquesWithEquals(5);
		

		System.out.println("Resultat de l'addition entre " + opArith1.getOperande1() + " et " + opArith1.getOperande2() + " = " + opArith1.sommeOperandes());
		System.out.println("Resultat de la difference entre " + opArith1.getOperande1() + " et " + opArith1.getOperande2() + " = " + opArith1.diffOperandes());
		System.out.println("Resultat du produit entre " + opArith1.getOperande1() + " et " + opArith1.getOperande2() + " = " + opArith1.prodOperandes());
		System.out.println("Resultat de la division entre " + opArith1.getOperande1() + " et " + opArith1.getOperande2() + " = " + opArith1.divOperandes());

		System.out.println("Resultat de l'addition entre " + opArith2.getOperande1() + " et " + opArith2.getOperande2() + " = " + opArith2.sommeOperandes());
		System.out.println("Resultat de la difference entre " + opArith2.getOperande1() + " et " + opArith2.getOperande2() + " = " + opArith2.diffOperandes());
		System.out.println("Resultat du produit entre " + opArith2.getOperande1() + " et " + opArith2.getOperande2() + " = " + opArith2.prodOperandes());
		System.out.println("Resultat de la division entre " + opArith2.getOperande1() + " et " + opArith2.getOperande2() + " = " + opArith2.divOperandes());

		//System.out.println(opArith1==opArith2);
		//System.out.println(opArith1.equals(opArith2)); false sans la redef de equals
		
		System.out.println(opArith1.equals(opArith2));
}
}