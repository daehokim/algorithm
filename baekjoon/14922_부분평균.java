import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int n, a[], ans, u, v;
	static double min, tmp;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		n = Integer.parseInt(br.readLine());
		a = new int[n];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i = 0; i < n; ++i) {
			a[i] = Integer.parseInt(st.nextToken());
		}
		ans = 0;
		min = (double) (a[0]+a[1])/2;
		for(int i = 2; i < n; ++i) {
			tmp = (double) (a[i-2]+a[i-1]+a[i])/3;
			if(tmp < min) {
				min = tmp;
				ans = i-2;
			}
		}
		for(int i = 2; i < n; ++i) {
			tmp = (double) (a[i-1]+a[i])/2;
			if(tmp < min) {
				min = tmp;
				ans = i-1;
			}
		}
		System.out.println(ans);
	}
}
