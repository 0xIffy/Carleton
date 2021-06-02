package comp2402a2;

import java.util.Comparator;
import java.util.List;
import java.util.LinkedList;
import java.util.ArrayList;
import java.util.Iterator;

public class FastMinDeque<T> implements MinDeque<T> {

	protected Comparator<? super T> comp;
	protected MinStack<T> front;
	protected MinStack<T> back;

  public FastMinDeque() {
    this(new DefaultComparator<T>());
  }

  public FastMinDeque(Comparator<? super T> comp) {
    this.comp = comp;
		// TODO: Your code goes here
		front = new FastMinStack<>();
		back = new FastMinStack<>();
	}
	
	private void balance(MinStack<T> s, Boolean bwds){
		front = new FastMinStack<>();
		back = new FastMinStack<>();

		int size = s.size();

		if(bwds){
			for(int i = size/2; i >= 0; i--){
				back.push(s.get(i));
			}
			for(int i = size/2+1; i < size; i++){
					front.push(s.get(i));
			}
		} else{
			for(int i = size/2; i >= 0; i--){
				front.push(s.get(i));
			}
			for(int i = size/2+1; i < size; i++){
					back.push(s.get(i));
			}
		}
	}

  public void addFirst(T x) {
		// TODO: Your code goes here		
		front.push(x);
  }

  public void addLast(T x) {
		// TODO: Your code goes here
		back.push(x);
  }

  public T removeFirst() {
		// TODO: Your code goes here
		if(front.isEmpty()){
			this.balance(back,false);
		}

		if(front.isEmpty()){
			return back.pop();
		}

		return front.pop();
  }

  public T removeLast() {
		// TODO: Your code goes here
		if(back.isEmpty()){
			this.balance(front,true);
		}

		if(back.isEmpty()){
			return front.pop();
		}

		return back.pop();
  }

  public T min() {
		// TODO: Your code goes here
		T fMin = !front.isEmpty() ? front.min() : null;
		T bMin = !back.isEmpty() ? back.min() : null;

		if(comp.compare(fMin, bMin) < 0){
			return fMin;
		} else{
			return bMin;
		}
  }

  public int size() {
    // TODO: Your code goes here
    return front.size() + back.size();
  }

  public Iterator<T> iterator() {
    // TODO: Your code goes here
    return new MinDequeIterator<>(this);
  }

  public Comparator<? super T> comparator() {
    return comp;
	}
	
	public MinStack<T> getFront(){
		return front;
	}

	public MinStack<T> getBack(){
		return back;
	}
}

class MinDequeIterator<T> implements Iterator<T>{
	T current;
	int pos;
	MinStack<T> front;
	MinStack<T> back;

	public MinDequeIterator(FastMinDeque<T> md){
		pos = 0;
		front = md.getFront();
		back = md.getBack();
		if(!front.isEmpty()){
			current = front.get(front.size()-1);
		} else{
			current = back.get(0);
		}
	}

	public boolean hasNext(){
		return current != null;
	}

	public T next(){
		pos++;
		T data = current;
		int fSize = front.size();
		if(pos < fSize){
			current = front.get(fSize-pos-1);
		} else{
			current = back.get(pos-fSize);
		}

		return data;
	}
}
