#include <string>
#include <vector>
#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

/*
 https://www.welcomekakao.com/learn/courses/30/lessons/42898
 집(1,1)에서 학교 (m,n)까지 갈 수 있는 최단경로의 개수를 
 1,000,000,007로 나눈 나머지를 return

 optimal substrcture: 최단경로의 부분 경로는 역시 최단경로.
 DP 또는 탐욕 알고리즘으로 효율적으로 풀 수 있음.
 DP 활용. (x, y) 경로 수 =  (x - 1, y) 경로 수 + (x, y - 1) 경로 수
*/

#define MAX 100

int solution(int m, int n, vector<vector<int>> puddles) {

	int dp[MAX + 1][MAX + 1] = { 0, };
	dp[1][1] = 1;

	for (int i = 0; i < puddles.size(); i++) {
			dp[puddles[i][1]][puddles[i][0]] = -1;	//웅덩이 -1로 초기화
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {

			if (dp[i][j] == -1)	//웅덩이
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
	int m = 4, n = 3; //격자의 크기 mxn
	vector<vector<int>> puddles = { {2,2} };	//물이 잠긴 지역의 좌표
	int answer = solution(m, n, puddles);

	cout << answer;
	return 0;
}
