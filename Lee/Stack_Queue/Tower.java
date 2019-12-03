package Programmers;

import java.util.Stack;

public class Tower {

	public static int[] solution(int[] heights) {
		int[] answer = new int[heights.length];

		Stack<Integer> s = new Stack<Integer>();

		for (int i = heights.length - 1; i >= 0; i--) {
			if (s.empty()) {
				s.add(heights[i]);
			} else {
				if (heights[i] > s.peek()) {
					int count = 1;
					while (!s.empty() && heights[i] > s.peek()) {
						s.pop();
						answer[i + count++] = i + 1;
					}
				}
				s.add(heights[i]);
			}
		}
		return answer;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int heights[] = { 3, 9, 9, 3, 5, 7, 2 };
		int answer[] = solution(heights);

		for (int i = 0; i < answer.length; i++) {
			System.out.println(answer[i] + " ");
		}
	}
}