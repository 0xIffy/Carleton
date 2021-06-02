import java.util.Scanner;

public class ElectronicStoreTester {
    public static void main(String[] args){
        ElectronicStore bestBuy = new ElectronicStore("Best Buy");
        bestBuy.printStock();

        Scanner in = new Scanner(System.in);
        while(true){
            System.out.print("\nEnter a item to search for: ");
            String search = in.next();

            if(search.equals("quit")) {
                break;
            } else {
                if(bestBuy.searchStock(search)){
                    System.out.println("A matching item is contained in stock.");
                } else{
                    System.out.println("No items in stock match your search.");
                }
            }
        }
    }
}