import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
	static int n, q[], front, end;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		n = Integer.parseInt(br.readLine());
		q = new int[n*2];
		front = 0;
		end = 0;
		for(int i = 1; i <= n; ++i) {
			q[end++] = i;
		}
		
		while(end-front != 1) {
			front++;
			q[end++] = q[front++];
		}
		
		System.out.println(q[front]);
	}
}
