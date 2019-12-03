package Programmers;

import java.util.LinkedList;
import java.util.Queue;

public class BridgeTruck {
	public static int solution(int bridge_length, int weight, int[] truck_weights) {
		int answer = 0;
		int sumOfWeight = 0;
		int insertIndex = 0;
		int deleteIndex = 0;
		Queue<Integer> q = new LinkedList<Integer>();

		while (deleteIndex < truck_weights.length) {
			if (!q.isEmpty() && q.peek() == answer) {
				q.poll();
				sumOfWeight -= truck_weights[deleteIndex++];
			}
			if (insertIndex < truck_weights.length) {

				int tmp = sumOfWeight + truck_weights[insertIndex];
				if (tmp <= weight) {
					sumOfWeight += truck_weights[insertIndex++];
					q.offer(answer + bridge_length);
				}
			}
			answer++;
		}

		return answer;
	}

	public static void main(String[] args) {
		int bridge_length = 100;
		int weight = 100;
		int[] truck_weights = { 10,10,10,10,10,10,10,10,10,10 };

		int s = solution(bridge_length, weight, truck_weights);
		System.out.println(s);
	}
}