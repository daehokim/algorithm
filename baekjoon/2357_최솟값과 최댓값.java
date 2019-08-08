import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int n, m, size, a, b, num[], minTree[], maxTree[];
	
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
		minTree = new int[size];
		maxTree = new int[size];
		initMin(0, 0, n-1);
		initMax(0, 0, n-1);
		for(int i = 0; i < m; ++i) {
			st = new StringTokenizer(br.readLine());
			a = Integer.parseInt(st.nextToken())-1;
			b = Integer.parseInt(st.nextToken())-1;
			sb.append(min(0, 0, n-1)+" "+max(0, 0, n-1)+"\n");
		}
		System.out.print(sb);
	}
	
	private static int min(int node, int start, int end) {
		if(b < start || end < a) return Integer.MAX_VALUE;
		if(a <= start && end <= b) return minTree[node];
		int mid = (start+end)/2;
		return Math.min(min(node*2+1, start, mid), min(node*2+2, mid+1, end));
	}

	private static int initMin(int node, int start, int end) {
		if(start == end) {
			return minTree[node] = num[start];
		} else {
			int mid = (start+end)/2;
			return minTree[node] = Math.min(initMin(node*2+1, start, mid), initMin(node*2+2, mid+1, end));
		}
	}
	
	private static int max(int node, int start, int end) {
		if(b < start || end < a) return 0;
		if(a <= start && end <= b) return maxTree[node];
		int mid = (start+end)/2;
		return Math.max(max(node*2+1, start, mid), max(node*2+2, mid+1, end));
	}
	
	private static int initMax(int node, int start, int end) {
		if(start == end) {
			return maxTree[node] = num[start];
		} else {
			int mid = (start+end)/2;
			return maxTree[node] = Math.max(initMax(node*2+1, start, mid), initMax(node*2+2, mid+1, end));
		}
	}
}
