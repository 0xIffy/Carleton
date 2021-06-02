//Note: All of your TrieMapInterface method implementations must function recursively
//I have left the method signatures from my own solution, which may be useful hints in how to approach the problem
//You are free to change/remove/etc. any of the methods, as long as your class still supports the TrieMapInterface
import java.util.ArrayList;
import java.util.HashMap;

public class TrieMap implements TrieMapInterface{
  TrieMapNode root;
  
  public TrieMap(){
    this.root = new TrieMapNode();
  }
  
  //Indirectly recursive method to meet definition of interface
  public void put(String key, String value){
    put(root,key,value,0);
  }
  
  //Recursive method
  //Note: arguments are only a suggestion, you may use your own if you devise a different recursive solution
  private void put(TrieMapNode curNode, String key, String value, Integer charIndex){
//    System.out.println(charIndex);
//    System.out.println(curKey+","+key.subSequence(0,charIndex+1).toString());
    if(value.equals(curNode.getValue())){
      return;
    } else {
      Character curKey = key.charAt(charIndex);
      HashMap<Character,TrieMapNode> nodeChildren = curNode.getChildren();

      if (!(nodeChildren.containsKey(curKey))) {
        curNode.addChild(curKey, new TrieMapNode());
      }
//      System.out.println(key.subSequence(0,charIndex+1).toString());
      if(key.subSequence(0,charIndex+1) == key){
        nodeChildren.get(curKey).setValue(value);
      }
      put(nodeChildren.get(curKey), key, value, charIndex+1);
    }
  }
  
  //Indirectly recursive method to meet definition of interface
  public String get(String key){
    if(!(containsKey(key))){
      return null;
    } else {
      return get(root, key,0);
    }
  }
  
  //Recursive method
  //Note: arguments are only a suggestion, you may use your own if you devise a different recursive solution
  public String get(TrieMapNode curNode, String key, Integer charIndex){
    if(key.substring(0,charIndex) == key){
      return curNode.getValue();
    } else {
      Character curKey = key.charAt(charIndex);
      HashMap<Character,TrieMapNode> nodeChildren = curNode.getChildren();

      return get(nodeChildren.get(curKey),key,charIndex+1);
    }
  }
  
  //Indirectly recursive method to meet definition of interface
  public boolean containsKey(String key){
    return containsKey(root,key,0);
  }
  
  //Recursive method
  //Note: arguments are only a suggestion, you may use your own if you devise a different recursive solution
  private boolean containsKey(TrieMapNode curNode, String key, Integer charIndex){
    if(key.substring(0,charIndex) == key){
      if(curNode.getValue() == null){
        return false;
      }
      return true;
    } else{
      Character curKey = key.charAt(charIndex);
      HashMap<Character,TrieMapNode> nodeChildren = curNode.getChildren();

      if(nodeChildren.containsKey(curKey)){
        return containsKey(nodeChildren.get(curKey),key,charIndex+1);
      } else{
        return false;
      }
    }
  }

  private boolean containsPrefix(TrieMapNode curNode, String prefix, Integer charIndex){
    if(prefix.substring(0,charIndex) == prefix){
      return true;
    } else{
      Character curKey = prefix.charAt(charIndex);
      HashMap<Character,TrieMapNode> nodeChildren = curNode.getChildren();

      if(nodeChildren.containsKey(curKey)){
        return containsPrefix(nodeChildren.get(curKey),prefix,charIndex+1);
      } else{
        return false;
      }
    }
  }
  
  //Indirectly recursive method to meet definition of interface
  public ArrayList<String> getKeysForPrefix(String prefix){
    if(containsPrefix(root,prefix,0)) {
      return getSubtreeKeys(findNode(root, prefix, 0),new ArrayList<String>());
    } else{
      return new ArrayList<String>();
    }
  }
  
  //Recursive helper function to find node that matches a prefix
  //Note: only a suggestion, you may solve the problem is any recursive manner
  public TrieMapNode findNode(TrieMapNode curNode, String prefix, Integer charIndex){
    if(prefix.substring(0,charIndex) == prefix) {
      return curNode;
    } else{
      Character curKey = prefix.charAt(charIndex);
      HashMap<Character,TrieMapNode> nodeChildren = curNode.getChildren();

      return findNode(nodeChildren.get(curKey),prefix,charIndex+1);
    }
  }
  
  //Recursive helper function to get all keys in a node's subtree
  //Note: only a suggestion, you may solve the problem is any recursive manner
  private ArrayList<String> getSubtreeKeys(TrieMapNode curNode, ArrayList<String> subKeys){
    HashMap<Character,TrieMapNode> nodeChildren = curNode.getChildren();

    if(curNode.getValue()!=null){
      subKeys.add(curNode.getValue());
    }

    for (Character key : nodeChildren.keySet()) {
      getSubtreeKeys(nodeChildren.get(key),subKeys);
    }

    return subKeys;
  }
  
  //Indirectly recursive method to meet definition of interface
  public void print(){
    System.out.print("[");
    print(root);
    System.out.println("]");
  }
  
  //Recursive method to print values in tree
  private void print(TrieMapNode curNode){
    if(curNode.getValue() != null){
      System.out.print(curNode.getValue() + ", ");
    }

    if(curNode.getChildren() != null) {
      for (Character key : curNode.getChildren().keySet()) {
        print(curNode.getChildren().get(key));
      }
    }
  }
  
  public static void main(String[] args){
    //You can add some code in here to test out your TrieMap initially
    //The TrieMapTester includes a more detailed test
    TrieMap fig = new TrieMap();
    fig.put("hello","hello");
    fig.print();
    fig.put("hello","hi");
    fig.print();
    fig.put("hey","hey");
    fig.print();
    System.out.println(fig.containsKey("hello"));
    System.out.println(fig.get("hey"));
    System.out.println(fig.get("hello"));
    System.out.println(fig.get("hi"));

  }
}