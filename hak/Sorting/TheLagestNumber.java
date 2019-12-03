import java.util.Arrays;

// 가장 큰 수
public class TheLagestNumber {
	public static String solution(int[] numbers) {
		String[] arr = new String[numbers.length];

		for (int i = 0; i < numbers.length; i++)
			arr[i] = String.valueOf(numbers[i]);
		
		// Arrays.sort Comparator
		Arrays.sort(arr, (o1, o2) -> (o2 + o1).compareTo(o1 + o2));

		if (arr[0].equals("0")) // 0만 있게 되는 경우
			return "0";

		StringBuffer sb = new StringBuffer();
		for (int i = 0; i < arr.length; i++)
			sb.append(arr[i]);

		return sb.toString();
	}

	public static void main(String[] args) {
		System.out.println(solution(new int[] { 0, 0, 1000, 0 }));
	}
}

// 출처 : https://youjourney.tistory.com/56
