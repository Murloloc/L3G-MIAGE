package tp2.exo2_6;
public class MainWithToString{
	public static void main(String[] args)
	{
		OperationsArithmetiquesWithToString opArith1 = new OperationsArithmetiquesWithToString(5);
		OperationsArithmetiquesWithToString opArith2 = new OperationsArithmetiquesWithToString(5);
		

		System.out.println("Resultat de l'addition entre " + opArith1.getOperande1() + " et " + opArith1.getOperande2() + " = " + opArith1.sommeOperandes());
		System.out.println("Resultat de la difference entre " + opArith1.getOperande1() + " et " + opArith1.getOperande2() + " = " + opArith1.diffOperandes());
		System.out.println("Resultat du produit entre " + opArith1.getOperande1() + " et " + opArith1.getOperande2() + " = " + opArith1.prodOperandes());
		System.out.println("Resultat de la division entre " + opArith1.getOperande1() + " et " + opArith1.getOperande2() + " = " + opArith1.divOperandes());

		System.out.println("Resultat de l'addition entre " + opArith2.getOperande1() + " et " + opArith2.getOperande2() + " = " + opArith2.sommeOperandes());
		System.out.println("Resultat de la difference entre " + opArith2.getOperande1() + " et " + opArith2.getOperande2() + " = " + opArith2.diffOperandes());
		System.out.println("Resultat du produit entre " + opArith2.getOperande1() + " et " + opArith2.getOperande2() + " = " + opArith2.prodOperandes());
		System.out.println("Resultat de la division entre " + opArith2.getOperande1() + " et " + opArith2.getOperande2() + " = " + opArith2.divOperandes());
		
		System.out.println(opArith1.equals(opArith2));
		
		System.out.println(opArith1);

		
}
}