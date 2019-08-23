import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {
	static int n, m;
	static String poke_str[], input;
	static Map<String, Integer> poke_int;
	
	public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        poke_str = new String[n+1];
        poke_int = new HashMap<String, Integer>();
        for(int i = 1; i <= n; ++i) {
        	poke_str[i] = br.readLine();
        	poke_int.put(poke_str[i], i);
        }
        
        for(int i = 0; i < m; ++i) {
        	try {
        		input = br.readLine();
        		sb.append(poke_str[Integer.parseInt(input)]).append("\n");
        	} catch (Exception e) {
        		sb.append(poke_int.get(input)).append("\n");
        	}
        }
        
        System.out.println(sb);
	}
}
