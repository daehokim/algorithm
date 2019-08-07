import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	static int n, left, right;
	static char str[];
	static StringBuilder sb;
	
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        sb = new StringBuilder();
        StringTokenizer st = null;
        int T = 10;
        for(int tc = 1; tc <= T; ++tc) {
        	n = Integer.parseInt(br.readLine());
        	str = new char[n];
        	for(int i = 0; i < n; ++i) {
        		st = new StringTokenizer(br.readLine());
        		str[Integer.parseInt(st.nextToken())-1] = st.nextToken().charAt(0);
        	}
        	
        	sb.append("#"+tc+" ");
        	inOrder(0);
        	sb.append("\n");
        }
	    System.out.print(sb);
    }

	private static void inOrder(int index) {
		if((left = index*2+1) < n) inOrder(left);
		sb.append(str[index]);
		if((right = index*2+2) < n) inOrder(right);
	}
}
