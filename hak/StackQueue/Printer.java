import java.util.ArrayList;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Queue;

// 프린터
public class Printer {
	public static int solution(int[] priorities, int location) {
		Queue<Integer> q = new LinkedList<>();					// 대기목록
		ArrayList<Integer> priority = new ArrayList<>();	// 대기목록 인덱스
		for (int i = 0; i < priorities.length; i++) {
			q.offer(priorities[i]);
			priority.add(i);
		}

		Iterator<Integer> it;
		int count = 0, element;		// count: 몇 번째로 인쇄, element: 검색용 원소
		int max = q.peek();			// max: 가장 큰 중요도
		int index, temp;				// index: 기준이 되는 대기목록 인덱스, temp: 기준이 되는 대기목록
		while(!q.isEmpty()) {
			//System.out.println("size: " + q.size());
			index = priority.get(0);	// 검색할 원소를 저장해두고 남은 원소들과 비교
			temp = q.poll();
			priority.remove(0);		// poll과 함께 List에서도 제거
			//System.out.println("temp: " + temp + " index: " + index + " count: " + count + " max " + max);
			
			it = q.iterator();
			while (it.hasNext()) {	// 남은 원소들과 비교
				element = it.next();
				if (temp < element) {// 중요도가 더 큰 것이 있으면
					q.offer(temp);		// 현재 대기목록을 맨 뒤로 옮김
					priority.add(index);
					max = element;
					break;
				}
			}

			if (temp == max) {		// 인쇄를 처리하면
				count++;
				if (index == location)		// 현재 인쇄되는 것이 원하는 문서인지
					return count;
				max = q.peek();		// 인쇄된 것을 제외하고 다시 max 값 설정
			}	
		}

		return count;
	}

	public static void main(String[] args) {
		System.out.println(solution(new int[] { 1,1,9,1,1,1}, 0));
	}
}
