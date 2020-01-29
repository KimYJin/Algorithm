/*
https://www.welcomekakao.com/learn/courses/30/lessons/42899
���￡�� ����� �ٸ� ���ø� ������ ������� �� �� �� �湮�� �� ������� ����
K�ð� �̳��� �����ϸ� ���� �� �ִ� �ִ� ��ݾ�
dp[i][j] -> i ���ÿ�, j �ð��� �ִ� ��ݾ�
travel �迭�� �� ���� [���� �ð�, ���� ��ݾ�, ������ �ð�, ������ ��ݾ�]
*/

#include <string>
#include <vector>
#include<iostream>
#include<algorithm>

using namespace std;

const int MAX1 = 100;
const int MAX2 = 100001;
int dp[MAX1][MAX2] = { 0, };

int solution(int K, vector<vector<int>> travel) {

	int answer = 0;
	int t_size = travel.size();
	
	dp[0][travel[0][0]] = travel[0][1];
	dp[0][travel[0][2]] = travel[0][3];

	for (int i = 1; i < t_size; i++) {	//����

		for (int j = 0; j <= K; j++) {	//�ð�

			if (dp[i - 1][j] == 0) //���� ���ÿ� j�ð��� ������ ����� ������ ����
				continue;	

			//�� ���ñ��� ���� ��ݾ� vs ���� ���÷κ��� ������ �̵��� ������ ��ݾ�
			if (j + travel[i][0] <= K)
				dp[i][j + travel[i][0]] = max(dp[i][j + travel[i][0]], dp[i - 1][j] + travel[i][1]);

			//�� ���ñ��� ���� ��ݾ� vs ���� ���÷κ��� �����ñ��� �����ŷ� �̵��� ������ ��ݾ�
			if (j + travel[i][2] <= K) 
				dp[i][j + travel[i][2]] = max(dp[i][j + travel[i][2]], dp[i - 1][j] + travel[i][3]);
		}
	}
	for (int j = 0; j <= K; j++) {
		answer = max(answer, dp[t_size - 1][j]);
	}

	return answer;
}

int main(void) {
	int K = 3000;
	vector<vector<int>> travel = { { 1000, 2000, 300, 700 },
	{ 1100, 1900, 400, 900 },
	{ 900, 1800, 400, 700 },{ 1200, 2300, 500, 1200 } };
	
	cout << solution(K, travel);

	return 0;
}

