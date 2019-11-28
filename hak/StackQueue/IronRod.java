import java.util.Stack;

// 쇠막대기
public class IronRod {
	public static int solution(String arrangement) {
		arrangement = arrangement.replace("()", "1");		// 레이저 처리
		int answer = 0;		// 쇠막대기 총 개수
		char curr;	// 배치
		Stack<Integer> stack = new Stack<>();
		for (int i = 0; i < arrangement.length(); i++) {
			curr = arrangement.charAt(i);
			
			if (curr == '(') 			// 쇠막대기 왼쪽
				stack.push(1);

			else if (curr == ')') 	// 쇠막대기 오른쪽
				answer += stack.pop();
			
			else {					// 레이저 처리
				answer += stack.size();
				// 통과 (8147.37ms, 351MB)
//				for (int j = 0; j < stack.size(); j++)
//					stack.set(j, stack.get(j)+1);
			}
		}
        return answer;
    }
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println(solution("()(((()())(())()))(())"));
	}
}


/* 테스트 케이스 1번 시간초과
import java.util.Stack;

// 쇠막대기
public class IronRod {
	public static int solution(String arrangement) {
		int answer = 0;
		char curr, next;
		Stack<Integer> stack = new Stack<>();
		for (int i = 0; i < arrangement.length(); i++) {
			curr = arrangement.charAt(i);
			if (i < arrangement.length()-1)
				next = arrangement.charAt(i+1);
			else
				next = ')';
			
			
			if (curr == '(') {
				for (int j = 0; !stack.isEmpty() && j < stack.size(); j++)
					stack.set(j, stack.get(j)+1);
				
				if (next == '(') 
					stack.push(1);
				else  // next == ')'
					answer += stack.size();
			}

			else {	// curr == ')'
				for (int j = 0; !stack.isEmpty() &&  j < stack.size(); j++)
					stack.set(j, stack.get(j)-1);
				
				if(!stack.isEmpty() && stack.peek() == 0) {
					stack.pop();
					answer++;
				}
			}
		}
        return answer;
    }
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println(solution("()(((()())(())()))(())"));
	}
}
*/
