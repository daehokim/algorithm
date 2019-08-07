import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
 
public class Solution {
	static int n, x, m, cage[], count[][], tmp, ans[], sum;
	
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        
        int T = Integer.parseInt(br.readLine());
        for(int tc = 1; tc <= T; ++tc) {
        	StringTokenizer st = new StringTokenizer(br.readLine());
        	n = Integer.parseInt(st.nextToken());
        	x = Integer.parseInt(st.nextToken());
        	m = Integer.parseInt(st.nextToken());
        	cage = new int[n];
        	count = new int[m][3];
        	for(int i = 0; i < m; ++i) {
        		st = new StringTokenizer(br.readLine());
        		count[i][0] = Integer.parseInt(st.nextToken())-1;
        		count[i][1] = Integer.parseInt(st.nextToken())-1;
        		count[i][2] = Integer.parseInt(st.nextToken());
        	}
        	
        	ans = new int[n];
        	sum = -1;
        	permu(0, 0);
        	
        	sb.append("#"+tc);
        	if(sum < 0) {
        		sb.append(" -1");
        	} else {
        		for(int i = 0; i < n; ++i) {
        			sb.append(" "+ans[i]);
        		}
        	}
        	sb.append("\n");
        }
	    System.out.print(sb);
    }

	private static void permu(int now, int total) {
		if(now == n) {
			if(total > sum) {
				for(int i = 0; i < m; ++i) {
					tmp = 0;
					for(int j = count[i][0]; j <= count[i][1]; ++j) {
						tmp += cage[j];
					}
					if(tmp != count[i][2]) return;
				}
				for(int j = 0; j < n; ++j) 
					ans[j] = cage[j];
				sum = total;
			}
			return;
		}
		
		for(int i = 0; i <= x; i++) {
			cage[now] = i;
			permu(now+1, total+i);
		}
	}
}
