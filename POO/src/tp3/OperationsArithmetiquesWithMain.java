package tp3;
public class OperationsArithmetiquesWithMain
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
}