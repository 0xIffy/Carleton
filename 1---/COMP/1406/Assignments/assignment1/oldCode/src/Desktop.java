public class Desktop {
    private double cpuSpeed;
    private int ram;
    private int storage;
    private boolean solidState;

    public Desktop(double cpuSpeed, int ram, int storage, boolean ssd){
        this.cpuSpeed = cpuSpeed;
        this.ram = ram;
        this.storage = storage;
        this.solidState = ssd;
    }

    public String toString(){
        String drive = "";
        if(this.solidState){
            drive = "SSD";
        } else{
            drive = "HDD";
        }
        return (String.format("Desktop PC with %.1fghz CPU, %dGB RAM, %dGB %s drive",this.cpuSpeed,this.ram,this.storage,drive));
    }
}
