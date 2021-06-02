import java.util.ArrayList;
import java.util.Random;

public class ElectronicStore {
    String name;
//    Desktop[] desktops = new Desktop[3];
    ArrayList<Desktop> desktops = new ArrayList<>;
    ArrayList<Laptop> laptops;
    ArrayList<Fridge> fridges;
    ArrayList<ArrayList> stock;


    public ElectronicStore(String storeName){
        this.name = storeName;

//        for(ArrayList<ArrayList> i: stock) {
        for(int j=0;j<3;j++) {
            this.desktops.add(new Desktop(3.5,16,1000,false));
        }
        for(int j=0;j<3;j++){
            this.laptops.add(new Laptop(4.8,8,500,true,15));
        }
        for(int j=0;j<3;j++){
            this.fridges.add(new Fridge(300,true,"Steel"));
        }

        this.stock.add(desktops);
        this.stock.add(laptops);
        this.stock.add((fridges));
    }

    public int printStock() {
        String stock = "";

//        ArrayList<String> products = new ArrayList<>
        for(ArrayList<ArrayList> i: this.stock){
            i.forEach(())

//            for(int j=0;j<3;j++){

//            }
        }
    }
}


Create Superclass for all products
Use more abstraction for this project
use inheritance
