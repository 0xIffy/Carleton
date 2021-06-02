public class CustomerTestProgram {
    public static void main(String args[]) {
        Customer c1, c2, c3, c4, c5;
        Customer c6 = null;

        c1 = new Customer("Bob",17,100);
        c2 = new Customer("Dottie",70,20);
        c3 = new Customer("Jane",21);
        c4 = new Customer("Sam");
        c5 = new Customer();

        System.out.println(c1.computeFee());
        System.out.println("");
        System.out.println(c1);
        System.out.println(c3);
        System.out.println(c4);
        System.out.println(c5);
        System.out.println("");


        if(!c2.spend(10f)){
            System.out.println("Unable to spend!");
        }
        System.out.println(c2);
        System.out.println("");

        System.out.println("Bob and Dottie: " + c1.hasMoreMoneyThan(c2));
        System.out.println("");

        c1.payAdmission();
        c2.payAdmission();

        System.out.println(c1);
        System.out.println(c2);
        System.out.println(c3);
    }
}
