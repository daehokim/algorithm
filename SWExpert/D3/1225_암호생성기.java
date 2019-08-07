import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
 
public class Solution {
	static int n, q[], head, tail, tmp, cycle;

	static void add(int val) {
		q[tail++] = val;
		if(tail == n) tail %= n;
	}
	
	static int pop() {
		int res = q[head++];
		if(head == n) head %= n;
		return res;
	}
	
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        
        int T = 10;
        for(int tc = 1; tc <= T; ++tc) {
        	br.readLine();
        	StringTokenizer st = new StringTokenizer(br.readLine());
        	n = 8;
        	q = new int[n];
        	head = 0; tail = 0;
        	for(int i = 0; i < n; ++i) {
        		add(Integer.parseInt(st.nextToken()));
        	}
        	
        	cycle = 1;
        	while(q[(tail+7)%n] != 0) {
        		tmp = pop();
        		tmp = tmp-cycle > 0 ? tmp-cycle : 0;
        		add(tmp);
        		cycle++;
        		if(cycle == 6) cycle = 1;
        	}
        		
        	sb.append("#"+tc);
        	for(int i = 0; i < n; ++i) sb.append(" "+pop());
        	sb.append("\n");
        }
	    System.out.print(sb);
    }
}
