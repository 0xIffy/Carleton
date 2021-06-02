public class Employee extends Person{
  double weeklyBaseSalary;
  double totalPaid;
  double totalTaxed;
  
  public Employee(String iName, int iAge, double baseSal){
    super(iName, iAge);
    this.weeklyBaseSalary = baseSal;
  }
  
  /*
   * Should update the total amount paid/taxed for this employee. 
   * Taxes should be 10% of the weekly base salary for employees under the age of 30 
   * and 15% for employees aged 30 or older. 
   * The total paid to the employee should be the amount remaining after taxes are paid
   */
  public void pay(){
    double tax;
    if(this.getAge()<30){
      tax=weeklyBaseSalary*0.1;
    }
    else{
      tax=weeklyBaseSalary*0.15;
    }
    totalTaxed+=tax;
    totalPaid=weeklyBaseSalary-tax;
  }
  
  /*
   * Should return a String representing the employee�s pay cheque. 
   * The pay cheque must contain the following information: the employee�s name and age, 
   * the weekly base salary, the amount paid in taxes, the amount paid to the employee.
   */
  public String makePaycheque(){
    //Code here
    return ""; //only included so code will compile
  }
  
  //Add any additional methods you require here
}