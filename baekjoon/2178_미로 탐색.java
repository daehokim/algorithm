import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	static int n, m, ans, currX, currY, tmpX, tmpY;
	static char maze[][];
	static Queue<Integer> q;
	static int dir[][] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		maze = new char[n][m];
		for(int i = 0; i < n; ++i) {
			maze[i] = br.readLine().toCharArray();
		}
		
		ans = 1;
		q = new LinkedList<Integer>();
		q.add(0);
		q.add(0);
		maze[0][0] = '0';
		loop:while(true) {
			for(int i = 0, len = q.size()/2; i < len; ++i) {
				currX = q.poll();
				currY = q.poll();
				if(currX == n-1 && currY == m-1) break loop;
				for(int d = 0; d < 4; ++d) {
					tmpX = currX+dir[d][0];
					tmpY = currY+dir[d][1];
					if(tmpX >= 0 && tmpX < n && tmpY >= 0 && tmpY < m && maze[tmpX][tmpY] == '1') {
						maze[tmpX][tmpY] = '0';
						q.add(tmpX);
						q.add(tmpY);
					}
				}
			}
			ans++;
		}
		
		System.out.println(ans);
	}
}
