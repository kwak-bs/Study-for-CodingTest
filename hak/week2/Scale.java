import java.util.Arrays;
class Solution {
    public static int solution(int[] weight) {
        Arrays.sort(weight);
        
        for (int i = 1;; i++) {
        	if (cal(weight, i) == 0)
        		return i;
        }
    }
	
	static int cal(int[] weight, int target) {
		for (int i = weight.length-1; i >= 0; i--) {
			if (weight[i] <= target)
				target -= weight[i];
			
			if (target == 0)
				return 1;
		}
		return 0;
	}
}
