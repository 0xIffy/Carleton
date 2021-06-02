import java.util.Random;

public class mystery {
	public mystery(){
		
	}

	public double myst(int n){
		int x = 0;
		double a, b;
		Random rand = new Random();

		for(int i = 1; i <= n; i++){
			a = rand.nextDouble();
			b = rand.nextDouble();

			if(a*a + b*b <= 1)
				x += 1;
		}

		return ( (double) 4*x/n);
	}

	public static void main(String args[]){
		mystery m = new mystery();

		System.out.println(m.myst(100000000));
	}
}