package exo2_6;
public class OperationsArithmetiquesWithToString
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
	public OperationsArithmetiquesWithToString()
	{this(0,0);}
	public OperationsArithmetiquesWithToString(double op)
	{this(op,0);}
	public OperationsArithmetiquesWithToString(double op1, double op2)
	{this.operande1=op1; this.operande2=op2;}

    public boolean equals(Object obj){
		if ((obj == null)||(this.getClass() != obj.getClass()))
			return(false);
		else
		if (this == obj) return(true);
		else
		{
			OperationsArithmetiquesWithToString aTester = (OperationsArithmetiquesWithToString) obj;
			return(this.operande1 == aTester.operande1);
		}
	}
	
	public String toString(){
		return ("Objet correctement affiché : operande 1 = "+this.operande1+" / operande 2 = "+this.operande2);
	}
}