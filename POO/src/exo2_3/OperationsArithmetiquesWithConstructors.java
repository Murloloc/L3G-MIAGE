package exo2_3;
public class OperationsArithmetiquesWithConstructors
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

	public OperationsArithmetiquesWithConstructors()
	{this(0,0);}

	public OperationsArithmetiquesWithConstructors(double op)
	{this(op,0);}

	public OperationsArithmetiquesWithConstructors(double op1, double op2)
	{this.operande1=op1; this.operande2=op2;}
}