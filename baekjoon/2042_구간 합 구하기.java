import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int n, m, k, size, a, b, c, index;
	static long num[], tree[], diff;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder(); 
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		num = new long[n];
		for(int i = 0; i < n; ++i) {
			num[i] = Integer.parseInt(br.readLine());
		}
		size = 1;
		while(size < n) 
			size = size<<1;
		size = (size<<1)-1;
		tree = new long[size];
		init(0, 0, n-1);
		for(int i = 0; i < m+k; ++i) {
			st = new StringTokenizer(br.readLine());
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken())-1;
			c = Integer.parseInt(st.nextToken());
			if(a == 1) {
				diff = c-num[b];
				num[b] = c;
				index = b;
				update(0, 0, n-1);
			} else {
				c--;
				sb.append(sum(0, 0, n-1)+"\n");
			}
		}
		System.out.print(sb);
	}

	private static long sum(int node, int start, int end) {
		if(c < start || b > end) {
			return 0;
		}
		if(b <= start && end <= c) {
			return tree[node];
		}
		int mid = (start+end)/2;
		return sum(node*2+1, start, mid)+sum(node*2+2, mid+1, end);
	}

	private static void update(int node, int start, int end) {
		if(index < start || end < index) return;
		
		tree[node] += diff;
		if(start != end) {
			int mid = (start+end)/2;
			update(node*2+1, start, mid);
			update(node*2+2, mid+1, end);
		}
	}

	private static long init(int node, int start, int end) {
		if(start == end) {
			return tree[node] = num[start];
		} else {
			int mid = (start+end)/2;
			return tree[node] = init(node*2+1, start, mid)+init(node*2+2, mid+1, end);
		}
	}
}
