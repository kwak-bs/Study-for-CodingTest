package Programmers;

import java.util.Arrays;

public class Lifeboat {
	// 한번에 최대 2명
	public static int solution(int[] people, int limit) {
		Arrays.sort(people);

		int answer = 0;
		int index = people.length - 1;
		for (int i = 0; i <= index; i++, answer++)
			while (index > i && people[i] + people[index--] > limit)
				answer++;

		return answer;
	}

	public static void main(String[] args) {
		int[] people = { 70, 50, 80, 50 };
		int limit = 100;

		System.out.println(solution(people, limit));
	}
}