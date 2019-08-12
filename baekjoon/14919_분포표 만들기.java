import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int m, cnt[];
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		m = Integer.parseInt(br.readLine());
		cnt = new int[m];
		StringTokenizer st = new StringTokenizer(br.readLine());
		while(st.hasMoreTokens()) {
			cnt[(int)((Double.parseDouble(st.nextToken())+0.000000001)*m)]++;
		}
		for(int i = 0; i < m; ++i) {
			sb.append(cnt[i]).append(" ");
		}
		System.out.println(sb);
	}
}
