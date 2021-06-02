public class Customer{
  double money;
  
  public Customer(){
    this(0.0);
  }
  
  public Customer(double initMoney){
    money = initMoney;
  }
  
  public double getMoney(){
    return money;
  }
  
  public void setMoney(double newMoney){
    money = newMoney;
  }
}