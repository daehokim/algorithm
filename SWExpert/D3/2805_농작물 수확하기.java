import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
 
public class Solution {
    static int n, ans;
     
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = null;
        
        int T = Integer.parseInt(br.readLine());
        for(int tc=1;tc<=T;++tc) {
            n = Integer.parseInt(br.readLine());
            ans = 0;
            for(int i = 0; i < n; ++i) {
            	for(int j = 0; j < n; ++j) {
            		if(Math.abs(n/2-i)+Math.abs(n/2-j) <= n/2) ans += br.read()-'0';
            		else br.read();
            	}
            	br.readLine();
            }
            sb.append("#"+tc+" "+ans+"\n");
        }
	    System.out.print(sb);
    }
}
