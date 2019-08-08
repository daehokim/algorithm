import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static String str;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		str = br.readLine();
		for(int i = 0, len = str.length(); i < len; ++i) {
			if(str.charAt(i) <= 'C') sb.append((char)(str.charAt(i)+23));
			else sb.append((char)(str.charAt(i)-3));
		}
		System.out.println((int)'A');
		System.out.println(sb);
	}
}
