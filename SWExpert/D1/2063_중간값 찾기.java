import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	static int n, num[], sorted[];
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
	
		n = Integer.parseInt(br.readLine());
		num = new int[n];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i = 0; i < n; ++i) {
			num[i] = Integer.parseInt(st.nextToken());
		}
		
		sorted = new int[n];
		mergeSort(0, n-1);
		
		sb.append(sorted[n/2]);
		System.out.println(sb);
	}

	private static void mergeSort(int left, int right) {
		if(left < right) {
			int mid = (left+right)/2;
			mergeSort(left, mid);
			mergeSort(mid+1, right);
			merge(left, mid, right);
		}
	}

	private static void merge(int left, int mid, int right) {
		int index = left;
		int i = left;
		int j = mid+1;
		while(i <= mid && j <= right) {
			if(num[i] < num[j]) 
				sorted[index++] = num[i++];
			else 
				sorted[index++] = num[j++];
		}
		
		if(i <= mid) {
			for(int l = i; l <= mid; ++l) {
				sorted[index++] = num[l];
			}
		}
		else {
			for(int l = j; l <= right; ++l) {
				sorted[index++] = num[l];
			}
		}
		
		for(int l=left; l <= right; ++l) {
			num[l] = sorted[l];
		}
	}
}
