public class Fridge extends Appliance {
    private double cubicFeet;
    private boolean hasFreezer;

    Fridge(double price,int quantity,int wattage,String colour,String brand,double cubicFeet,boolean hasFreezer){
        super(price,quantity,wattage,colour,brand);
        this.cubicFeet = cubicFeet;
        this.hasFreezer = hasFreezer;
    }

    public String toString(){
        return (this.cubicFeet+" cu. ft. "+super.toString());
    }

    /**
     * Checks if fridge has freezer feature
     * @return String containing the feature if it exists
     */
    protected String addOns(){
        if(this.hasFreezer){
            return "with Freezer";
        }
        return "";
    }

    /**
     * Gets name of the run time type of this appliance
     * @return String containing name
     */
    protected String getName(){
        return "Fridge";
    }
}
