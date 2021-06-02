import java.util.Scanner;

public class TaxProgram {
    public static void main(String[] args){
        double income, fedTax, provTax;
        int dependents;

        Scanner input = new Scanner(System.in);
        System.out.print("Please enter your taxable income: ");
        income = input.nextDouble();
        System.out.println();
        System.out.print("Please enter your number of dependents: ");
        dependents = input.nextInt();
        System.out.println();
        fedTax = 0.0;
        provTax = 0.0;

        if(income <= 29590){
            fedTax = income*0.17;
        } else if(income <= 59179.99){
            fedTax = 29590*0.17+(income-29590)*0.26;
        } else if(income >= 59180){
            fedTax = (29590*0.17)+(29590*0.26)+(income-59180)*0.29;
        }

        provTax = fedTax*0.425-160.5;

        if(provTax > 328*dependents){
            provTax-=328*dependents;
        } else{
            provTax = 0;
        }

//        System.out.println("The total tax is: "+(fedTax+provTax));

        System.out.println(String.format("%-20s$%,10.2f","Income",income));
        System.out.println(String.format("%-20s %10d","Dependants",dependents));
        System.out.println(String.format("%31s",' ').replace(' ','-'));
        System.out.println(String.format("%-20s$%,10.2f","Federal Tax",fedTax));
        System.out.println(String.format("%-20s$%,10.2f","Provincial Tax",provTax));
        System.out.println(String.format("%31s",' ').replace(' ','='));
        System.out.println(String.format("%-20s$%,10.2f","Total Tax",(fedTax+provTax)));


    }
}
