public class ElectronicStoreTester {
    public static void main(String[] args){
        Desktop d1 = new Desktop(4,16,500, true);
        Laptop l1 = new Laptop(4,16,500, true,15);
        Fridge f1 = new Fridge(12.2,true,"Red");

        System.out.println(d1);
        System.out.println(l1);
        System.out.println(f1);

    }
}
