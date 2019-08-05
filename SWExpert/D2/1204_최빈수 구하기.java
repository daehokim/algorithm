import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	static int n, ans, count[], cnt;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
	
		int T = Integer.parseInt(br.readLine());
		for(int tc=1; tc<=T; ++tc) {
			n = Integer.parseInt(br.readLine());
			count = new int[101];
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int i=0; i<1000; ++i) {
				count[Integer.parseInt(st.nextToken())]++;
			}
			
			cnt = 0;
			ans = 0;
			for(int i=0; i<=100; ++i) {
				if(count[i] >= cnt) {
					cnt = count[i];
					ans = i;
				}
			}
			sb.append("#"+tc+" "+ans+"\n");
		}
		System.out.println(sb);
	}
}
