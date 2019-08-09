import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

class Customer {
	int num;
	int time;
	int receptionNum;
	int repairNum;
	int receptionEndTime;
	Customer next;
	
	Customer(int num, int time) {
		this.num = num;
		this.time = time;
	}
	void setReceptionNum(int receptionNum) {
		this.receptionNum = receptionNum;
	}
	void setRepairNum(int repairNum) {
		this.repairNum = repairNum;
	}
	void setReceptionEndTime(int receptionEndTime) {
		this.receptionEndTime = receptionEndTime;
	}
}

class List {
	Customer head;
	Customer tail;
	
	void add(Customer c) {
		if(head == null) {
			head = c;
			tail = c;
			head.next = c;
		} else {
			tail.next = c;
			tail = c;
		}
	}
	
	Customer pop() {
		Customer res = head;
		head = head.next;
		return res;
	}
	
	boolean isEmpty() {
		if(head == null) return true;
		else return false;
	}
}

class Heap {
	Customer customers[];
	int size;
	Heap(int num) {
		customers = new Customer[num+1];
		this.size = 1;
	}
	
	void add(Customer c) {
		int now = size++;
		customers[now] = c;
		while(now != 1) {
			if(check(now/2, now)) {
				swap(now/2, now);
			}
			now /= 2;
		}
	}
	Customer pop() {
		int index = 1;
		Customer res = customers[index];
		customers[index] = customers[--size];
		
		while(true) {
			int left = index*2;
			int right = index*2+1;
			boolean leftChk = left <= size && check(index, left);
			boolean rightChk = right <= size && check(index, right);
			if(leftChk && rightChk) {
				if(check(left, right)) {
					swap(right, index);
					index = right;
				} else {
					swap(left, index);
					index = left;
				}
 			} else if(leftChk) {
				swap(left, index);
				index = left;
			} else if(rightChk) {
				swap(right, index);
				index = right;
			} else {
				break;
			}
		}
 		
		return res;
	}
	boolean isEmpty() {
		if(size == 1) return true;
		else return false;
	}
	private void swap(int i, int j) {
		Customer tmp = customers[i];
		customers[i] = customers[j];
		customers[j] = tmp;
	}
	
	private boolean check(int a, int b) {
		if(customers[a].receptionEndTime > customers[b].receptionEndTime) {
			return true;
		} else if(customers[a].receptionEndTime == customers[b].receptionEndTime) {
			if(customers[a].receptionNum > customers[b].receptionNum) {
				return true;
			}
		}
		return false;
	}
}

public class Solution {
	static int n, m, k, a, b, receptionDesk[][], repairDesk[][], ans, t;
	
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        
        int T = Integer.parseInt(br.readLine());
        for(int tc = 1; tc <= T; ++tc) {
        	StringTokenizer st = new StringTokenizer(br.readLine());
        	n = Integer.parseInt(st.nextToken());
        	m = Integer.parseInt(st.nextToken());
        	k = Integer.parseInt(st.nextToken());
        	a = Integer.parseInt(st.nextToken());
        	b = Integer.parseInt(st.nextToken());
        	receptionDesk = new int[n][2];
        	st = new StringTokenizer(br.readLine());
        	for(int i = 0; i < n; ++i) receptionDesk[i][0] = Integer.parseInt(st.nextToken());
        	repairDesk = new int[m][2];
        	st = new StringTokenizer(br.readLine());
        	for(int i = 0; i < m; ++i) repairDesk[i][0] = Integer.parseInt(st.nextToken());
        	List receptionWait = new List();
        	st = new StringTokenizer(br.readLine());
        	for(int i = 0; i < k; ++i) receptionWait.add(new Customer(i+1, Integer.parseInt(st.nextToken())));
        	
        	ans = 0;
        	t = 0;
        	Heap repairWait = new Heap(k);
        	Customer[] receptioning = new Customer[n];
        	Customer[] repairing = new Customer[n];
        	while(k > 0) {
        		for(int i = 0; i < n; ++i) {
        			if(receptionDesk[i][1] > 0) {
        				if(--receptionDesk[i][1] == 0) {
        					receptioning[i].setReceptionEndTime(t);
        					repairWait.add(receptioning[i]);
        					receptioning[i] = null;
        				}
        			}
        			if(!receptionWait.isEmpty() && receptionWait.head.time <= t && receptioning[i] == null) {
    					receptionDesk[i][1] = receptionDesk[i][0];
    					receptioning[i] = receptionWait.pop();
    					receptioning[i].setReceptionNum(i+1);
    				}
        		}
        		
        		for(int i = 0; i < m; ++i) {
        			if(repairDesk[i][1] > 0) {
        				if(--repairDesk[i][1] == 0) {
        					repairing[i] = null;
        				}
        			}
        			if(!repairWait.isEmpty() && repairing[i] == null) {
        				repairDesk[i][1] = repairDesk[i][0];
        				repairing[i] = repairWait.pop();
        				repairing[i].setRepairNum(i+1);
        				if(repairing[i].receptionNum == a && repairing[i].repairNum == b) {
        					ans += repairing[i].num;
        				}
        				k--;
        			}
        		}
        		t++;
        	}
        	if(ans == 0) ans--;
        	sb.append("#").append(tc).append(" ")
        	.append(ans).append("\n");
        }
	    System.out.print(sb);
    }
}
