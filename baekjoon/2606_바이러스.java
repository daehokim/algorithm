import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int n, m, com[], rank[], ans;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		n = Integer.parseInt(br.readLine());
		m = Integer.parseInt(br.readLine());
		com = new int[n];
		rank = new int[n];
		for(int i = 0; i < n; ++i) com[i] = i;
		for(int i = 0; i < m; ++i) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			union(Integer.parseInt(st.nextToken())-1, Integer.parseInt(st.nextToken())-1);
		}
		
		ans = 0;
		int root = find(com[0]);
		for(int i = 1; i < n; ++i) {
			if(root == find(com[i])) ans++;
 		}
		
		System.out.println(ans);
	}

	private static void union(int x, int y) {
		int rootX = find(x);
		int rootY = find(y);
		
		if(rootX == rootY) return;
		if(rank[rootX] > rank[rootY]) {
			com[rootY] = rootX;
		} else {
			com[rootX] = rootY;
			if(rank[rootX] == rank[rootY]) {
				rank[rootY]++;
			}
		}
	}

	private static int find(int x) {
		if(com[x] == x) return x;
		return find(com[x]);
	}
}
