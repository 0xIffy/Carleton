public class Store {
    public static final int MAX_CUSTOMERS = 500;
    private static int LATEST_ID = 100000;
    private String name;
    private Customer[] customers;
    private int customerCount;

    public Store(String n) {
        name = n;
        customers = new Customer[MAX_CUSTOMERS];
        customerCount = 0;
    }
    public void addCustomer(Customer c) {
        if (customerCount < MAX_CUSTOMERS) {
            customers[customerCount++] = c;
            c.setID(LATEST_ID++);
        }
    }
    public void listCustomers() {
        for (int i=0; i<customerCount; i++)
            System.out.println(customers[i]);
    }

    public int averageCustomerAge(){
        int tAge = 0;
        int count = 0;
        for(Customer i: customers){
            tAge+=i.getAge();
            count++;
        }

        return tAge/customers.length;
    }

    public Customer richestCustomer(){
        int richIndex = 0;

        for(int i=1;i<customers.length;i++){
            if(customers[i].hasMoreMoneyThan(customers[i-1])){
                richIndex = i;
            }
        }

        return customers[richIndex];
    }

    public Customer[] getCustomers() {
        return customers;
    }
    public int getCustomerCount() {
        return customerCount;
    }

    public Customer[] friendsFor(Customer lonelyC){
        Customer[] friends = new Customer[this.customers.length];
        int count = 0;

        for(Customer c: this.customers){
            try {
                if (!c.equals(null) && ((lonelyC.getAge() - c.getAge() <= 3 && lonelyC.getAge() - c.getAge() > 0) || (c.getAge() - lonelyC.getAge() <= 3 && c.getAge() - lonelyC.getAge() > 0))) {
                    friends[count] = c;
                    count++;
                }
            }
            catch (Exception NullPointerException){
                break;
            }
        }
        return friends;
    }
}
