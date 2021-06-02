public abstract class Product {
    private double price;
    private int stockQuantity;
    private int soldQuantity;

    Product(double price,int quantity){
        this.price = price;
        this.stockQuantity = quantity;
        this.soldQuantity = 0;
    }

    public String toString(){
        return (String.format("\n\t($%.2f/unit, %d in stock, %d sold)",this.price,this.stockQuantity,this.soldQuantity));
    }

    // Get  methods
    int getStockQuantity() { return stockQuantity; }

    /**
     * Sells specified amount of this product
     * @param amount amount of product to sell
     * @return The revenue earned in the sale
     */
    double sellUnits(int amount){
        if(amount <= this.stockQuantity){
            this.stockQuantity-=amount;
            this.soldQuantity+=amount;

            return (this.price*amount);
        } else{
            System.out.println("Not enough stock to complete sale.");
            return 0.0;
        }
    }
}
