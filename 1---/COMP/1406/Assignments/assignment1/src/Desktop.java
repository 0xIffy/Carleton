public class Desktop extends Computer{
    public Desktop(){
        super();
    }

    public Desktop(double cpuSpeed, int ram, int storage, boolean ssd){
        super(cpuSpeed,ram,storage,ssd);
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