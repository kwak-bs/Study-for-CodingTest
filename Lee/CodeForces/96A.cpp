#include <iostream> 
#include <ctype.h>
#include <cstring>
using namespace std;

int main(void)
{
	char cs[110];
	int counter = 1;

	cin.getline(cs, 110);
	cin.clear();

	for(int i = 1; i < (signed)strlen(cs); i++) {
		if(counter > 6) {
			cout << "YES" << endl;
			return 0;
		}
		if(cs[i-1] == cs[i]) {
			counter++;
		}
		else {
			counter = 1;
		}

	}
	if(counter > 6) {
		cout << "YES" << endl;
		return 0;
	}
	
	cout << "NO" << endl;

	return 0;
}