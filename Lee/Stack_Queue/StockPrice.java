package Programmers;

import java.util.Stack;

class Point {
	int idx;
	int value;

	Point(int idx, int value) {
		this.idx = idx;
		this.value = value;
	}
}

public class StockPrice {

	public static int[] solution(int[] prices) {
		int length = prices.length;
		int[] answer = new int[length];
		Stack<Point> s = new Stack<Point>();

		for (int i = 0; i < length - 1; i++) {
			if (!s.empty()) {
				if (prices[i] < s.peek().value) {
					while (!s.empty() && prices[i] < s.peek().value) {
						Point tmp = s.pop();
						answer[tmp.idx] = i - tmp.idx;
					}
				}
			}
			s.add(new Point(i, prices[i]));
		}

		while (!s.empty()) {
			Point tmp = s.pop();
			answer[tmp.idx] = length - 1 - tmp.idx;
		}

		return answer;
	}

	public static void main(String[] args) {
		int[] prices = { 1, 2, 3, 2, 3 };
		int[] tmp = solution(prices);

		for (int i = 0; i < tmp.length; i++) {
			System.out.println(tmp[i] + " ");
		}
	}
}