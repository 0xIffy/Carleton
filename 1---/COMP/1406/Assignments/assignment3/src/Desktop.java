public class Desktop extends Computer {
    private String profile;

    Desktop(double price,int quantity,double speed,int ram,boolean ssd,int storage,String profile){
        super(price,quantity,speed,ram,ssd,storage);
        this.profile = profile;
    }

    public String toString(){
        return (this.profile+" "+super.toString());
    }
}
