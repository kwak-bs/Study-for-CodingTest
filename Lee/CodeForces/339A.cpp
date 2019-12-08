#include <iostream> 
#include <ctype.h>
#include <cstring>
using namespace std;

int main(void)
{
	char cs[110];
	int count[4] = {0, };

	cin.getline(cs, 110);
	cin.clear();

	for(int i = 0; i < (signed)strlen(cs); i+=2) {
		switch(cs[i]) {
			case '1':
			count[(int)cs[i] - 49]++;
			break;
			case '2':
			count[1]++;
			break;
			case '3':
			count[2]++;
			break;
		}
	}


	do  {
		if(count[0] > 0) {
			cout << "1";
			count[0]--;
			continue;
		}
		else if(count[1] > 0) {
			cout << "2";
			count[1]--;
			continue;
		}
		else if(count[2] > 0) {
			cout << "3";
			count[2]--;
			continue;
		}
	} while(count[0] + count[1] + count[2] > 0 && cout << "+");

	return 0;
}