import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int n, person[][], ans[];
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		n = Integer.parseInt(br.readLine());
		person = new int[n][2];
		for(int i = 0; i < n; ++i) {
			st = new StringTokenizer(br.readLine());
			person[i][0] = Integer.parseInt(st.nextToken());
			person[i][1] = Integer.parseInt(st.nextToken());
		}
		
		ans = new int[n];
		for(int i = 0; i < n; ++i) {
			ans[i] = 1;
			for(int j = 0; j < n; ++j) {
				if(i != j && person[i][0] < person[j][0] && person[i][1] < person[j][1]) {
					ans[i]++;
				}
			}
			sb.append(ans[i] + " ");
		}
		System.out.println(sb);
	}
}
