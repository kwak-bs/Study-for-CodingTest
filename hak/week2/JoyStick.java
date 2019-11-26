import java.util.ArrayList;
class Solution {
    static ArrayList<Integer> min;
	public static int solution(String name) {
		min = new ArrayList<Integer>();
		String temp = "A";
		for (int i = 1; i < name.length(); i++)
			temp += "A";
		
		leftGreedy(0, temp, name, 0, 1);
		rightGreedy(0, temp, name, 0, 1);
		int result = 1000;
		for (int tmp : min) {
			if (tmp < result)
				result = tmp;
		}
		//System.out.println("result2 : " + result);
		return result;
    }
	
	static void leftGreedy(int count, String current, String finish, int index, int size) {
		if (size > current.length())
			return;
		
		char tmp = finish.charAt(index);
		int Tcount = shortAl(tmp) + count;
		if (index == current.length()-1)
			current = current.substring(0, index) + tmp;
		else
			current = current.substring(0, index) + tmp + current.substring(index+1, current.length());
		//System.out.println("count " + count + " tmp " + tmp + " finish" + finish.charAt(index) + " replace " + Tcount);
		
		if (current.equals(finish)) {
			//System.out.println("result " + Tcount);
			min.add(Tcount);
			return;
		}
		
		leftGreedy(Tcount+1, current, finish, Left(index, current), size+1);
		rightGreedy(Tcount+1, current, finish, Right(index, current), size+1);
	}
	
	static void rightGreedy(int count, String current, String finish, int index, int size) {
		if (size > current.length())
			return;
		
		char tmp = finish.charAt(index);
		int Tcount = shortAl(tmp) + count;
		if (index == current.length()-1)
			current = current.substring(0, index) + tmp;
		else
			current = current.substring(0, index) + tmp + current.substring(index+1, current.length());
		//System.out.println("count " + count + " tmp " + tmp + " finish" + finish.charAt(index) + " replace " + Tcount);
		
		if (current.equals(finish)) {
			//System.out.println("result " + Tcount);
			min.add(Tcount);
			return;
		}
		
		rightGreedy(Tcount+1, current, finish, Right(index, current), size+1);
		leftGreedy(Tcount+1, current, finish, Left(index, current), size+1);
	}
	
	// nextAl
	static char Up(char temp) {
		return (char) (temp == 'Z' ? 'A' : temp+1);
	}
	
	// preAl
	static char Down(char temp) {
		return (char) (temp == 'A' ? 'Z' : temp-1);
	}
	
	static int shortAl(char temp) {
		int up = 0;
		int down = 0;
		char tmp = 'A';
		
		for (int i = 0; tmp != temp; i++) {
			up++;
			tmp = Up(tmp);
		}
		
		tmp = 'A';
		for (int i = 0; tmp != temp; i++) {
			down++;
			tmp = Down(tmp);
		}
		
		return up >= down ? down : up;
	}
	
	static int Left(int idx, String name) {
		return idx <= 0 ? name.length()-1 : idx-1;
	}
	
	static int Right(int idx, String name) {
		return idx >= name.length()-1 ? 0 : idx+1;
	}
}
