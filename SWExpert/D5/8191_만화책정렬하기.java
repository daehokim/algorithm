import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	static int n, ans, now;
	static boolean chk[];
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		
		int T = Integer.parseInt(br.readLine());
		for(int tc = 1; tc <= T; tc++) {
			n = Integer.parseInt(br.readLine());
			st = new StringTokenizer(br.readLine());
			ans = 1;
			chk = new boolean[n];
			for(int i = 0; i < n; ++i) {
				now = Integer.parseInt(st.nextToken())-1;
				if(now > 0 && !chk[now-1]) ans++;
				chk[now] = true;
			}
			sb.append("#" + tc + " " + ans + "\n");
		}
		
		System.out.println(sb);
	}
}
