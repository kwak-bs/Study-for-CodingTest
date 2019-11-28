import java.util.Arrays;
class Boat {
    public static int solution(int[] people, int limit) {
		Arrays.sort(people);
		
		int result = people.length;
		int j = people.length-1;
		for (int i = 0; j > i; j--) {
			int heavy = people[j];
			if (people[i] + heavy <= limit) {
				result--;
				i++;	
			}					
		}
		
		return result;
    }
}
