import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	static int w, h, ans;
	static char building[][];
	static Queue<Integer> sg, fire;
	static int dir[][] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st = null;
		
		int T = Integer.parseInt(br.readLine());
		for(int tc = 1; tc <= T; ++tc) {
			st = new StringTokenizer(br.readLine());
			w = Integer.parseInt(st.nextToken());
			h = Integer.parseInt(st.nextToken());
			building = new char[h][w];
			sg = new LinkedList<Integer>();
			fire = new LinkedList<Integer>();
			for(int i = 0; i < h; ++i) {
				building[i] = br.readLine().toCharArray();
				for(int j = 0; j < w; ++j) {
					if(building[i][j] == '@') {
						sg.add(i);
						sg.add(j);
						sg.add(1);
					}
					if(building[i][j] == '*') {
						fire.add(i);
						fire.add(j);
					}
				}
			}
			
			ans = 0;
			loop:while(!sg.isEmpty()) {
				int len = fire.size()/2;
				for(int i = 0; i < len; ++i) {
					int currX = fire.poll();
					int currY = fire.poll();
					for(int d = 0; d < 4; ++d) {
						int x = currX+dir[d][0];
						int y = currY+dir[d][1];
						if(x >= 0 && x < h && y >= 0 && y < w && building[x][y] != '#' && building[x][y] != '*') {
							building[x][y] = '*';
							fire.add(x);
							fire.add(y);
						}
					}
				}
				len = sg.size()/3;
				for(int i = 0; i < len; ++i) {
					int currX = sg.poll();
					int currY = sg.poll();
					int time = sg.poll();
					for(int d = 0; d < 4; ++d) {
						int x = currX+dir[d][0];
						int y = currY+dir[d][1];
						if(x < 0 || x == h || y < 0 || y == w) {
							ans = time;
							break loop;
						}
						if(building[x][y] == '.') {
							building[x][y] = '@';
							sg.add(x);
							sg.add(y);
							sg.add(time+1);
						}
					}
				}
			}
			
			if(ans == 0) sb.append("IMPOSSIBLE\n");
			else sb.append(ans+"\n");
		}
		System.out.println(sb);
	}
}
