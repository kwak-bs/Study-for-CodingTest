import java.util.ListIterator;
import java.util.Stack;

// 탑
public class Top {
	public static int[] solution(int[] heights) {
		 int[] answer = new int[heights.length];
        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < heights.length; i++)			// 송신 탑 높이를 Stack에 Push
        	stack.push(heights[i]);
        
        ListIterator<Integer> it;		// Stack의 원소 출력용
        int element, top, index;			// element: 적절한 수신 탑, 
        											// top: 현재 스택 젤 맨 위의 값, 
        											// index: element 조절 값
        
        // 송신 탑의 수신을 받을 수 있는 수신 탑 검색
        for (int i = stack.size()-1; !stack.isEmpty(); i--) {	// i: 현재 송신 탑
        	index = 0;
        	top = stack.pop();
        	it = stack.listIterator(stack.size());		// top을 제외한 배열을 위해 초기화
            while (it.hasPrevious()) {		// Stack 원소의 역방향으로 출력
            	element = it.previous();
            	if (top < element) {			// 송신 탑보다 수신 탑의 높이가 크면
            		answer[i] = i-index;
            		break;
            	}
            	index++;
            }
            if (answer[i] != 0)				// 적절한 수신 탑 크기를 찾았으면
            	continue;
        }
        
        return answer;
    }
}
