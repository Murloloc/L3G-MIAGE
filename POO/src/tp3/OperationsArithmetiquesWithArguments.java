package tp3;
public class OperationsArithmetiquesWithArguments implements Cloneable
{

	private double operande1;
	private double operande2;
	private static int nbOperations;

	public double getOperande1()
	{return(this.operande1);}

	public double getOperande2()
	{return(this.operande2);}

	public static int getnbOperations()
	{return(OperationsArithmetiquesWithArguments.nbOperations);}

	public void setOperande1(double op)
	{this.operande1=op;}

	public void setOperande2(double op)
	{this.operande2=op;}
	
	public double sommeOperandes() {
	OperationsArithmetiquesWithArguments.nbOperations++;
	return(this.operande1 + this.operande2);
	}
	
	public double diffOperandes() {
	OperationsArithmetiquesWithArguments.nbOperations++;
	return(this.operande1 - this.operande2);
	}

	public double prodOperandes() {
	OperationsArithmetiquesWithArguments.nbOperations++;
	return(this.operande1 * this.operande2);
	}

	public double divOperandes() {
	OperationsArithmetiquesWithArguments.nbOperations++;
	return(this.operande1 / this.operande2);
	}

	public OperationsArithmetiquesWithArguments()
	{this(0,0);}
	public OperationsArithmetiquesWithArguments(double op)
	{this(op,0);}
	public OperationsArithmetiquesWithArguments(double op1, double op2)
	{this.operande1=op1; this.operande2=op2;}

    public boolean equals(Object obj){
		if ((obj == null)||(this.getClass() != obj.getClass()))
			return(false);
		else
		if (this == obj) return(true);
		else
		{
			OperationsArithmetiquesWithArguments aTester = (OperationsArithmetiquesWithArguments) obj;
			return(this.operande1 == aTester.operande1);
		}
	}
	public String toString() {
		return (" op1 = " + this.operande1 + "/ op2 = " );
	}
	
	public Object clonage ()throws CloneNotSupportedException
	{
		return ((OperationsArithmetiquesWithArguments)this.clone());
	}
}