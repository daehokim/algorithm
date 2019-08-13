import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
	static int n, x, ans;
	static boolean chk[];
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		x = 42;
		chk = new boolean[x];
		ans = 0;
		for(int i = 0; i < 10; ++i) {
			n = Integer.parseInt(br.readLine())%x;
			if(!chk[n]) {
				ans++;
				chk[n] = true;
			}
		}
		System.out.println(ans);
	}
}
