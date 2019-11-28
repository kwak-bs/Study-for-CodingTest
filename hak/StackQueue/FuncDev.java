import java.util.LinkedList;
import java.util.Queue;

// 기능개발
public class FuncDev {
	public static int[] solution(int[] progresses, int[] speeds) {
		int[] pro = progresses;		// 복사본
		Queue<Integer> result= new LinkedList<>();	// 배포 수 저장
		int index = 0, count = 0;		// index: 배포할 수 있는 기준, count: 한 번에 배포되는 수
		
		while(index < pro.length) {	// 
			for (int i = 0; i < pro.length; i++)	// 하루 진도율 처리
				pro[i] += speeds[i];
			
			if (pro[index] >= 100) {	// index 작업이 배포될 수 있으면
				while(index < pro.length && pro[index] >= 100) {	// 다른 것도 같이 배포될 수 있는지
					count++;
					index++;
				}
				
				result.offer(count);		// 한 번에 배포된 개수 저장
				count = 0;
			}
		}
			
		int[] answer = new int[result.size()];
		for (int i = 0; i < answer.length; i++)
			answer[i] = result.poll();
		
        return answer;
    }
	
	public static void main(String[] args) {
		System.out.println(solution(new int[] {93,30,55}, new int[] {1,30,5}));
	}
}
