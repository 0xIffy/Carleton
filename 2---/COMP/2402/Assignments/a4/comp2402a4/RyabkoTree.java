package comp2402a4;

// import java.util.ArrayList;
// import java.util.List;
import java.util.Iterator;
// import ods.FastArrayStack;

public class RyabkoTree implements PrefixStack {
	private int n;
	// public List<Integer> arr;
	// public List<Long> sums;
	private int[] arr;
	private long[] sums;

  public RyabkoTree() {
		n = 0;
		// arr = new ArrayList<Integer>();
		// sums = new ArrayList<Long>();
		// sums.add((long) 0);

		arr = new int[1];
		sums = new long[2];

		sums[0] = 0;
	}

	private int parent(int i){
		return i - (i & (-i));
	}

	private int next(int i){
		return i + (i & (-i));
	}

	private void resize(){
		int[] b = new int[Math.max(2*n,1)];
		long[] c = new long[Math.max((2*n)+1,2)];
		c[0] = 0;

		for(int i = 0; i < n; i++){
			b[i] = arr[i];
			c[i+1] = sums[i+1];
		}
		arr = b;
		sums = c;
	}

  public void push(int x) {
		// throw new UnsupportedOperationException();
		// arr.add(x);
		if(n + 1 > arr.length) 
			resize();

		arr[n] = x;

		n++;

		//Parent sum of n
		long pSum = 0;
		int j = parent(n);

		// while(j > 0){
		// 	pSum += sums.get(j);
		// 	j = parent(j);
		// }

		// sum of last index
		int prevP = n - 1;
		long sum = x;

		while(prevP > 0 || j > 0){
			if(prevP > 0){
				// sum += sums.get(prevP);
				sum += sums[prevP];
				prevP = parent(prevP);
			}

			if(j > 0){
				// pSum += sums.get(j);
				pSum += sums[j];
				j = parent(j);
			}
		}

		// sums.add(sum - pSum);
		sums[n] = sum - pSum;
	}

  public int pop() {
		// throw new UnsupportedOperationException();
		// int x = arr.remove(n - 1);
		int x = arr[n - 1];
		// sums.remove(n);
		n--;

		if(arr.length >= n*3)
			resize();

		return x;
  }


  public int get(int i) {
		// throw new UnsupportedOperationException();
		// return arr.get(i);
		return arr[i];
  }

  public int set(int i, int x) {
		// throw new UnsupportedOperationException();
		int prev = get(i);
		if(x == prev)
			return x;

		long diff = x - prev;
		// int prev = arr.set(i,x);
		arr[i] = x;
		int j = i + 1;

		while(j <= n){
			// sums.set(j,sums.get(j) + diff);
			sums[j] += diff;
			j = next(j);
		}

		return prev;
  }

  public long prefixSum(int i) {
		// throw new UnsupportedOperationException();
		int curr = i + 1;
		long sum = 0;

		while(curr > 0){
			// sum += sums.get(curr);
			sum += sums[curr];
			curr = parent(curr);
		}

		return sum;
  }

	public int size() {
			// throw new UnsupportedOperationException();
			return n;
	}

	public Iterator<Integer> iterator() {
			// throw new UnsupportedOperationException();
			// return arr.iterator();
			class PrefixIterator implements Iterator<Integer>{
				Integer i;

				public PrefixIterator(){
					// this.curr = arr[0];
					i = 0;
				}

				public boolean hasNext(){
					return i + 1 < n;
				}

				public Integer next(){
					i++;

					return arr[i];
				}
			}

			return new PrefixIterator();
	}

	public static void main(String[] args){
		RyabkoTree rt = new RyabkoTree();
		int[] arr = {2,1,1,3,2,3,4,5,6,7,8,9};

		for(int i : arr){
			rt.push(i);
		}

		System.out.print("[");
		for(int i : rt.arr){
			System.out.print(i+",");
		}
		System.out.println("]");

		System.out.print("[");
		for(long i : rt.sums){
			System.out.print(i+",");
		}
		System.out.println("]");
	}
}
