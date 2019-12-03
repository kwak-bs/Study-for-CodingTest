import java.util.Arrays;
import java.util.Stack;

// H-Index, 문제가 이상한데 결국 인용된 횟수의 최대값을 구해야함
public class H_Index {
	public static int solution(int[] citations) {
		Arrays.sort(citations); // 처리하기 편하게 정렬
		Stack<Integer> stack = new Stack<>(); // H <= 인용된 횟수를 만족하는 H 모음
		int count = 0, h = 0;		// count: 몇 번 인용됐는가, h: h번
		int i, min, index = 0 ;	// i: for문의 인덱스, min: 다음 인덱스를 찾기 위한 발판, 
											// index: 다음 검색할 h를 빨리 찾기 위한 인덱스 
		
		while(h <= citations[citations.length-1]) {
			min = 10000;
			for (i = index; i < citations.length; i++) {
				if (h+1 == citations[i] && min > i) {	// 다음 인용된 수를 바로가기 위한 인덱스 처리
					min = i;
					index = i;
				}
				
				if (h <= citations[i])	// h만큼 인용됐다면
					count++;
				
				if (h < count)			// 볼 것도 없음
					break;
			}
			
			if (h <= count)			// 문제의 답을 만족할 때
				stack.push(h);
			
			count = 0;		// 다음 h를 위한 초기화
			h++;
		}
		return stack.pop();
    }
	
	public static void main(String[] args) {
		System.out.println(solution(new int[] {20,19,18,1}));
	}
}
