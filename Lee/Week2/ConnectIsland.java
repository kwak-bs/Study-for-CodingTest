package Programmers;

public class ConnectIsland {

	public static int solution(int n, int[][] costs) {
		int answer = 0;
		int[][] map = new int[n][n];
		for (int i = 0; i < costs.length; i++) {
			map[costs[i][0]][costs[i][1]] = costs[i][2];
			map[costs[i][1]][costs[i][0]] = costs[i][2];
		}
		boolean[] connected = new boolean[n];
		connected[0] = true;
		answer = prim(map, connected, 0, 1);

		return answer;
	}

	public static int prim(int[][] map, boolean[] connected, int value, int count) {
		if (count == connected.length)
			return value;
		int to = -1;
		int min = Integer.MAX_VALUE;
		for (int i = 0; i < connected.length; i++) {
			if (connected[i]) {
				for (int j = 0; j < map.length; j++) {
					if (!connected[j] && map[i][j] != 0 && min > map[i][j]) {
						to = j;
						min = map[i][j];
					}
				}
			}
		}
		connected[to] = true;
		value += min;
		count++;
		return prim(map, connected, value, count);
	}

	public static void main(String[] args) {
		int n = 4;
		int[][] costs = { { 0, 1, 1 }, { 0, 2, 2 }, { 1, 2, 5 }, { 1, 3, 1 }, { 2, 3, 8 } };

		System.out.println(solution(n, costs));

	}
}