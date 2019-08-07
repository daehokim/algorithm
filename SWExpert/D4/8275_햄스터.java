import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
 
public class Solution {
	static int n, x, m, cage[], count[][], tmp, ans[], sum, start, end;
	
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
        	start = n;
        	end = 0;
        	for(int i = 0; i < m; ++i) {
        		st = new StringTokenizer(br.readLine());
        		count[i][0] = Integer.parseInt(st.nextToken())-1;
        		count[i][1] = Integer.parseInt(st.nextToken())-1;
        		count[i][2] = Integer.parseInt(st.nextToken());
        		if(start > count[i][0]) start = count[i][0];
        		if(end < count[i][1]+1) end = count[i][1]+1;
        	}
        	
        	ans = new int[n];
        	sum = -1;
        	permu(start, 0);
        	
        	sb.append("#"+tc);
        	if(sum < 0) {
        		sb.append(" -1");
        	} else {
        		for(int i = 0; i < start; ++i)
        			sb.append(" "+x);
        		for(int i = start; i < end; ++i) 
        			sb.append(" "+ans[i]);
        		for(int i = end; i < n; ++i)
        			sb.append(" "+x);
        	}
        	sb.append("\n");
        }
	    System.out.print(sb);
    }

	private static void permu(int now, int total) {
		if(now == end) {
			if(total > sum) {
				for(int i = 0; i < m; ++i) {
					tmp = 0;
					for(int j = count[i][0]; j <= count[i][1]; ++j) {
						tmp += cage[j];
					}
					if(tmp != count[i][2]) return;
				}
				for(int j = start; j < end; ++j) 
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
