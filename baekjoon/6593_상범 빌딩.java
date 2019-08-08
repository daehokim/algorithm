import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	static int l, r, c, ans;
	static char building[][][];
	static Queue<int[]> q;
	static int dir[][] = {{-1, 0, 0}, {0, -1, 0}, {0, 0, -1}, {1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st = null;
		
		while((st = new StringTokenizer(br.readLine())) != null) {
			l = Integer.parseInt(st.nextToken());
			r = Integer.parseInt(st.nextToken());
			c = Integer.parseInt(st.nextToken());
			if(l == 0) break;
			building = new char[l][r][c];
			q = new LinkedList<int[]>();
			for(int i = 0; i < l; ++i) {
				for(int j = 0; j < r; ++j) {
					building[i][j] = br.readLine().toCharArray();
					if(q.isEmpty())
						for(int k = 0; k < c; ++k) {
							if(building[i][j][k] == 'S') q.offer(new int[] {i, j, k, 1});
						}
				}
				br.readLine();
			}
			
			ans = 0;
			loop:while(!q.isEmpty()) {
				for(int i = 0, len = q.size(); i < len; ++i) {
					int[] curr = q.poll();
					for(int d = 0; d < 6; ++d) {
						int x = curr[0]+dir[d][0];
						int y = curr[1]+dir[d][1];
						int z = curr[2]+dir[d][2];
						if(x >= 0 && x < l && y >= 0 && y < r && z >= 0 && z < c && ans == 0) {
							if(building[x][y][z] == '.') {
								building[x][y][z] = 'S';
								q.offer(new int[] {x, y, z, curr[3]+1});
							} else if(building[x][y][z] == 'E') {
								ans = curr[3];
								break loop;
							}
						}
					}
				}
			}
			if(ans == 0) sb.append("Trapped!\n");
			else sb.append("Escaped in "+ans+" minute(s).\n");
		}
		System.out.println(sb);
	}
}
