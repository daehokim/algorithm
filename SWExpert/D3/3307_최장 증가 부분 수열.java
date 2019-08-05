import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	static int n, num[], ans[], max;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
	
		int T = Integer.parseInt(br.readLine());
		for(int tc = 1; tc <= T; ++tc) {
			n = Integer.parseInt(br.readLine());
			num = new int[n];
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int i = 0; i < n; ++i) {
				num[i] = Integer.parseInt(st.nextToken());
			}
			
			ans = new int[n];
			max = 0;
			for(int i = 0; i < n; ++i) {
				ans[i] = 1;
				for(int j = 0; j < i; ++j) {
					if(num[i] > num[j] && ans[i] <= ans[j])
						ans[i] = ans[j]+1;
				}
				max = max > ans[i] ? max : ans[i]; 
			}
			
			sb.append("#"+tc+" "+max+"\n");
		}
		System.out.println(sb);
	}
}
