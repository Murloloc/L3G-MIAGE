package exo2_2;
public class Main{

public static void main(String[] args)
	{
		OperationsArithmetiquesWithMain opArith1 = new OperationsArithmetiquesWithMain();
		OperationsArithmetiquesWithMain opArith2 = new OperationsArithmetiquesWithMain();
		
		opArith1.setOperande1(14);
		opArith1.setOperande2(6);
		opArith2.setOperande1(4);
		opArith2.setOperande2(8);

		System.out.println("Resultat de l'addition entre" + opArith1.getOperande1() + "et" + opArith1.getOperande2() + "=" + opArith1.sommeOperandes());
		System.out.println("Resultat de la difference entre" + opArith1.getOperande1() + "et" + opArith1.getOperande2() + "=" + opArith1.diffOperandes());
		System.out.println("Resultat du produit entre" + opArith1.getOperande1() + "et" + opArith1.getOperande2() + "=" + opArith1.prodOperandes());
		System.out.println("Resultat de la division entre" + opArith1.getOperande1() + "et" + opArith1.getOperande2() + "=" + opArith1.divOperandes());

		System.out.println("Resultat de l'addition entre" + opArith2.getOperande1() + "et" + opArith2.getOperande2() + "=" + opArith2.sommeOperandes());
		System.out.println("Resultat de la difference entre" + opArith2.getOperande1() + "et" + opArith2.getOperande2() + "=" + opArith2.diffOperandes());
		System.out.println("Resultat du produit entre" + opArith2.getOperande1() + "et" + opArith2.getOperande2() + "=" + opArith2.prodOperandes());
		System.out.println("Resultat de la division entre" + opArith2.getOperande1() + "et" + opArith2.getOperande2() + "=" + opArith2.divOperandes());
}
}