#include <string>
#include <vector>
#include<iostream>

using namespace std;

#define MAX 80

//정사각형 타일 한 변의 길이 1, 1, 2, 3, 5, 8, ... 피보나치
//이러한 타일들로 구성되는 큰 직사각형의 둘레 return
long long solution(int N) {
	long long answer = 0;

	long long d[MAX + 1] = { 0, };		//타일 한 변의 길이
	long long len[MAX + 1] = { 0, };	//직사각형 둘레

	d[1] = 1; 
	d[2] = 1;
	len[1] = d[1] * 4;

	for (int n = 3; n <= N; ++n) {
		d[n] = d[n - 2] + d[n - 1];
		cout << d[n]<<endl;
	}

	for (int n = 2; n <= N; ++n) {
		len[n] = len[n - 1] + d[n] * 2;
	}

	if(len[N]>0)
		return len[N];
}

int main(void) {

	int N = 5;
	long long answer = solution(N);

	cout << answer;

	return 0;
}