import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	static int n, k, s, e, ans;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		
		int T = Integer.parseInt(br.readLine());
		for(int tc = 1; tc <= T; tc++) {
			st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());
			k = Integer.parseInt(st.nextToken());
			s = 1;
			e = k*2;
			ans = 0;
			for(int i = 0; i < n/2; ++i) {
				ans += s+e;
				s = e+1;
				e += k*2;
			}
			sb.append("#"+tc+" ");
			if(n%2 == 0) {
				for(int i = 0; i < k; ++i) {
					sb.append(ans+" ");
				}
			} else {
				for(int i = s; i < s+k; ++i) {
					sb.append((ans+i)+" ");
				}
			}
			sb.append("\n");
		}
		
		System.out.println(sb);
	}
}
