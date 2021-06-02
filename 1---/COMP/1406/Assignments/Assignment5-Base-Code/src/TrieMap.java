//Note: All of your TrieMapInterface method implementations must function recursively
//I have left the method signatures from my own solution, which may be useful hints in how to approach the problem
//You are free to change/remove/etc. any of the methods, as long as your class still supports the TrieMapInterface
import java.util.ArrayList;
public class TrieMap implements TrieMapInterface{
  TrieMapNode root;
  
  public TrieMap(){
    
  }
  
  //Indirectly recursive method to meet definition of interface
  public void put(String key, String value){
    
  }
  
  //Recursive method
  //Note: arguments are only a suggestion, you may use your own if you devise a different recursive solution
  public void put(TrieMapNode current, String curKey, String value){
    
  }
  
  //Indirectly recursive method to meet definition of interface
  public String get(String key){
    return "";
  }
  
  //Recursive method
  //Note: arguments are only a suggestion, you may use your own if you devise a different recursive solution
  public String get(TrieMapNode current, String curKey){
    return "";
  }
  
  //Indirectly recursive method to meet definition of interface
  public boolean containsKey(String key){
    return false;
  }
  
  //Recursive method
  //Note: arguments are only a suggestion, you may use your own if you devise a different recursive solution
  public boolean containsKey(TrieMapNode current, String curKey){
    return false;
  }
  
  //Indirectly recursive method to meet definition of interface
  public ArrayList<String> getKeysForPrefix(String prefix){
    return new ArrayList<String>();
  }
  
  //Recursive helper function to find node that matches a prefix
  //Note: only a suggestion, you may solve the problem is any recursive manner
  public TrieMapNode findNode(TrieMapNode current, String curKey){
    return null;
  }
  
  //Recursive helper function to get all keys in a node's subtree
  //Note: only a suggestion, you may solve the problem is any recursive manner
  public ArrayList<String> getSubtreeKeys(TrieMapNode current){
    return new ArrayList<String>();
  }
  
  //Indirectly recursive method to meet definition of interface
  public void print(){
    
  }
  
  //Recursive method to print values in tree
  public void print(TrieMapNode current){
    
  }
  
  public static void main(String[] args){
    //You can add some code in here to test out your TrieMap initially
    //The TrieMapTester includes a more detailed test
  }
}