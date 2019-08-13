import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int n, m, card[], ans, tmp;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		card = new int[n];
		st = new StringTokenizer(br.readLine());
		for(int i = 0; i < n; ++i) card[i] = Integer.parseInt(st.nextToken());
		
		ans = 0;
		for(int i = 0; i < n-2; ++i) {
			for(int j = i+1; j < n-1; ++j) {
				for(int k = j+1; k < n; ++k) {
					tmp = card[i]+card[j]+card[k];
					if(tmp <= m && tmp > ans) ans = tmp;
				}
			}
		}
		
		System.out.println(ans);
	}
}
