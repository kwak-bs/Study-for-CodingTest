#include <iostream> 
#include <ctype.h>
#include <cstring>
using namespace std;

int main(void)
{
	char cs[110];
	cin.getline(cs, 110);

	int alphabet[26] = { 0,};
	int count = 0;

	for(int i = 0; i < (signed)strlen(cs); i++) {
		if(alphabet[cs[i]-97] == 0) {
			alphabet[cs[i]-97] = 1;
			count++;
		}
	}

	if(count % 2 == 0) {
		cout << "CHAT WITH HER!";
	}
	else {
		cout << "IGNORE HIM!";
	}

	cout << endl;

	return 0;
}