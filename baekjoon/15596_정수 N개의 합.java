
public class Test {
	public long sum(int[] a) {
		long sum = 0;
		for(int i = 0, len = a.length; i < len; ++i) {
			sum += a[i];
		}
		return sum;
	}
}
