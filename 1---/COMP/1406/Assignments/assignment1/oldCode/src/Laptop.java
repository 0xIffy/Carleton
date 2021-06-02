public class Laptop extends Desktop{
    int screenSize;

    public Laptop(int size){
        this.cpuSpeed = cpuSpeed;
        this.ram = ram;
        this.storage = storage;
        this.solidState = ssd;
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
