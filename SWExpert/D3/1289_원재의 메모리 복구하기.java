import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	static int ans;
	static char bit[], chk;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int T = Integer.parseInt(br.readLine());
		for(int tc = 1; tc <= T; ++tc) {
			bit = br.readLine().toCharArray();
			
			ans = 0;
			chk = '0';
			for(int i = 0, len = bit.length; i < len; ++i) {
				if(bit[i] != chk) {
					chk = bit[i];
					ans++;
				}
			}
			
			sb.append("#"+tc+" "+ans+"\n");
		}
		
		System.out.println(sb);
	}
}
