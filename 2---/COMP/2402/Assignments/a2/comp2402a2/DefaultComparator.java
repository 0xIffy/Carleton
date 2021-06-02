package comp2402a2;

import java.util.Comparator;

class DefaultComparator<T> implements Comparator<T> {
	@SuppressWarnings("unchecked")
	public int compare(T a, T b) {
		if(a == null){
			return 1;
		} else if(b == null){
			return -1;
		} else{
			return ((Comparable<T>)a).compareTo(b);
		}
	}
}
