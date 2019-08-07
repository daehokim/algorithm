import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Solution {
	static int n, ans;
	static String str[];
	
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int T = 10;
        for(int tc = 1; tc <= T; ++tc) {
        	n = Integer.parseInt(br.readLine());
        	ans = 1;
        	for(int i = 0; i < n; ++i) {
        		str = br.readLine().split(" ");
        		if(str[1].equals("+") || str[1].equals("-") || str[1].equals("*") || str[1].equals("/")) {
        			if(str.length != 4)
        				ans = 0;
        		} else {
        			if(str.length != 2)
        				ans = 0;
        		}
        	}
        	sb.append("#"+tc+" "+ans+"\n");
        }
	    System.out.print(sb);
    }
}
