import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	static int current[], promise[], time[];
	static String ans;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		
		int T = Integer.parseInt(br.readLine());
		for(int tc = 1; tc <= T; tc++) {
			current = new int[3];
			promise = new int[3];
			time = new int[3];
			st = new StringTokenizer(br.readLine(), ":");
			for(int i = 0; i < 3; ++i) 
				current[i] = Integer.parseInt(st.nextToken());
			st = new StringTokenizer(br.readLine(), ":");
			for(int i = 0; i < 3; ++i) 
				promise[i] = Integer.parseInt(st.nextToken());
			
			time[2] = promise[2]-current[2];
			if(time[2] < 0) {
				time[2] += 60;
				if(--promise[1] < 0) {
					promise[1] += 60;
					if(--promise[0] < 0) promise[0] += 24;
				}
			}
			time[1] = promise[1]-current[1];
			if(time[1] < 0) {
				time[1] += 60;
				if(--promise[0] < 0) promise[0] += 24;
			}
			time[0] = promise[0]-current[0];
			if(time[0] < 0) time[0] += 24;
			
			if(time[0] < 10) ans = "0"+time[0];
			else ans = time[0]+"";
			if(time[1] < 10) ans += ":0"+time[1];
			else ans += ":"+time[1];
			if(time[2] < 10) ans += ":0"+time[2];
			else ans += ":"+time[2];
			
			sb.append("#"+tc+" " + ans + "\n");
		}
		
		System.out.println(sb);
	}
}
