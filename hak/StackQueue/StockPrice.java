import java.util.Iterator;
import java.util.LinkedList;
import java.util.Queue;

// 주식 가격
public class StockPrice {
	public static int[] solution(int[] prices) {
		Queue<Integer> q = new LinkedList<>();	// prices
		Iterator<Integer> it;		// 비교 원소들
		int[] answer = new int[prices.length];	// 가격이 떨어지지 않은 기간
		for (int i : prices)
			q.offer(i);
		
		int price, count;	// price: 현재 주식 가격, count: 얼마나 떨어지지 않았는가
		for (int i = 0; i < prices.length; i++) {
			price = q.poll();
			it = q.iterator();
			count = 0;
			while (it.hasNext()) {
				count++;
				if (price > it.next()) {	// 현재 주식 가격이 해당 시간에 떨어진다면
					answer[i] = count;
					break;
				}				
			}
			
			if (i == prices.length-1)		// 마지막 시점은 예측 불가
				answer[i] = 0;
			else if (answer[i] == 0)		// 끝까지 가격이 떨어지지 않았을 때
				answer[i] = count;
		}
        return answer;
    }
	
	public static void main(String[] args) {
		System.out.println(solution(new int[] {1,2,3,2,3}));
	}
}
