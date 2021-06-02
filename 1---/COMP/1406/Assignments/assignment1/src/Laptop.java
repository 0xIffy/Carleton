public class Laptop extends Computer{
    int screenSize;

    public Laptop(){
        super();
        this.screenSize = 15;
    }

    public Laptop(double cpuSpeed, int ram, int storage, boolean ssd, int  size){
        super(cpuSpeed,ram,storage,ssd);
        this.screenSize = size;
    }

    public String toString(){
        String drive = "";
        if(this.solidState){
            drive = "SSD";
        } else{
            drive = "HDD";
        }
        return (String.format("%d\" Laptop PC with %.1fghz CPU, %dGB RAM, %dGB %s drive",this.screenSize,this.cpuSpeed,this.ram,this.storage,drive));
    }
}