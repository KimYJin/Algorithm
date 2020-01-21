#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

#include <string>
#include <vector>
#include<algorithm>
#include<functional>

using namespace std;

int solution(vector<int> citations) {

	int answer = 0;

	sort(citations.begin(), citations.end(), greater<int>());

	for (int i = 0; i < citations.size(); i++) {
		
		cout << citations[i] << " " << i << endl;
		if (i >= citations[i])
		{
			cout << i;
			return i;
		}
	}

	cout << citations.size();
	return citations.size(); //논문의 개수가 인용수의 최소값보다 작은 경우 해당 조건을 만족하지 못하므로 논문의 수를 return (ex.{30,40})
}

int main() {

	vector<int>  citations = {3,0,6,1,5 };
	solution(citations);

	return 0;
}

