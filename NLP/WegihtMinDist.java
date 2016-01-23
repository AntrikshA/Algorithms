// Weighted Minimum Edit Distance, in JAVA
// just input separate little lookup tables for del, ins and subs !

public class WeightMinDist { 

	// public static:
	static String x = "hello";
	static String y = "yellow";
	static int d;
	static int[][] mind = new int[10][10];

	public static int min(int a, int b, int c){
		int min;
		min = (a<b) ? a : b;
		min = (min<c) ? min : c;
		return min;
	}

	public static int MinDist(int n,int m){
		
		for (int i=0;i<=m ;i++) {
			mind[0][i] = i;
		}
		for (int i=0;i<=n ;i++ ) {
			mind[i][0] = i;
		}

		for (int i=1; i<=n ; i++) {
			for (int j=1; j<=m ; j++ ) {

				int a = mind[i-1][j] + 1;
				int b = mind[i][j-1] + 1;
				int c;
				if(x.charAt(i-1) == y.charAt(j-1)){
					c = mind[i-1][j-1];
				}
				else{
					c = mind[i-1][j-1] + 2;
				}

				mind[i][j] = min(a,b,c);
				// System.out.println(d);
			}
		}

		return mind[n][m];
	
	}

	public static void main(String[] args) { 

		// Scanner reader = new Scanner(System.in);  // Reading from System.in
		// System.out.println("Enter a number: ");
		// int n = reader.nextInt(); // Scans the next token of the input as an int.
		
		int n = x.length();
		int m = y.length();

		System.out.println(x);
		System.out.println(y);

		int k = MinDist(n,m);

		System.out.print("Minimum Edit Distance :");
		System.out.println(k);

		for (int i=0;i<=n ;i++ ) {
			for (int j=0;j<=m ;j++ ) {
				System.out.print(mind[i][j]);
				System.out.print("\t");
			}
			System.out.println("");
			System.out.println("");
		}
	}
}