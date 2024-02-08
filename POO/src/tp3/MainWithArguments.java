package tp3;
public class MainWithArguments{
	public static void main(String[] args) throws CloneNotSupportedException
	{

		
			
		double arg0 = Double.parseDouble(args[0]);
		double arg1 = Double.parseDouble(args[1]);
		
		
		OperationsArithmetiquesWithArguments opArith1 = new OperationsArithmetiquesWithArguments(arg0,arg1);
		OperationsArithmetiquesWithArguments opArith2 = new OperationsArithmetiquesWithArguments(arg0,arg1);
		
		if(args.length==2){
		
		System.out.println("Il y a "+OperationsArithmetiquesWithArguments.getnbOperations()+" operations");

		System.out.println("Resultat de l'addition entre " + opArith1.getOperande1() + " et " + opArith1.getOperande2() + " = " + opArith1.sommeOperandes());
		System.out.println("Resultat de la difference entre " + opArith1.getOperande1() + " et " + opArith1.getOperande2() + " = " + opArith1.diffOperandes());
		System.out.println("Resultat du produit entre " + opArith1.getOperande1() + " et " + opArith1.getOperande2() + " = " + opArith1.prodOperandes());
		System.out.println("Resultat de la division entre " + opArith1.getOperande1() + " et " + opArith1.getOperande2() + " = " + opArith1.divOperandes());

		System.out.println("Resultat de l'addition entre " + opArith2.getOperande1() + " et " + opArith2.getOperande2() + " = " + opArith2.sommeOperandes());
		System.out.println("Resultat de la difference entre " + opArith2.getOperande1() + " et " + opArith2.getOperande2() + " = " + opArith2.diffOperandes());
		System.out.println("Resultat du produit entre " + opArith2.getOperande1() + " et " + opArith2.getOperande2() + " = " + opArith2.prodOperandes());
		System.out.println("Resultat de la division entre " + opArith2.getOperande1() + " et " + opArith2.getOperande2() + " = " + opArith2.divOperandes());

		System.out.println("Il y a "+OperationsArithmetiquesWithArguments.getnbOperations()+" operations");
		}
		else{System.out.println("Mauvais nombre d'argument");}
		
}
}