//Represents a meal made up of up to maxItems food items
public class Meal{
  private FoodItem[] items; //stores all of the food items that are in the meal
  private static final int maxItems = 25;
  
  //Constructor should initialize all instance variables
  public Meal(){
   
  }
  
  //Add the given food item to the items array, if there is still room
  //If there is no room, do nothing.
  public void addFoodItem(FoodItem item){
    
  }
  
  //Return the FoodItem in the items array that has the largest number of calories
  //If there are ties, you may return any of the largest
  public FoodItem mostCalories(){
    return null; //included so code will compile
  }
  
  //Computes and returns the total number of calories of all food items in this meal
  public int calculateTotalCalories(){
    return -1; //included so code will compile
  }
}