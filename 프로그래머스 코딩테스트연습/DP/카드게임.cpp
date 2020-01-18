#include <string>
#include <vector>
#include<iostream>
#include <algorithm>

using namespace std;

#define MAX 2000

int dp[MAX][MAX] = { 0, };	//점화식: D[i][j] = 왼쪽 카드가 i, 오른쪽 카드가 j번째 카드일 때 최대 점수값
int num=0;
vector<int> L, R;

/*
https://www.welcomekakao.com/learn/courses/30/lessons/42896
(1) 양쪽 카드 모두 (2) 왼쪽 카드만 (3) 오른쪽 카드만 버리는 경우
dp[i][j] = 왼쪽 카드가 i, 오른쪽 카드가 j번째 카드일 때 최대 점수값
dp[i][j] = 위 3가지 경우 중 최대값 
*/

int step(int i, int j) {

	if (i >= num || j >= num) 
		return 0;

	if (dp[i][j] > 0)
		return dp[i][j];

	//왼쪽 또는 양쪽 카드 버리는 경우
	dp[i][j] = max(step(i + 1, j), step(i + 1, j + 1));

	//오른쪽 카드 버리는 경우
	if (L[i] > R[j]) {
		dp[i][j] = max(dp[i][j], step(i, j + 1) + R[j]);
	}

	return dp[i][j];
}

int solution(vector<int> left, vector<int> right) {	
	L = left; R = right;
	num = left.size();
	return step(0,0);	//얻을 수 있는 최종 점수의 최대값
}

int main(void) {

	vector<int> left = { 3,2,5 };	//왼쪽 더미의 카드
	vector<int> right = { 2,4,1 };	//오른쪽 더미의 카드

	int answer = solution(left,right);	//도둑이 훔칠 수 있는 돈의 최댓값

	cout << answer;
	return 0;
}
