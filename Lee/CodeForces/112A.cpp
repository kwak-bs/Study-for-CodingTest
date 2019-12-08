#include <iostream> 
#include <ctype.h>
#include <cstring>
using namespace std;

int main(void)
{
	char cs1[110];
	char cs2[110];
	int result = 0;

	cin.getline(cs1, 110);
	cin.clear();

	cin.getline(cs2, 110);
	cin.clear();

	for(int i = 0; i < (signed)strlen(cs1); i++) {
		cs1[i] = tolower(cs1[i]);
		cs2[i] = tolower(cs2[i]);

		if(cs1[i] - cs2[i] > 0) {
			result = 1;
			break;
		}
		else if(cs1[i] - cs2[i] < 0) {
			result = -1;
			break;
		}
	}

	cout << result << endl;

	return 0;
}