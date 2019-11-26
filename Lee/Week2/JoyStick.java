package Programmers;

public class JoyStick {

	public static int solution(String name) {
		int answer = 0;
		StringBuilder madeName = new StringBuilder();
		boolean[] made = new boolean[name.length()];

		for (int i = 0; i < name.length(); i++) {
			madeName.append("A");
			if (name.charAt(i) == 'A')
				made[i] = true;
		}

		int index = 0;
		while (!name.equals(madeName.toString())) {
			// A에서 아래로 이동하면 Z
			if (name.charAt(index) > 'N')
				answer = answer + 'Z' - name.charAt(index) + 1;
			else
				answer = answer + name.charAt(index) - 'A';

			madeName.replace(index, index + 1, name.substring(index, index + 1));
			made[index] = true;

			int count = 0;
			int before = index;
			int after = index;
			while (true) {
				count++;
				before = before - 1;
				after = after + 1;

				if (count >= name.length() / 2) {
					index++;
					if (index >= name.length())
						index = 0;
					answer++;

					break;
				}

				if (before < 0)
					before = name.length() - 1;
				if (after >= name.length())
					after = 0;
				
				if (name.charAt(after) != 'A' && !made[after]) {
					answer += count;
					index = after;
					break;
				} else if (name.charAt(before) != 'A' && !made[before]) {
					answer += count;
					index = before;
					break;
				}
			}
		}
		return answer - 1;
	}

	public static void main(String[] args) {
		String name = "BBAABB";
		System.out.println(solution(name));
	}
}