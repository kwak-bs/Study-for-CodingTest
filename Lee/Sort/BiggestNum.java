package Programmers;

import java.util.Arrays;
import java.util.Comparator;

public class BiggestNum {

	public static String solution(int[] numbers) {
		StringBuilder answer = new StringBuilder();

		String str_numbers[] = new String[numbers.length];

		for (int i = 0; i < str_numbers.length; i++)
			str_numbers[i] = Integer.toString(numbers[i]);

		Arrays.sort(str_numbers, new Comparator<String>() {
			@Override
			public int compare(String o1, String o2) {
				return (o2 + o1).compareTo(o1 + o2);
			}
		});

		for (String n : str_numbers)
			answer.append(n);

		if (answer.charAt(0) == '0')
			return "0";

		return answer.toString();
	}

	public static void main(String[] args) {
		int[] numbers = { 6, 10, 2 };

		System.out.println(solution(numbers));
	}
}