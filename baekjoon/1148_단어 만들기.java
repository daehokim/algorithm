import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Main {
	static int count[], puzzle[], tmp, cnt, min, max;
	static char al[];
	static String ettential, dic;
	static List<String> dictionary;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		dictionary = new ArrayList<String>();
		String d = null;
		while(!(d=br.readLine()).equals("-")) {
			dictionary.add(d);
		}
		
		while(!(d=br.readLine()).equals("#")) {
			min = 200001;
			StringBuilder minString = new StringBuilder();
			max = 0;
			StringBuilder maxString = new StringBuilder();
			puzzle = new int[26];
			al = d.toCharArray();
			ettential = null;
			for(int i = 0; i < 9; i++) {
				puzzle[al[i]-'A']++;
			}
			
			count = new int[26];
			for(int i = 0; i < 26; i++) {
				if(puzzle[i] > 0) {
					ettential = (char)(i+'A')+"";
					cnt = 0;
					loop:for(int j = 0, size = dictionary.size(); j < size; j++) {
						Arrays.fill(count, 0);
						dic = dictionary.get(j);
						if(dic.contains(ettential)) {
							al = dic.toCharArray();
							for(int k = 0, len = al.length; k < len; k++) {
								tmp = al[k]-'A';
								count[tmp]++;
								if(count[tmp] > puzzle[tmp]) {
									continue loop;
								}
							}
							cnt++;
						}
					}//while
					if(cnt > max) {
						max = cnt;
						maxString.delete(0, maxString.length());
						maxString.append(ettential);
					} else if(cnt == max) {
						maxString.append(ettential);
					}
					if(cnt < min) {
						min = cnt;
						minString.delete(0, minString.length());
						minString.append(ettential);
					} else if(cnt == min) {
						minString.append(ettential);
					}
				}
			}//for puzzle
			
			sb.append(minString).append(" ").append(min).append(" ").append(maxString).append(" ").append(max).append("\n");
		}//while
		System.out.print(sb);
	}
}
