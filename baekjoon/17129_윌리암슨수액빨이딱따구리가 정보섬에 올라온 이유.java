import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	static int n, m, map[][], ans;
	static boolean visit[][];
	static Queue<int[]> q;
	static int dir[][] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st = null;
		
		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		map = new int[n][m];
		visit = new boolean[n][m];
		q = new LinkedList<int[]>();
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				map[i][j] = br.read()-'0';
			}
			br.readLine();
		}
		
		ans = 0;
		loop:for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				if(map[i][j] == 2) {
					visit[i][j] = true;
					q.add(new int[] {i, j, 1});
					int curr[], x, y;
					loopW:while(!q.isEmpty()) {
						curr = q.poll();
						for(int d = 0; d < 4; ++d) {
							x = curr[0]+dir[d][0];
							y = curr[1]+dir[d][1];
							if(x >= 0 && x < n && y >= 0 && y < m && !visit[x][y] && map[x][y] != 1) {
								if(map[x][y] > 1) {
									ans = curr[2];
									break loopW;
								}
								visit[x][y] = true;
								q.add(new int[] {x, y, curr[2]+1});
							}
						}
					}
					break loop;
				}
			}
		}
		
		if(ans == 0) sb.append("NIE\n");
		else sb.append("TAK\n"+ans+"\n");
		
		System.out.println(sb);
	}
}
