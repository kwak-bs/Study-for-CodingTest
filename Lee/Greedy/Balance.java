package Programmers;

import java.util.Arrays;

public class Balance {

	public static int solution(int[] weight) {
		int e = 0;
		Arrays.sort(weight);

		for (int i = 0; i < weight.length; i++) {
			int num = weight[i];
			if (e + 1 < num) {
				return e + 1;
			} else {
				e = e + num;
			}
		}

		return e + 1;
	}

	public static void main(String[] args) {
		int[] weight = { 3, 1, 6, 2, 7, 30, 1 };

		System.out.println(solution(weight));

	}

}
