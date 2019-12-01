/*
https://www.welcomekakao.com/learn/courses/30/lessons/42747
*/

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int index(0);
    
    // citations를 내림차순으로 sort
    sort(citations.begin(), citations.end(), greater<int>());

    // citation[index] 값이 index 보다 작거나 같으면 해당 index가 H-Index
    while(index < citations.size()){
        if(citations[index] <= index) break;
        index++;
    }

    return index;
}

/*
citations = [7, 6, 4, 1, 1, 0]

index   citations[ans]
  0         7
  1         6
  2         4
  3         1          -> citations[index] <= index
  4         1
  5         0
  
H-Index = 3
*/
