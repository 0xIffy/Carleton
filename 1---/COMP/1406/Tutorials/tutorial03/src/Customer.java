public class Customer {
    private int ID;
    private String name;
    private int age;
    private float money;

    public Customer(String n, int a, float m) {
        ID = -1;
        name = n;
        age = a;
        money = m;
    }

    public String toString() {
        return "Customer " + name + ": a " + age + " year old with $" + money;
    }

    public String getName(){ return this.name; }

    public int getAge(){ return this.age; }

    public boolean hasMoreMoneyThan(Customer c){
        if(this.money > c.money){
            return true;
        }
        return false;
    }

    public void setID(int id){ this.ID = id; }

    public int getID(){ return this.ID; }
}
