#include <string>
#include <vector>
#include<iostream>

using namespace std;

#define MAX 80

//���簢�� Ÿ�� �� ���� ���� 1, 1, 2, 3, 5, 8, ... �Ǻ���ġ
//�̷��� Ÿ�ϵ�� �����Ǵ� ū ���簢���� �ѷ� return
long long solution(int N) {
	long long answer = 0;

	long long d[MAX + 1] = { 0, };		//Ÿ�� �� ���� ����
	long long len[MAX + 1] = { 0, };	//���簢�� �ѷ�

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