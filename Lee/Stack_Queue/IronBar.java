package Programmers;

import java.util.Stack;

public class IronBar {

	public static int solution(String arrangement) {
		int answer = 0;
		int cutCount = 0;

		Stack<Integer> s = new Stack<Integer>();

		for (int i = 0; i < arrangement.length(); i++) {
			if (arrangement.charAt(i) == '(' && arrangement.charAt(i + 1) == ')') {
				cutCount++;
				i++;
			} else {
				if (arrangement.charAt(i) == '(') {
					s.add(cutCount);
				} else {
					answer = answer + cutCount - s.pop() + 1;
				}
			}
		}

		return answer;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String arrangement = "()(((()())(())()))(())";

		System.out.println(solution(arrangement));
	}

}
