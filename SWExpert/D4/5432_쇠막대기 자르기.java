import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
 
public class Solution {
	static int cnt, ans;
    static String laser;
    static boolean flag;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        
        int T = Integer.parseInt(br.readLine());
        for(int tc=1;tc<=T;++tc) {
        	laser = br.readLine();
        	cnt = 0;
        	ans = 0;
        	flag = false;
        	for(int i = 0, len = laser.length(); i < len; ++i) {
        		if(laser.charAt(i) == '(') {
        			flag = true;
        			cnt++;
        		} else {
        			cnt--;
        			if(flag) {
        				ans += cnt;
        				flag = false;
        			} else {
        				ans++;
        			}
        		}
        	}
            sb.append("#"+tc+" "+ans+"\n");
        }
	    System.out.print(sb);
    }
}
