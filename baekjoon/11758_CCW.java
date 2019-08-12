import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int n, p[][], tmp, ans;
	
	static int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
	    if ((tmp = x1*y2+x2*y3+x3*y1 - y1*x2-y2*x3-y3*x1) > 0) {
	        return 1;
	    } else if (tmp < 0) {
	        return -1;
	    } else {
	        return 0;
	    }
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		p = new int[3][2];
		for(int i = 0; i < 3; ++i) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			p[i][0] = Integer.parseInt(st.nextToken());
			p[i][1] = Integer.parseInt(st.nextToken());
		}
		
		ans = ccw(p[0][0], p[0][1], p[1][0], p[1][1], p[2][0], p[2][1]);
		
		System.out.println(ans);
	}
}
