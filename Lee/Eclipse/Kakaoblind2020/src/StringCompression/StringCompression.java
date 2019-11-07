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
		String tmp = "";		// ������ �ڸ� n-gram�� ������ ����
		String split = "";		// �̹��� �ڸ� n-gram�� ������ ����
		int start = 0;			// ���� index.
		int counter = 0;		// n-gram�� ���� Ƚ���� ������ ����
		int result = 0;			// ��� ��

		// �ڸ��� ������ ���ڿ��� ���̸� ��� ������ �ݺ�
		while (start + length <= s.length()) {
			// start index���� ���̸�ŭ �ڸ�. ex) start = 3, length = 4    substring(3, 7) -> 3~6������ ���ڿ��� return ��.
			split = s.substring(start, start + length);

			// ���� �ڸ����� �����Ͱ� ����
			if (split.equals(tmp)) {
				counter++;
			}
			// ���ο� ������ ���ڿ��̸�
			else {
				// 2�� �̻� ������ ��� ���� ���ڿ� �տ� ���ڰ� ��.
				if (counter > 0) {
					result += (int) (Math.log10(counter + 1) + 1);		// ������ ������ ���̸� ���ϴ� �κ�, counter�� 1�� ���ϴ� ������ 10�� ������ ��� count�� 9�̱� ����.
					counter = 0;
				}
				result += length; 	// ������ �������� ���ο� ���ڿ��� ���̸� �־���, �� 3abc2def�� ��� abc->3abc->3abcdef-> 3abc2def ������ result�� ������.

			}
			tmp = split;			// ������ �������� �̹��� �ڸ� n-gram�� ����
			start += length; 		// �ε��� �̵�
		}

		// ����ؾߵ� ��Ȳ
		// 1. ������ �� �°� ���� ���
		// 2. ������ �����ؼ� ���� ���
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
