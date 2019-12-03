import java.util.ArrayList;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Queue;

// 다리를 지나는 트럭
public class Truck {
	public static int solution(int bridge_length, int weight, int[] truck_weights) {
		Queue<Integer> bridge = new LinkedList<>();		// 다리를 지나는 트럭
		Queue<Integer> wait = new LinkedList<>();		// 대기 트럭
		ArrayList<Integer> count = new ArrayList<>();	// 트럭이 간 거리
		
		for (int i: truck_weights)
			wait.offer(i);
		
		Iterator<Integer> it;
		int result, sum = 0;
		for (result = 1; !bridge.isEmpty() || !wait.isEmpty(); result++) {	// 다리를 모두 지나면
			//System.out.println("result: " + result);
			if (!count.isEmpty() && count.get(0) == bridge_length) {	// 다리를 지나는 가장 앞 트럭이 다 지나가면
				bridge.poll();		// 다리에서 제거
				count.remove(0);	// 거리에서 제거
			}
			
			it = bridge.iterator();
			while(it.hasNext()) {	// 다리 위에 있는 트럭의 무게
				sum += it.next();
			}
			
			if (!wait.isEmpty() && sum + wait.peek() <= weight) {	// 여유가 되면 트럭 하나 들어감
				bridge.offer(wait.poll());
				count.add(0);
			}
			
			for (int i = 0; i < count.size(); i++)	// 트럭들이 한 칸씩 이동
				count.set(i, count.get(i)+1);
			
			sum = 0;
		}
		
        return result-1;
    }
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println(solution(100,100,new int[] {10,10,10,10,10,10,10,10,10,10}));
	}
}
