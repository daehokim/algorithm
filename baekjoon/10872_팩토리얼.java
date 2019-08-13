import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
	static int n, fac[];
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		fac = new int[13];
		fac[0] = 1;
		fac[1] = 1;
		for(int i = 2; i < 13; ++i) fac[i] = fac[i-1]*i;
		
		n = Integer.parseInt(br.readLine());
		
		System.out.println(fac[n]);
	}
}
