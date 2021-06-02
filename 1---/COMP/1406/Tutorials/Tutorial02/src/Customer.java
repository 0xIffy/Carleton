public class Customer {
    String name;
    int age;
    float money;
    boolean admitted;

    public Customer() {
        this("Default Customer",0,0.0f);
    }
    public Customer(String dName) {
        this(dName,0,0.0f);
    }

    public Customer(String dName, int dAge) {
        this(dName,dAge,0.0f);
    }

    public Customer(String dName, int dAge, float dMoney) {
        this.name = dName;
        this.age = dAge;
        this.money = dMoney;
        this.admitted = false;
    }

    public float computeFee(){
        float fee = 0;

        if(this.age >= 0 && this.age <= 3){
            fee = 0;
        } else if(this.age < 18){
            fee = 8.50f;
        } else if(this.age < 65){
            fee = 12.75f;
        } else if(this.age >= 65){
            fee = 12.75f*0.5f;
        }
        return fee;
    }

    public boolean spend(float amt){
        if(amt > 0){
            if (amt <= this.money){
                this.money -= amt;
                return true;
            } else{
                return false;
            }
        } else{
            return false;
        }
    }

    public boolean hasMoreMoneyThan(Customer c){
        if(this.money > c.money){
            return true;
        } else{
            return false;
        }
    }

    public void payAdmission(){
        this.spend(this.computeFee());
        this.admitted = true;
    }

    public String toString() {
        String admit = "";
        if(this.admitted == false){
            admit = "not ";
        }

        return (String.format("Customer %s: a %d year old with $%.2f who has %sbeen admitted",this.name,this.age,this.money,admit));
    }
}
