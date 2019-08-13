import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
	static int n, maxHeap[], maxSize, minHeap[], minSize, left, right;
	static boolean leftChk, rightChk;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		n = Integer.parseInt(br.readLine());
		maxHeap = new int[n/2+2];
		maxSize = 1;
		maxHeap[1] = -10001;
		minHeap = new int[n/2+2];
		minSize = 1;
		for(int i = 0; i < n; ++i) {
			add(Integer.parseInt(br.readLine()));
			sb.append(mid()).append("\n");
		}
		System.out.println(sb);
	}

	private static int mid() {
		int res = 0;
		if(maxSize < minSize) {
			res = minHeap[1];
		} else {
			res = maxHeap[1];
		}
		return res;
	}

	private static void add(int x) {
		if(maxSize < minSize) {
			if(minHeap[1] < x) {
				maxAdd(minPop());
				minAdd(x);
			} else {
				maxAdd(x);
			}
		} else {
			if(maxHeap[1] > x) {
				minAdd(maxPop());
				maxAdd(x);
			} else {
				minAdd(x);
			}
		}
	}

	private static int minPop() {
		int now = 1;
		int res = minHeap[1];
		minHeap[1] = minHeap[--minSize];
		while(true) {
			left = now*2;
			right = now*2+1;
			leftChk = left <= minSize && minHeap[now] > minHeap[left]; 
			rightChk = right <= minSize && minHeap[now] > minHeap[right];
			if(leftChk && rightChk) {
				if(minHeap[left] > minHeap[right]) {
					minSwap(now, right);
					now = right;
				} else {
					minSwap(now, left);
					now = left;
				}
			} else if(leftChk) {
				minSwap(now, left);
				now = left;
			} else if(rightChk) {
				minSwap(now, right);
				now = right;
			} else {
				break;
			}
		}
		return res;
	}

	private static void minAdd(int x) {
		int now = minSize++;
		minHeap[now] = x;
		while(now > 1 && minHeap[now/2] > minHeap[now]) {
			minSwap(now/2, now);
			now /= 2;
		}
	}

	private static void minSwap(int i, int j) {
		int tmp = minHeap[i];
		minHeap[i] = minHeap[j];
		minHeap[j] = tmp;
	}

	private static int maxPop() {
		int now = 1;
		int res = maxHeap[1];
		maxHeap[1] = maxHeap[--maxSize];
		while(true) {
			left = now*2;
			right = now*2+1;
			leftChk = left <= maxSize && maxHeap[now] < maxHeap[left]; 
			rightChk = right <= maxSize && maxHeap[now] < maxHeap[right];
			if(leftChk && rightChk) {
				if(maxHeap[left] < maxHeap[right]) {
					maxSwap(now, right);
					now = right;
				} else {
					maxSwap(now, left);
					now = left;
				}
			} else if(leftChk) {
				maxSwap(now, left);
				now = left;
			} else if(rightChk) {
				maxSwap(now, right);
				now = right;
			} else {
				break;
			}
		}
		return res;
	}

	private static void maxAdd(int x) {
		int now = maxSize++;
		maxHeap[now] = x;
		while(now > 1 && maxHeap[now/2] < maxHeap[now]) {
			maxSwap(now/2, now);
			now /= 2;
		}
	}

	private static void maxSwap(int i, int j) {
		int tmp = maxHeap[i];
		maxHeap[i] = maxHeap[j];
		maxHeap[j] = tmp;
	}
}
