import java.util.Scanner;

public class ElectronicStore {
    private final int MAX_PRODUCTS = 10;
    private String name;
    private double revenue;
    private Product[] products;
    private int productCount;

    public ElectronicStore(String name){
        this.name = name;
        this.revenue = 0;
        this.productCount = 0;
        this.products = new Product[MAX_PRODUCTS];
    }

    // Get methods
    String getName(){ return this.name; }
    double getRevenue(){ return this.revenue; }

    /**
     * Adds new product to Product array
     * @param p
     * @return Boolean value based on success of task
     */
    boolean addProduct(Product p){
        if(this.productCount < this.MAX_PRODUCTS){
            products[productCount] = p;
            productCount++;
            return true;
        } else{
            return false;
        }
    }

    /**
     * Prints all values contained in product array
     */
    void printStock(){
        for(int i=0;i<productCount;i++){
            System.out.println(i+". "+products[i]);
        }
    }

    /**
     * Sells specified amount of items of certain type
     * @param item int representing product's index in array
     * @param amount amount of specified item to sell
     */
    void sellProducts(int item, int amount){
        if(item >= 0 && item < this.productCount){
            if(amount > 0 && amount <= products[item].getStockQuantity()){
                this.revenue+=products[item].sellUnits(amount);;
            }
        }
    }

    /**
     * Prompts user to enter the index number and amount of a product to sell and sells them
     */
    void sellProducts(){
        Scanner in = new Scanner(System.in);
        int item, amount;
        printStock();

        while(true){
            System.out.print("\nWhat item (#) would you like to sell?: ");
            item = in.nextInt();
            if (item >= 0 && item < productCount) {
                break;
            }
        }
        while(true) {
            System.out.print("How many of this item would you like to sell?: ");
            amount = in.nextInt();
            if (amount > 0) {
                break;
            }
        }
        sellProducts(item,amount);
    }
}
