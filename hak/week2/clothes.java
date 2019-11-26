import java.util.Arrays;
import java.util.ArrayList;
class Solution {
    static ArrayList<Integer> max;
	public static int solution(int n, int[] lost, int[] reserve) {
		boolean[] isSpare = new boolean[reserve.length];
		for (int i = 0; i < isSpare.length; i++) {
			if (reserve[i] != 0)
				isSpare[i] = true;
		}
		max = new ArrayList<Integer>();
		Arrays.sort(lost);
		Arrays.sort(reserve);
		Greedy(n - lost.length, 0, lost, reserve, isSpare);

		int result = 0;
		for (int tmp : max) {
			if (tmp > result)
				result = tmp;
		}
		//System.out.println("result : " + result);
		return result;
	}

	static void Greedy(int clothes, int lostIndex, int[] lost, int[] reserve, boolean[] isSpare) {
		if (lostIndex == 0)
			max.add(clothes);

		if (lostIndex == lost.length) {
			max.add(clothes);
			//System.out.println("clothes: " + clothes);
			return;
		}
		
		if (useList(reserve, lost[lostIndex])) {
			//System.out.print("현재 " + lost[lostIndex] + ", ");
			int index = Arrays.binarySearch(reserve, lost[lostIndex]);
			//System.out.print(lost[lostIndex] + "->" + reserve[index] + ", " + isSpare[index] + " ");
			if (index == 0) {
				if (reserve[0] == lost[lostIndex] && isSpare[index]) {
					clothes++;
					isSpare[index] = false;
					Greedy(clothes, lostIndex + 1, lost, reserve, isSpare);
					clothes--;
					isSpare[index] = true;
				}
			}

			else {
				if (isSpare[index]) {
					clothes++;
					isSpare[index] = false;
					Greedy(clothes, lostIndex + 1, lost, reserve, isSpare);
					clothes--;
					isSpare[index] = true;
				}
			}
		}
		
		else {
			if (useList(reserve, lost[lostIndex] - 1)) {
				//System.out.print("현재 " + lost[lostIndex] + ", ");
				int index = Arrays.binarySearch(reserve, lost[lostIndex] - 1);
				//System.out.print(lost[lostIndex] + "->" + reserve[index] + ", " + isSpare[index] + " ");
				if (index == 0) {
					if (reserve[0] == lost[lostIndex] - 1 && isSpare[index]) {
						clothes++;
						isSpare[index] = false;
						Greedy(clothes, lostIndex + 1, lost, reserve, isSpare);
						clothes--;
						isSpare[index] = true;
					}
				}

				else {
					if (isSpare[index]) {
						clothes++;
						isSpare[index] = false;
						Greedy(clothes, lostIndex + 1, lost, reserve, isSpare);
						clothes--;
						isSpare[index] = true;
					}
				}
			}

			if (useList(reserve, lost[lostIndex] + 1)) {
				//System.out.print("현재 " + lost[lostIndex] + ", ");
				int index = Arrays.binarySearch(reserve, lost[lostIndex] + 1);
				//System.out.print(lost[lostIndex] + "->" + reserve[index] + ", " + isSpare[index] + " ");
				if (index == 0) {
					if (reserve[0] == lost[lostIndex] + 1 && isSpare[index]) {
						clothes++;
						isSpare[index] = false;
						Greedy(clothes, lostIndex + 1, lost, reserve, isSpare);
						clothes--;
						isSpare[index] = true;
					}
				}

				else {
					if (isSpare[index]) {
						clothes++;
						isSpare[index] = false;
						Greedy(clothes, lostIndex + 1, lost, reserve, isSpare);
						clothes--;
						isSpare[index] = true;
					}
				}
			}
		}

		Greedy(clothes, lostIndex + 1, lost, reserve, isSpare);
	}

	// https://jjeong.tistory.com/1250
	public static boolean useList(int[] arr, int targetValue) {

		int result = Arrays.binarySearch(arr, targetValue);
		// System.out.println("useLst " + targetValue + " " + result);
		if (result == 0 && arr[0] == targetValue)
			result = 1;

		return result > 0 ? true : false;
	}
}
