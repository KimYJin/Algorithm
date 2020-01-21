#include <string>
#include <vector>
#include<iostream>

using namespace std;

//https://www.welcomekakao.com/learn/courses/30/lessons/43104
//���簢�� Ÿ�� �� ���� ���� 1, 1, 2, 3, 5, 8, ... �Ǻ���ġ
//�̷��� Ÿ�ϵ�� �����Ǵ� ū ���簢���� �ѷ� return


long long solution(int N) {
	long long answer = 0;

	vector<long long> d;	//Ÿ�� �� ���� ����

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