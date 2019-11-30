import java.util.Arrays;

// K번째 수
public class K {
	public static int[] solution(int[] array, int[][] commands) {
        int[] answer = new int[commands.length];		// 결과 개수
        int [] index;				// 답을 찾을 배열
        int first, last, target; // first부터 last까지 있는 원소 중 target번째
        int arr = 0, idx = 0; // arr: answer 배열의 인덱스, idx: 
        for (int i = 0; i < commands.length; i++) {
        	first = commands[i][0];
        	last = commands[i][1];
        	target = commands[i][2];
        	
        	index = new int[last - first+1];		// 배열 크기를 정하고 원소 삽입
        	for (int j = first-1; j < last; j++) 
        		index[idx++] = array[j];
        	
        	idx = 0;		// 다음을 위한 발판
        	Arrays.sort(index);
        	
        	answer[arr++] = index[target-1]; // 찾음
        }

        return answer;
    }

	public static void main(String[] args) {
		System.out.println(solution(new int[] {1, 5, 2, 6, 3, 7, 4}, new int[][] {{2,5,3},{4,4,1},{1,7,3}}));
	}
}
