package Programmers;

import java.util.LinkedList;
import java.util.Queue;

public class Printer {

	public static int solution(int[] priorities, int location) {
		int answer = 0;
		Queue<String> q = new LinkedList<String>();
		Queue<Integer> qI = new LinkedList<Integer>();

		for (int i = 0; i < priorities.length; i++) {
			q.offer(Integer.toString(priorities[i]));
			qI.offer(i);
		}

		int count = 0;
		while (!q.isEmpty()) {
			count++;
			int peek = Integer.parseInt(q.peek());
			int max = peek;
			for (int i = peek + 1; i < 10; i++) {
				if (q.contains(Integer.toString(i))) {
					max = i;
				}
			}

			while (!q.peek().equals(Integer.toString(max))) {
				q.offer(q.poll());
				qI.offer(qI.poll());
			}

			if (qI.peek() == location) {
				answer = count;
				break;
			}

			System.out.print(q.poll() + " ");
			System.out.println(qI.poll());
		}

		return answer;
	}

	public static void main(String[] args) {
		int[] priorities = { 1, 1, 9, 1, 1, 1 };
		int location = 0;

		System.out.println(solution(priorities, location));

	}
}