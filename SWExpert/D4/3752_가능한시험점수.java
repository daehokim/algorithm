import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Node {
	int val;
	Node next;

	Node(int val) {
		this.val = val;
	}
}

class List {
	int size;
	Node head;
	Node tail;
	
	void add(Node n) {
		if(size++ == 0) {
			head = n;
			tail = n;
			head.next = tail;
		} else {
			tail.next = n;
			tail = n;
		}
	}
}
public class Solution {
	static int n, score, tmp;
	static boolean chk[];
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		
		int T = Integer.parseInt(br.readLine());
		for(int tc = 1; tc <= T; tc++) {
			n = Integer.parseInt(br.readLine());
			chk = new boolean[10001];
			List ans = new List();
			ans.add(new Node(0));
			st = new StringTokenizer(br.readLine());
			for(int i = 0; i < n; ++i) {
				score = Integer.parseInt(st.nextToken());
				Node now = ans.head;
				for(int j = 0, len = ans.size; j < len; j++) {
					tmp = now.val+score;
					if(!chk[tmp]) {
						ans.add(new Node(tmp));
						chk[tmp] = true;
					}
					now = now.next;
				}
			}
			
			sb.append("#" + tc + " " + ans.size + "\n");
		}
		
		System.out.println(sb);
	}
}
