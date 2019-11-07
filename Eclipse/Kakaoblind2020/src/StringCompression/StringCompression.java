package StringCompression;

public class StringCompression {

	public static int solution(String s) {
		int min = find(s, 1);

		for (int i = 2; i <= s.length(); i++) {
			int result = find(s, i);
			if (result < min) {
				min = result;
			}
		}

		return min;
	}

	public static int find(String s, int length) {
		String tmp = "";		// 직전에 자른 n-gram을 저장할 변수
		String split = "";		// 이번에 자른 n-gram을 저장할 변수
		int start = 0;			// 시작 index.
		int counter = 0;		// n-gram의 등장 횟수를 저장할 변수
		int result = 0;			// 결과 값

		// 자르는 범위가 문자열의 길이를 벗어날 때까지 반복
		while (start + length <= s.length()) {
			// start index부터 길이만큼 자름. ex) start = 3, length = 4    substring(3, 7) -> 3~6까지의 문자열이 return 됨.
			split = s.substring(start, start + length);

			// 새로 자른것이 이전것과 동일
			if (split.equals(tmp)) {
				counter++;
			}
			// 새로운 등장한 문자열이면
			else {
				// 2번 이상 등장한 경우 압축 문자열 앞에 숫자가 들어감.
				if (counter > 0) {
					result += (int) (Math.log10(counter + 1) + 1);		// 정수형 숫자의 길이를 구하는 부분, counter에 1을 더하는 이유는 10번 등장한 경우 count가 9이기 때문.
					counter = 0;
				}
				result += length; 	// 개수를 세기전에 새로운 문자열의 길이를 넣어줌, 즉 3abc2def의 경우 abc->3abc->3abcdef-> 3abc2def 순으로 result가 증가함.

			}
			tmp = split;			// 다음에 쓰기위해 이번에 자른 n-gram을 저장
			start += length; 		// 인덱스 이동
		}

		// 고려해야될 상황
		// 1. 위에서 딱 맞게 끝난 경우
		// 2. 위에서 오버해서 끝난 경우
		if (start == s.length()) {
			if (counter > 0) {
				result += (int) (Math.log10(counter + 1) + 1);
			}
		} else if (start < s.length() && start + length > s.length()) {
			if (counter > 0) {
				result += (int) (Math.log10(counter + 1) + 1);
			}
			result += (s.length() - start);
		}

		return result;
	}

	public static void main(String[] args) {
		String s = "aabbaccc";
		
		System.out.println(solution(s));
	}
}
