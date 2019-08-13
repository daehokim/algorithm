import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int n, q[], front, end, size, r, tmp, i;
	static String str, cmd;
	static boolean error;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int T = Integer.parseInt(br.readLine());
		for(int tc = 1; tc <= T; ++tc) {
			cmd = br.readLine();
			n = Integer.parseInt(br.readLine());
			q = new int[n];
			str = br.readLine();
			StringTokenizer st = new StringTokenizer(str.substring(1, str.length()-1), ",");
			for(i = 0; i < n; ++i) {
				q[i] = Integer.parseInt(st.nextToken()); 
			}
			
			front = 0;
			end = n-1;
			size = n;
			r = 1;
			i = 0;
			error = false;
			for(int len =cmd.length(); i < len; ++i) {
				if(cmd.charAt(i) == 'R') {
					tmp = front;
					front = end;
					end = tmp;
					r = -r;
				} else {
					if(size == 0) {
						sb.append("error").append("\n");
						error = true;
						break;
					} else {
						front += r;
						size--;
					}
				}
			}
			if(!error) {
				sb.append("[");
				while(size != 0 && front != end) {
					sb.append(q[front]).append(",");
					front += r;
				}
				if(size != 0)
					sb.append(q[front]).append("]\n");
				else
					sb.append("]\n");
			}
		}
		System.out.print(sb);
	}
}
