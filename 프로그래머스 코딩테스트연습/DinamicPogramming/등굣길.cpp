#include <string>
#include <vector>
#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

/*
 https://www.welcomekakao.com/learn/courses/30/lessons/42898
 ��(1,1)���� �б� (m,n)���� �� �� �ִ� �ִܰ���� ������ 
 1,000,000,007�� ���� �������� return

 optimal substrcture: �ִܰ���� �κ� ��δ� ���� �ִܰ��.
 DP �Ǵ� Ž�� �˰������� ȿ�������� Ǯ �� ����.
 DP Ȱ��. (x, y) ��� �� =  (x - 1, y) ��� �� + (x, y - 1) ��� ��
*/

#define MAX 100

int solution(int m, int n, vector<vector<int>> puddles) {

	int dp[MAX + 1][MAX + 1] = { 0, };
	dp[1][1] = 1;

	for (int i = 0; i < puddles.size(); i++) {
			dp[puddles[i][1]][puddles[i][0]] = -1;	//������ -1�� �ʱ�ȭ
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {

			if (dp[i][j] == -1)	//������
			{
				dp[i][j] = 0;
				continue;
			}

			dp[i][j] += (dp[i - 1][j] + dp[i][j - 1]) % 1000000007;
		}
	}

	/*
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	
	return dp[n][m];
}

int main(void) {
	int m = 4, n = 3; //������ ũ�� mxn
	vector<vector<int>> puddles = { {2,2} };	//���� ��� ������ ��ǥ
	int answer = solution(m, n, puddles);

	cout << answer;
	return 0;
}
