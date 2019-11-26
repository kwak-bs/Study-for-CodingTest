package Programmers;

import java.util.Arrays;
import java.util.Comparator;

public class CCTV {

	public static int solution(int[][] routes) {
		int answer = 0;

		Arrays.sort(routes, new Comparator<int[]>() {
			@Override
			public int compare(int[] o1, int[] o2) {
				return Integer.compare(o1[1], o2[1]);
				// �� ��° �׸��� �������� �������� ����
				// ù ��° �׸����� �����Ϸ��� o1[0]�� o2[0]�� ���� �ָ� �ȴ�.
			}
		});

		for (int i = 0; i < routes.length; i++) {
			System.out.println(routes[i][0] + " " + routes[i][1]);
		}

		int cameraPos = -30001;
		for (int i = 0; i < routes.length; i++) {
			if (cameraPos < routes[i][0]) {
				answer++;
				cameraPos = routes[i][1];
			}
		}
		return answer;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[][] routes = { { -20, -15 }, { -14, -5 }, { -18, -13 }, { -5, -3 } };

		System.out.println(solution(routes));

	}

}
