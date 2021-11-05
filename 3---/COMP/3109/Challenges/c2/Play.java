import java.util.Random;

public class Play{
	Random rand;

	Play(long seed){
		rand = new Random(seed);
	}

	int nextInt(){
		return rand.nextInt();
	}

	public static int next(long seed) {
		int bits = 32;
		long seed2;
		// long seed2 = (seed ^ 0x5DEECE66DL) & ((1L << 48) - 1);

		// do{
			// seed = seed2;
			seed2 = (seed * 0x5DEECE66DL + 0xBL) & ((1L << 48) - 1);
		// } while(seed == seed2);

		return (int)(seed2 >>> (48 - bits));
	}


	public static void main(String[] args){
		long t1 = 319333903;
		long t2 = 381363348;
		// long seed = 0x5AA5B6B8; 
		Play p;

		Random r = new Random();
		int n1, n2, n3;

		// long seed =0;
		// for (int i = 0; i < 65536; i++) {
		// 		seed = t1 *65536 + i ;
		// 		if (next(seed) == t2) {
		// 				System.out.println("Seed found: " + seed);
		// 				break;
		// 		}
		// }

		long seed = (t1 << 16);
		for(int i = 0; i < 65536; i++){
			if(next(seed) == t2){
				System.out.println(t2);
				System.out.println(next(seed));
				System.out.println(seed);

				break;
			} 

			seed++;
		}
		

		System.out.println(next( (seed * 0x5DEECE66DL + 0xBL) & ((1L << 48) - 1) ));

		// int delta = 0xfffff;
		// int i = -1 * delta;
		// do{
		// 	seed = r.nextInt();
		
		// 	// seed = 0x5AA5B6B;	
			// p = new Play(seed);

			// n1 = p.nextInt();
			// n2 = p.nextInt();
			// n3 = p.nextInt();

		// 	// System.out.println(String.format("x%08X", (n1) >>> 24));

		// 	// System.out.println(n1);
		// 	// System.out.println(n2);
		// 	// System.out.println(n3);
		// } while((n1 ^ t1) >>> 4 != 0);

		// do{
		// 	// System.out.println("hey");
			
		// 	p = new Play(seed + i++);

		// 	n1 = p.nextInt();
		// 	n2 = p.nextInt();
		// 	n3 = p.nextInt();

		// 	if(i > delta){
		// 		System.out.println("f");
		// 	}

		// } while((n1 ^ t1) >>> 4 != 0 || (n2 ^ t2) >>> 24 != 0);
		

		// System.out.println(String.format("0x%08X", seed));
		// System.out.println(String.format("0x%08X, %d", n1, n1));
		// System.out.println(String.format("0x%08X, %d", n2, n2));
		// System.out.println(String.format("0x%08X", n3));
	}
}