public abstract class Computer extends Product{
    private double cpuSpeed;
    private int ram;
    private boolean ssd;
    private int storage;

    Computer(double price,int quantity,double speed,int ram,boolean ssd,int storage){
        super(price,quantity);
        this.cpuSpeed = speed;
        this.ram = ram;
        this.ssd = ssd;
        this.storage = storage;
    }

    public String toString(){
        return (String.format("%s PC with %.1fghz CPU, %dGB of RAM, %dGB %s drive.",this.getClass().getName(),this.cpuSpeed,this.ram,this.storage,this.getHardDriveType())+super.toString());
    }

    /**
     * Checks the value of the ssd variable
     * @return String specifying type of hard drive the computer has
     */
    private String getHardDriveType(){
        String drive = "";
        if(this.ssd){
            drive = "SSD";
        } else{
            drive = "HDD";
        }
        return drive;
    }
}
