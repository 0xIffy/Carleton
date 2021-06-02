import java.lang.reflect.Array;


public class Test{
	public class Node{
		int x;

		public Node(int i){
			x = i;
		}
	}

	Node[] arr;

	// @SuppressWarnings("unchecked")
	public Test(){
		arr = (Node[])Array.newInstance(Node.class,10);
	}

	public static void main(String[] args){
		Test t = new Test();

		System.out.println(t.arr[9]);
	}
}