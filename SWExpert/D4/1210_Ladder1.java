import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
 
public class Solution {
    static int n, ladder[][], ans;
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        
        for(int tc=1;tc<=10;++tc) {
            Integer.parseInt(br.readLine());
            n = 100;
            ladder = new int[n][n];
            ans = 0;
            for(int i = 0; i < n; ++i) {
            	StringTokenizer st = new StringTokenizer(br.readLine());
            	for(int j = 0; j < n; ++j) {
            		ladder[i][j] = Integer.parseInt(st.nextToken());
            	}
            }
            for(int i = 0; i < n; ++i) {
            	if(ladder[n-1][i] == 2) {
            		int x = n-1;
            		while(x > 0) {
            			if(i-1 >= 0 && ladder[x][i-1] == 1) 
            				while(i-1 >= 0 && ladder[x][i-1] == 1) i--;
            			else if(i+1 < n && ladder[x][i+1] == 1) 
            				while(i+1 < n && ladder[x][i+1] == 1) i++;
            			x--;
            		}
            		ans = i;
            		break;
            	}
            }
            sb.append("#"+tc+" "+ans+"\n");
        }
	    System.out.print(sb);
    }
}
