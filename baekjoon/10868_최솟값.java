import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int n, m, size, a, b, num[], tree[];
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder(); 
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		num = new int[n];
		for(int i = 0; i < n; ++i) {
			num[i] = Integer.parseInt(br.readLine());
		}
		size = 1;
		while(size < n) 
			size = size<<1;
		size = (size<<1)-1;
		tree = new int[size];
		init(0, 0, n-1);
		for(int i = 0; i < m; ++i) {
			st = new StringTokenizer(br.readLine());
			a = Integer.parseInt(st.nextToken())-1;
			b = Integer.parseInt(st.nextToken())-1;
			sb.append(min(0, 0, n-1)+"\n");
		}
		System.out.print(sb);
	}
	
	private static int min(int node, int start, int end) {
		if(b < start || end < a) return Integer.MAX_VALUE;
		if(a <= start && end <= b) return tree[node];
		int mid = (start+end)/2;
		return Math.min(min(node*2+1, start, mid), min(node*2+2, mid+1, end));
	}

	private static int init(int node, int start, int end) {
		if(start == end) {
			return tree[node] = num[start];
		} else {
			int mid = (start+end)/2;
			return tree[node] = Math.min(init(node*2+1, start, mid), init(node*2+2, mid+1, end));
		}
	}
}
