package Programmers;

public class GymClothes {

	public static int solution(int n, int[] lost, int[] reserve) {
		int answer = 0;
		// 바로 앞이나 뒤 학생에게만 빌려줌

		int student[] = new int[n + 1];
		for (int i = 0; i < reserve.length; i++)
			student[reserve[i]]++;

		for (int i = 0; i < lost.length; i++)
			student[lost[i]]--;

		for (int i = 1; i < student.length; i++) {
			if (student[i] >= 0) {
				continue;
			}
			if (i + 1 < student.length && student[i + 1] == 1) {
				student[i + 1]--;
				student[i]++;
			}
			if (student[i - 1] == 1) {
				student[i - 1]--;
				student[i]++;
			}
		}
		
		for (int i = 1; i < student.length; i++) {
			if (student[i] >= 0) {
				answer++;
			}
		}

		return answer;
	}

	public static void main(String[] args) {
		int n = 3;
		int[] lost = { 3 };
		int[] reserve = { 1 };

		System.out.println(solution(n, lost, reserve));
	}

}
