import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int n, num[], min, tmp;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		n = Integer.parseInt(br.readLine());
		num = new int[n];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i = 0; i < n; ++i) {
			num[i] = Integer.parseInt(st.nextToken());
		}
		min = 1234567890;
		int i = 0;
		int j = n-1;
		while(i < j) {
			tmp = num[i]+num[j];
			if(Math.abs(min) > Math.abs(tmp)) min = tmp;
			if(tmp < 0) ++i;
			else --j;
		}
		System.out.println(min);
	}
}
