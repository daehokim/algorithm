import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Solution {
	static int n, m, ans, odd, even;
	static String encrypt, tmp;
	static String[] decrypt = {
			"0001101", "0011001", "0010011", "0111101", "0100011", "0110001", "0101111", "0111011", "0110111", "0001011"
	};
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        
        int T = Integer.parseInt(br.readLine());
        for(int tc = 1; tc <= T; ++tc) {
        	StringTokenizer st = new StringTokenizer(br.readLine());
        	n = Integer.parseInt(st.nextToken());
        	m = Integer.parseInt(st.nextToken());
        	encrypt = null;
        	for(int i = 0; i < n;++i) {
        		tmp = br.readLine();
        		if(encrypt == null && tmp.contains("1")) {
        			while(!tmp.endsWith("1")) {
        				tmp = tmp.substring(0, --m);
        			}
        			encrypt = tmp.substring(m-56, m);
        		}
        	}
        	
        	ans = 0;
        	odd = 0;
        	even = 0;
        	for(int i = 0; i < 8; ++i) {
        		tmp = encrypt.substring(7*i, 7*(i+1));
        		if(i%2 == 0) {
        			for(int j = 0; j < 10; ++j) {
        				if(decrypt[j].equals(tmp)) {
        					odd += j;
        					break;
        				}
        			}
        		} else {
        			for(int j = 0; j < 10; ++j) {
        				if(decrypt[j].equals(tmp)) {
        					even += j;
        					break;
        				}
        			}
        		}
        	}
        	if((odd*3+even)%10 == 0) ans = odd+even;
        	sb.append("#").append(tc).append(" ")
        	.append(ans).append("\n");
        }
	    System.out.print(sb);
    }
}
