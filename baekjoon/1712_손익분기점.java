import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int start, end, mid;
	static long a, b, c, ans;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		a = Long.parseLong(st.nextToken());
		b = Long.parseLong(st.nextToken());
		c = Long.parseLong(st.nextToken());

		ans = c-b;
		if(ans <= 0) {
			ans = -1;
		} else {
			ans = a/(c-b);
			ans++;
		}
		
		System.out.println(ans);
	}
}
