package tp2.exo2_1;
public class OperationsArithmetiques
{

	public double getOperande1()
	{return(this.operande1);}

	public double getOperande2()
	{return(this.operande2);}

	public void setOperande1(double op)
	{this.operande1=op;}

	public void setOperande2(double op)
	{this.operande2=op;}


	private double operande1;
	private double operande2;
	
	public double sommeOperandes() 
	{return(this.operande1 + this.operande2);}

	public double diffOperandes() 
	{return(this.operande1 - this.operande2);}

	public double prodOperandes() 
	{return(this.operande1 * this.operande2);}

	public double divOperandes() 
	{return(this.operande1 / this.operande2);}

	public static void main(String[] args)
	{
		OperationsArithmetiques opArith1 = new OperationsArithmetiques();
		OperationsArithmetiques opArith2 = new OperationsArithmetiques();
		
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