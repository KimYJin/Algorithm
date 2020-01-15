#include <string>
#include <vector>
#include<iostream>

using namespace std;

//https://www.welcomekakao.com/learn/courses/30/lessons/43104
//정사각형 타일 한 변의 길이 1, 1, 2, 3, 5, 8, ... 피보나치
//이러한 타일들로 구성되는 큰 직사각형의 둘레 return


long long solution(int N) {
	long long answer = 0;

	vector<long long> d;	//타일 한 변의 길이

	d.push_back(0);
	d.push_back(1);

	for (int n = 2; n <= N; ++n) {
		d.push_back(d[n - 2] + d[n - 1]);
	}

	return d[N] * 4 + d[N - 1] * 2;
}

int main(void) {

	int N = 5;
	long long answer = solution(N);

	cout << answer;

	return 0;
}