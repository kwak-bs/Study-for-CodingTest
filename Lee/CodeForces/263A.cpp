#include <iostream> 
#include <cstdlib>
using namespace std;

int main(void)
{
	int zeroOrOne = 0;
	int size = 25;
	int result = 0;

	for(int i=0; i<size; i++) {
		cin >> zeroOrOne;
		if(zeroOrOne == 1)
			result = abs(2 - i/5) + abs(2 - i%5);
	}

	cout << result << endl;

	return 0;
}
