package Programmers;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class FunctionalDevelopment {

	public static int[] solution(int[] progresses, int[] speeds) {
		int[] answer = {};
		ArrayList<Integer> tempAnswer = new ArrayList<Integer>();
		int max = Integer.MIN_VALUE;
		Queue<Integer> q = new LinkedList<Integer>();

		for (int i = 0; i < progresses.length; i++) {
			double tmp = (double) (100 - progresses[i]) / speeds[i];
			q.offer((int) Math.ceil(tmp));
		}

		int count = 0;
		while (!q.isEmpty()) {
			if (max >= q.peek()) {
				q.poll();
				count++;
			} else {
				max = q.poll();
				tempAnswer.add(count + 1);
				count = 0;
			}
		}

		tempAnswer.add(count + 1);
		answer = new int[tempAnswer.size() - 1];

		for (int i = 0; i < answer.length; i++) {
			answer[i] = tempAnswer.get(i + 1);
		}
		return answer;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] progresses = { 93, 30, 55 };
		int[] speeds = { 1, 30, 5 };

		int[] tmp = solution(progresses, speeds);
		for (int i = 0; i < tmp.length; i++) {
			System.out.print(", " + tmp[i]);
		}

	}

}
