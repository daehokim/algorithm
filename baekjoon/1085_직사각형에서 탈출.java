import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int x, y, w, h, ans;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		x = Integer.parseInt(st.nextToken());
		y = Integer.parseInt(st.nextToken());
		w = Integer.parseInt(st.nextToken());
		h = Integer.parseInt(st.nextToken());
		
		ans = 1234567890;
		if(x < ans) ans = x;
		if((w-x) < ans) ans = w-x;
		if(y < ans) ans = y;
		if((h-y) < ans) ans = h-y;
		
		System.out.println(ans);
	}
}
