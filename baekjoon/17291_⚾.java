import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int n, batter[][], ans, out, ining, base[], batting[], index, bit, tmp;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder(); 
		
    	n = Integer.parseInt(br.readLine());
    	batter = new int[n+1][9];
    	for(int i = 0; i < 9; ++i) {
    		batter[0][i] = i;
    	}
    	for(int i = 1; i <= n; ++i) {
    		StringTokenizer st = new StringTokenizer(br.readLine());
    		for(int j = 0; j < 9; ++j) {
    			batter[i][j] = Integer.parseInt(st.nextToken());
    		}
    	}
    	
    	ans = 0;
    	bit = 0;
    	batting = new int[9];
    	for(int i = 1; i < 9; ++i) {
			index = 0;
			batting[index++] = batter[0][i];
			bit += (1<<i);
			lineUp();
			bit -= (1<<i);
    	}
    	
		System.out.println(ans);
	}

	private static void lineUp() {
		if(index == 9) {
			out = 0;
			play();
			return;
		}
		if(index == 3) {
			batting[index++] = batter[0][0];
			lineUp();
			index--;
		}
		for(int i = 1; i < 9; ++i) {
			if((bit&(1<<i)) == 0) {
    			batting[index++] = batter[0][i];
    			bit += (1<<i);
    			lineUp();
    			bit -= (1<<i);
    			index--;
    		}
		}
	}

	private static void play() {
		int score = 0;
		int cnt = 0;
		for(ining = 1; ining <= n; ++ining) {
			out = 0;
			base = new int[4];
			while(out < 3) {
				if((tmp = batter[ining][batting[cnt++]]) == 0) out++;
				else {
					for(int i = 3; i > 0; --i) {
						if(base[i] > 0) {
							if(i+tmp < 4) {
								base[i]--;
								base[i+tmp]++;
							} else {
								base[i]--;
								score++;
							}
						}
					}
					if(tmp < 4) {
						base[tmp]++;
					} else {
						score++;
					}
				}
				cnt %= 9;
			}
		}
		if(score > ans) ans = score;
	}
}
