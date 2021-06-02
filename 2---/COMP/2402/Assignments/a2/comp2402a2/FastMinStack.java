package comp2402a2;

import java.util.Comparator;
import java.util.List;
import java.util.LinkedList;
import java.util.Iterator;
import java.util.ArrayList;

public class FastMinStack<T> implements MinStack<T> {

	protected Comparator<? super T> comp;
	protected List<T> ms;
	protected List<T> mins;
	protected int n;

  public FastMinStack() {
    this(new DefaultComparator<T>());
  }

  public FastMinStack(Comparator<? super T> comp) {
    this.comp = comp;
		// TODO: Your code goes here
		n = 0;
		ms = new ArrayList<T>();
		mins = new ArrayList<T>();
	}
	
	public T get(int i){
		if(n > i){
			return ms.get(i);
		} else {
			return null;
		}
	}

  public void push(T x) {
		// TODO: Your code goes here
		ms.add(x);
		n++;
		if(mins.isEmpty() || comp.compare(x, mins.get(mins.size()-1)) <= 0){
			mins.add(x);
		}
  }

  public T pop() {
		// TODO: Your code goes here
		int minSize = mins.size()-1;
		int mSize = n-1;
		
		if(ms.get(mSize) == mins.get(minSize)){
			mins.remove(minSize);
		}

		n--;
    return ms.remove(mSize);
  }

  public T min() {
    // TODO: Your code goes here
    return mins.get(mins.size()-1);
	}
	
	public boolean isEmpty(){
		return this.get(0) == null;
	}

  public int size() {
    // TODO: Your code goes here
    return n;
  }

  public Iterator<T> iterator() {
    // TODO: Your code goes here
    return ms.iterator();
  }

  public Comparator<? super T> comparator() {
    return comp;
  }
}
