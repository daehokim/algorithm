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
	Node head;
	Node tail;
	void add(Node n) {
		if(head == null) {
			head = new Node(0);
			tail = n;
			head.next = tail;
		} else {
			tail.next = n;
			tail = n;
		}
	}
	void add(Node now, Node n) {
		n.next = now.next;
		now.next = n;
	}
}
public class Solution {
	static int n, m, x, y;
	
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        
        int T = 10;
        for(int tc = 1; tc <= T; ++tc) {
        	n = Integer.parseInt(br.readLine());
        	StringTokenizer st = new StringTokenizer(br.readLine());
        	List list = new List();
        	for(int i = 0; i < n; ++i) 
        		list.add(new Node(Integer.parseInt(st.nextToken())));
        	m = Integer.parseInt(br.readLine());
        	st = new StringTokenizer(br.readLine());
        	for(int i = 0; i < m; ++i) {
        		switch(st.nextToken()) {
        		case "I":
        			x = Integer.parseInt(st.nextToken());
        			y = Integer.parseInt(st.nextToken());
        			Node now = list.head;
        			for(int j = 0; j < x; ++j)
        				now = now.next;
        			for(int j = 0; j < y; ++j) {
        				list.add(now, new Node(Integer.parseInt(st.nextToken())));
        				now = now.next;
        			}
        			break;
        		}
        	}
        	sb.append("#"+tc);
        	Node ans = list.head;
        	for(int i = 0; i < 10; ++i) {
        		ans = ans.next;
        		sb.append(" "+ans.val);
        	}
        	sb.append("\n");
        }
	    System.out.print(sb);
    }
}
