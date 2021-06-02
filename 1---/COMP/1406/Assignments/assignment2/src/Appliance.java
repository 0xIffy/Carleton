public abstract class Appliance extends Product {
    private int wattage;
    private String colour;
    private String brand;

    Appliance(double price,int quantity,int wattage,String colour,String brand){
        super(price,quantity);
        this.wattage = wattage;
        this.colour = colour;
        this.brand = brand;
    }

    public String toString(){
        return (String.format("%s %s %s (%s, %d watts)",this.brand,this.getName(),this.addOns(),this.colour,this.wattage)+super.toString());
    }

    //Abstract methods
    protected abstract String addOns();
    protected abstract String getName();
}
