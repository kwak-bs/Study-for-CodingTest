#include <iostream> 
using namespace std;

int main(void)
{
	int n, k;
	cin >> n >> k;

	int a [n];
	int count = 0;

	for(int i = 0; i < n; i++) {
		cin >> a[i];
		// cout << a[i] << " ";
	}

	for(int i=0; i<n; i++) {
		if(a[i] >= a[k-1] && a[i] > 0) count++;
		else break;
	}

	// if(a[k-1] == 0) {
	// 	if(a[0] == 0) {
	// 		count = 0;
	// 	}
	// 	else {
	// 		for(int i=k-1; i>=0; i--) {
	// 			if(a[i] > 0) {
	// 				count = i;
	// 				break;
	// 			}
	// 		}
	// 	}
	// }
	// else {
	// 	for(int i = k; i < n; i++) {
	// 		if(a[i] < a[i-1]) {
	// 			break;
	// 		}
	// 		else
	// 			count++;
	// 	}
	// }

	cout << count << endl;

	return 0;
}
