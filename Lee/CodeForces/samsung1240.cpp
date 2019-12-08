#include <iostream> 
#include <cstring>
#define codesLength 8
#define codeLength 7
using namespace std;

struct Point {
	int row;
	int col;
};

int N = 0, M = 0;

// 암호의 종료지점을 탐색
Point findCode(char cs[][M], Point startP) {
	int lastIndex = 0;
	for (int i = startP.row + 1; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if(cs[i][j] == 1) {
				lastIndex = j;
			}
		}
		if(lastIndex != 0) {
			Point p = {i, lastIndex};
			return p;
		}
	}
}

// 문자형 배열에서 이진 코드로 추출
char getBinary(char cs[][M], Point p) {
	char code = 0b0000000;
	for(int i = 0; i < codeLength; i++) {
		if(cs[p.row][p.col - i] == '1') {
			code += (1 << i);	
		}
	}
	return code;
}

int binary2Int(char code) {
	char numList[] = {
		0b0001101, 0b0011001, 0b0010011, 0b0111101, 0b0100011, 
		0b0110001, 0b0101111, 0b0111011, 0b0110111, 0b0001011
	};

	// 반전 연산 후 &연산시 동일하면 0이 나옴.
	for(int i = 0; i < 10; i++) {
		if(!(code & ~numList[i])) return i;
	}
	
	return -1;
	// char numList[][] = {
	// 	{'0', '0', '0', '1', '1', '0', '1'}, 
	// 	{'0', '0', '1', '1', '0', '0', '1'}, 
	// 	{'0', '0', '1', '0', '0', '1', '1'},
	// 	{'0', '1', '1', '1', '1', '0', '1'},
	// 	{'0', '1', '0', '0', '0', '1', '1'},
	// 	{'0', '1', '1', '0', '0', '0', '1'},
	// 	{'0', '1', '0', '1', '1', '1', '1'},
	// 	{'0', '1', '1', '1', '0', '1', '1'},
	// 	{'0', '1', '1', '0', '1', '1', '1'},
	// 	{'0', '0', '0', '1', '0', '1', '1'}
	// }
}

int check(int codes[]) {
	int result = (codes[0] + codes[2] + codes[4] + codes[6]) * 3 + codes[1] + codes[3] + codes[5] + codes[7];
	if(result % 10) {
		result -= (codes[0] + codes[2] + codes[4] + codes[6]) * 2;
	}
	else
		result = 0;
	return result;
}

int main(void)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> M;
		char cs[N][M];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> cs[i][j];
			}
		}
		Point p = {0, 0};

		ONE: 
		p = findCode(cs, p);
		int codes[codesLength] = {0, };
		for(int i = codesLength; i > 0; i--) {
			codes[i] = binary2Int(getBinary(cs, p));
			if(codes[i] == -1) goto ONE;
			p.col = p.col - codeLength - 1;
		}
		
		cout << "#" << test_case << " " << check(codes) << endl;
	}
	cout << endl;

	return 0;
}
