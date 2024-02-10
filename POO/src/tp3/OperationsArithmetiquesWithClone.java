package tp3;
public class OperationsArithmetiquesWithClone implements Cloneable
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
	public OperationsArithmetiquesWithClone()
	{this(0,0);}
	public OperationsArithmetiquesWithClone(double op)
	{this(op,0);}
	public OperationsArithmetiquesWithClone(double op1, double op2)
	{this.operande1=op1; this.operande2=op2;}

    public boolean equals(Object obj){
		if ((obj == null)||(this.getClass() != obj.getClass()))
			return(false);
		else
		if (this == obj) return(true);
		else
		{
			OperationsArithmetiquesWithClone aTester = (OperationsArithmetiquesWithClone) obj;
			return(this.operande1 == aTester.operande1);
		}
	}
	public String toString() {
		return (" op1 = " + this.operande1 + "/ op2 = " + this.operande2);
	}

	public Object clonage ()throws CloneNotSupportedException
	{
		return ((OperationsArithmetiquesWithClone)this.clone());
	}
}