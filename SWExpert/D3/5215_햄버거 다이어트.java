import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	static int n, l, t[], k[], score[], ans;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
	
		int T = Integer.parseInt(br.readLine());
		for(int tc = 1; tc <= T; ++tc) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());
			l = Integer.parseInt(st.nextToken());
			t = new int[n];
			k = new int[n];
			for(int i = 0; i < n; ++i) {
				st = new StringTokenizer(br.readLine());
				t[i] = Integer.parseInt(st.nextToken());
				k[i] = Integer.parseInt(st.nextToken());
			}
			
			score = new int[l+1];
			score[0] = 1;
			ans = 0;
			for(int i = 0; i < n; ++i) {
				for(int j = l-k[i]; j >= 0; --j) {
					if(score[j] > 0 && score[j]+t[i] > score[j+k[i]]) {
						score[j+k[i]] = score[j]+t[i]; 
						ans = ans > score[j+k[i]] ? ans : score[j+k[i]];
					}
				}
			}
			
			sb.append("#"+tc+" "+(ans-1)+"\n");
		}
		System.out.println(sb);
	}
}   
