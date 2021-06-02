public class ToasterOven extends Appliance {
    private int width;
    private boolean convection;

   ToasterOven(double price,int quantity,int wattage,String colour,String brand,int width,boolean convection){
        super(price,quantity,wattage,colour,brand);
        this.width = width;
        this.convection = convection;
    }

    public String toString(){
        return (this.width+"\" "+super.toString());
    }

    /**
     * Checks if toaster has convection feature
     * @return String containing the feature if it exists
     */
    protected String addOns(){
        if(this.convection){
            return "with convection";
        }
        return "";
    }

    /**
     * Gets name of the run time type of this appliance
     * @return String containing name
     */
    protected String getName(){
        return "Toaster";
    }
}
