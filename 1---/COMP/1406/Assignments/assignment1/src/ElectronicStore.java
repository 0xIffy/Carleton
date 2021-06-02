import java.lang.reflect.Constructor;
import java.util.HashMap;
import java.util.ArrayList;

public class ElectronicStore {
    String name;
    HashMap<String, ArrayList> stock = new HashMap<>();

    public ElectronicStore(String storeName) {
        this.name = storeName;

        ArrayList<Object> desk = new ArrayList<>();
        ArrayList<Object> lap = new ArrayList<>();
        ArrayList<Object> fridge = new ArrayList<>();

        for (int i = 0; i < 3; i++)
            desk.add(new Desktop());
        for (int i = 0; i < 3; i++)
            lap.add(new Laptop());
        for (int i = 0; i < 3; i++)
            fridge.add(new Fridge());

        this.stock.put("desktops", desk);
        this.stock.put("laptops", lap);
        this.stock.put("fridges", fridge);
    }

    public void printStock() {
        System.out.println("Stock includes:");
        for (String product : this.stock.keySet()) {
            for(int i=0;i<3;i++) {
                System.out.println(this.stock.get(product).get(i));
            }
        }
    }

    public boolean searchStock(String s){
        for (String product : this.stock.keySet()) {
            for (int i = 0; i < 3; i++) {
                if(this.stock.get(product).get(i).toString().toLowerCase().contains(s.toLowerCase())){
                    return true;
                }
            }
        }
        return false;
    }
}