public class test {

	public static void main(String[] args) {
		String s = "ababababababababababcdcd";
		System.out.println(s);
		
		int min[] = new int[s.length()];
		int index = 0;
		for (int i = 1; i < s.length()/2+1; i++) {
			String result = task(s, i);		
			//System.out.println(result + " " + result.length());
			if (!result.equals("error"))
				min[index++] += result.length();
			//System.out.println("resultㅁㅁㅁ: " + i + "개씩 " + result + " " + result.length());
		}
		
		
		int mini = s.length();
		for (int i = 0; i < min.length; i++) {
			//System.out.println("min " + min[i]);
			int tmpMin = min[i];
			if (tmpMin < mini && min[i] != 0)
				mini = tmpMin;
		}
		System.out.println("value: " + mini);
	}
	
	static String task(String s, int n) {
		int count = 1;
		String nextTmp = "";
		String result = "";
		
		for (int i = 0; i < s.length(); i+=n) {
			String tmp;
			if (i+n <= s.length())
				tmp = s.substring(i, i+n);
			else
				tmp = s.substring(i, s.length());
			//System.out.println("tmp: " + tmp);
			
			if (i+n <= s.length() && i+n+n <= s.length())
				nextTmp = s.substring(i+n, i+n+n);
			else
				nextTmp = "";
			
			if (tmp.equals(nextTmp)) 
				count++;
			else {
				result += count + tmp;
				count = 1;
			}		
			
			//System.out.println("result: " + result);
		}
		
		//System.out.println("------------------------------");
		// temp
		nextTmp = result;
		result = "";
		
		for (int i = 0; i < nextTmp.length(); i++) {
			if (nextTmp.charAt(i) == '1' && !('0' <= nextTmp.charAt(i+1) && nextTmp.charAt(i+1) <= '9'))
				continue;
			else
				result += nextTmp.charAt(i);
		}
		return result;
	}
}