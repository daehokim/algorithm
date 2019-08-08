import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
	static int x, max, index;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		max = 0;
		index = 0;
		for(int i = 0; i < 9; ++i) {
			x = Integer.parseInt(br.readLine());
			if(x > max) {
				max = x;
				index = i+1;
			}
		}
		System.out.println(max);
		System.out.println(index);
	}
}
