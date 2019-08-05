import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	static int n, box[], max, min;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
	
		for(int tc=1; tc<=10; ++tc) {
			n = Integer.parseInt(br.readLine());
			box = new int[101];
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int i=0; i<100; ++i) {
				box[Integer.parseInt(st.nextToken())]++;
			}
			max = 100;
			min = 0;
			for(int i=0; i<n; ++i) {
				while(box[max] == 0) {
					max--;
				}
				while(box[min] == 0) {
					min++;
				}
				box[max]--;
				box[max-1]++;
				box[min]--;
				box[min+1]++;
			}
			if(box[max] == 0) max--;
			if(box[min] == 0) min++;
			sb.append("#"+tc+" "+(max-min)+"\n");
		}
		System.out.print(sb);
	}
}
