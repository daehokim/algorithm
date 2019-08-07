import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int n, m, num[], sorted[];
	
	static void mergeSort(int left, int right) {
		if(left < right) {
			int mid = (left+right)/2;
			mergeSort(left, mid);
			mergeSort(mid+1, right);
			merge(left, mid, right);
		}
	}
	
	static void merge(int left, int mid, int right) {
		int index = left;
		int l = left;
		int r = mid+1;
		while(l <= mid && r <= right) {
			if(num[l] < num[r])
				sorted[index++] = num[l++];
			else
				sorted[index++] = num[r++];
		}
		
		if(l <= mid) {
			for(int i = l; i <= mid; ++i)
				sorted[index++] = num[i];
		} else {
			for(int i = r; i <= right; ++i)
				sorted[index++] = num[i];
		}
		
		for(int i = left; i <= right; ++i) {
			num[i] = sorted[i];
		}
	}
	
	static boolean find(int x) {
		int l = 0;
		int r = n-1;
		int mid = 0;
		while(l < r) {
			mid = (l+r)/2;
			if(num[mid] < x) l = mid+1;
			else r = mid;
		}

		if(num[l] == x) return true;
		else return false;
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st = null;
		
		n = Integer.parseInt(br.readLine());
		num = new int[n];
		st = new StringTokenizer(br.readLine());
		for(int i = 0; i < n; ++i)
			num[i] = Integer.parseInt(st.nextToken());
		
		sorted = new int[n];
		mergeSort(0, n-1);
		
		m = Integer.parseInt(br.readLine());
		st = new StringTokenizer(br.readLine());
		int x = 0;
		for(int i = 0; i < m; ++i) {
			x = Integer.parseInt(st.nextToken());
			if(find(x)) sb.append("1\n");
			else sb.append("0\n");
		}
		System.out.print(sb);
	}
}
