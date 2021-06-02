public class Fridge {
    double size;
    boolean freezer;
    String colour;

    public Fridge(double size, boolean freezer, String colour){
        this.size = size;
        this.freezer = freezer;
        this.colour = colour;
    }

    public String toString(){
        String freezer = "";

        if(this.freezer){
            freezer = "with Freezer";
        }
        return (String.format("%.1f cubic foot Fridge %s (%s)",this.size,freezer,this.colour));
    }
}
