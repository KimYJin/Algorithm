#include <string>
#include <vector>
#include<iostream>
#include <algorithm>

/*
https://www.welcomekakao.com/learn/courses/30/lessons/42896
(1) ���� ī�� ��� (2) ���� ī�常 (3) ������ ī�常 ������ ���
dp[i][j] = ���� ī�尡 i, ������ ī�尡 j��° ī���� �� �ִ� ������
dp[i][j] = �� 3���� ��� �� �ִ밪
*/

using namespace std;

#define MAX 2000
int dp[MAX][MAX] = { 0, };

int solution(vector<int> left, vector<int> right) {

	int size = left.size();

	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= size; j++) {

			cout << endl<<"���� ī�� " << i << " ������ ī�� " << j << " �� ��" << endl;

			if (left[i - 1] > right[j - 1])	// (1) ������ ī�� ������ ���
			{
				dp[i][j] = dp[i][j - 1] + right[j - 1];
				cout << left[i - 1] << " > " << right[j - 1] << " �̹Ƿ� " << right[j - 1] << " ���ϸ� " << dp[i][j] << endl;
			}
			else	// (2)���� ī�� ���, (3) ���� ī�常 ������ ���
			{
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]);
				cout << left[i - 1] << " < " << right[j - 1] << " �̹Ƿ� " << dp[i][j] << endl;

			}
		}
	}

	return dp[size][size];	//���� �� �ִ� ���� ������ �ִ밪
}


int main(void) {

	vector<int> left = { 3,2,5 };	//���� ������ ī��
	vector<int> right = { 2,4,1 };	//������ ������ ī��

	int answer = solution(left, right);	//������ ��ĥ �� �ִ� ���� �ִ�

	cout << answer;
	return 0;
}