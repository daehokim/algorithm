import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
 
public class Solution {
	static int n, cnt1, cnt2, cnt3, cnt4;
    static String brace;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        
        for(int tc=1;tc<=10;++tc) {
        	n = Integer.parseInt(br.readLine());
        	brace = br.readLine();
        	cnt1 = 0;
        	cnt2 = 0;
        	cnt3 = 0;
        	cnt4 = 0;
        	for(int i = 0; i < n; ++i) {
        		switch(brace.charAt(i)) {
        		case '(': cnt1++; break;
        		case ')': cnt1--; break;
        		case '{': cnt2++; break;
        		case '}': cnt2--; break;
        		case '[': cnt3++; break;
        		case ']': cnt3--; break;
        		case '<': cnt4++; break;
        		case '>': cnt4--; break;
        		}
        	}
        	if((cnt1|cnt2|cnt3|cnt4) == 0)
        		sb.append("#"+tc+" 1\n");
        	else 
        		sb.append("#"+tc+" 0\n");
        }
	    System.out.print(sb);
    }
}
