public class Laptop extends Computer {
    private double screenSize;

    Laptop(double price,int quantity,double speed,int ram,boolean ssd,int storage,double screenSize){
        super(price,quantity,speed,ram,ssd,storage);
        this.screenSize = screenSize;
    }

    public String toString(){
        return (this.screenSize+"\" "+super.toString());
    }
}
