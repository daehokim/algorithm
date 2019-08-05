import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	static int n, k;
	static boolean chk[];
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
	
		int T = Integer.parseInt(br.readLine());
		for(int tc=1; tc<=T; ++tc) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());
			k = Integer.parseInt(st.nextToken());
			chk = new boolean[n+1];
			st = new StringTokenizer(br.readLine());
			for(int i=0; i<k; ++i) {
				chk[Integer.parseInt(st.nextToken())] = true;
			}
			
			sb.append("#"+tc+" ");
			for(int i=1; i<=n; ++i) {
				if(!chk[i]) sb.append(i+" ");
			}
			sb.append("\n");
		}
		System.out.println(sb);
	}
}
