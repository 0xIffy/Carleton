import java.util.ArrayList;

public class Mall {
    public static final int MAX_STORES = 100;
    private String name;
    private Store[] stores;
    private int storeCount;
    public Mall(String n) {
        name = n;
        stores = new Store[MAX_STORES];
        storeCount = 0;
    }
    public void addStore(Store s) {
        if (storeCount < MAX_STORES) {
            stores[storeCount++] = s;
        }
    }
    public boolean shoppedAtSameStore(Customer c1,Customer c2){
        int count;

        for(Store s: this.stores) {
            try {
                if (!s.equals(null)) {
                    count = 0;
                    Customer[] customers = s.getCustomers();
                    for (Customer c : customers) {
                        if (c1.equals(c) || c2.equals(c)) {
                            count++;
                        }
                        if (count == 2) {
                            return true;
                        }
                    }
                    //            System.out.println("ssas");
                }
            }
            catch(Exception NullPointerException){
                break;
            }
        }
        return false;
    }

    public int getUniqueCustomerCount(){
        ArrayList<Customer> todayCust = new ArrayList<>();

        for(Store s: this.stores) {
            try {
                if (!s.equals(null)) {
                    Customer[] storeCust = s.getCustomers();
                    for (Customer c : storeCust) {
                        if (!c.equals(null) && !todayCust.contains(c)) {
                            todayCust.add(c);
                        }
                    }
                }
            }
            catch(Exception NullPointerException){
                continue;
            }
        }
//        System.out.println(todayCust);
        return todayCust.size();
    }
}
