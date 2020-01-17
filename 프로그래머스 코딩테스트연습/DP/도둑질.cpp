#include <string>
#include <vector>
#include<iostream>
#include <algorithm>
using namespace std;

/*
https://www.welcomekakao.com/learn/courses/30/lessons/42897
������ ���׶��� ��ġ�Ǿ� �ִµ�, ������ �� ���� �и� �溸�� �︰��.
������ ��ĥ �� �ִ� ���� �ִ��� return.
dp[n]�� nĭ ������ �ִ� ��ģ ��
*/

int solution(vector<int> money) {

	int size = money.size();

	vector<int> dp(size);
	vector<int> dp2(size);

	//1) 0��° ���� �湮�� ���
	dp[0] = money[0];
	dp[1] = money[0];	//������ ���� �湮�� �� �����Ƿ�

	for (int i = 2; i < size - 1; i++) {
		dp[i] = max(dp[i - 1], dp[i - 2] + money[i]); // �湮 X vs �湮 O
	}

	//2) 0��° ���� �ݹ����� ���� ���
	dp2[0] = 0;
	dp2[1] = money[1];	//dp[1]�� money[1]�� ���ľ� �ִ��̹Ƿ�

	for (int i = 2; i < size; i++) {
		dp2[i] = max(dp2[i - 1], dp2[i - 2] + money[i]);
	}

	return max(dp[size - 2], dp2[size - 1]);
}

int main(void) {

	vector<int> money = { 1,2,3,1 };	//�� ���� �ִ� ��
	int answer = solution(money);	//������ ��ĥ �� �ִ� ���� �ִ�

	cout << answer;
	return 0;
}
