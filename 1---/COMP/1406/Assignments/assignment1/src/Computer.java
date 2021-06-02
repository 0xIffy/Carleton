public class Computer{
    double cpuSpeed;
    int ram;
    int storage;
    boolean solidState;

    public Computer(){
        this(4.8,16,500,true);
    }

    public Computer(double cpuSpeed, int ram, int storage, boolean ssd){
        this.cpuSpeed = cpuSpeed;
        this.ram = ram;
        this.storage = storage;
        this.solidState = ssd;
    }
}