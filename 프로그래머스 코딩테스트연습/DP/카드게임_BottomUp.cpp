#include <string>
#include <vector>
#include<iostream>
#include <algorithm>

/*
https://www.welcomekakao.com/learn/courses/30/lessons/42896
(1) 양쪽 카드 모두 (2) 왼쪽 카드만 (3) 오른쪽 카드만 버리는 경우
dp[i][j] = 왼쪽 카드가 i, 오른쪽 카드가 j번째 카드일 때 최대 점수값
dp[i][j] = 위 3가지 경우 중 최대값
*/

using namespace std;

#define MAX 2000
int dp[MAX][MAX] = { 0, };

int solution(vector<int> left, vector<int> right) {

	int size = left.size();

	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= size; j++) {

			cout << endl<<"왼쪽 카드 " << i << " 오른쪽 카드 " << j << " 일 때" << endl;

			if (left[i - 1] > right[j - 1])	// (1) 오른쪽 카드 버리는 경우
			{
				dp[i][j] = dp[i][j - 1] + right[j - 1];
				cout << left[i - 1] << " > " << right[j - 1] << " 이므로 " << right[j - 1] << " 더하면 " << dp[i][j] << endl;
			}
			else	// (2)양쪽 카드 모두, (3) 왼쪽 카드만 버리는 경우
			{
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]);
				cout << left[i - 1] << " < " << right[j - 1] << " 이므로 " << dp[i][j] << endl;

			}
		}
	}

	return dp[size][size];	//얻을 수 있는 최종 점수의 최대값
}


int main(void) {

	vector<int> left = { 3,2,5 };	//왼쪽 더미의 카드
	vector<int> right = { 2,4,1 };	//오른쪽 더미의 카드

	int answer = solution(left, right);	//도둑이 훔칠 수 있는 돈의 최댓값

	cout << answer;
	return 0;
}