package Programmers;

import java.util.Arrays;

public class KthNumber {
	public static int[] solution(int[] array, int[][] commands) {
		int[] answer = new int[commands.length];
		int count = 0;

		for (int i = 0; i < commands.length; i++) {
			int begin = commands[i][0];
			int end = commands[i][1];
			int k = commands[i][2];

			int[] arr = new int[end - begin + 1];

			for (int j = begin - 1; j < end; j++)
				arr[j - begin + 1] = array[j];

			Arrays.sort(arr);
			answer[count++] = arr[k-1];
		}

		return answer;
	}

	public static void main(String[] args) {
		int[] array = { 1, 5, 2, 6, 3, 7, 4 };
		int[][] commands = { { 2, 5, 3 }, { 4, 4, 1 }, { 1, 7, 3 } };

		int[] answer = solution(array, commands);

		for (int n : answer) {
			System.out.println(n);
		}
	}
}