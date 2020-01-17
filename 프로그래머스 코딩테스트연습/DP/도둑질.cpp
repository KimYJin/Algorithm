#include <string>
#include <vector>
#include<iostream>
#include <algorithm>
using namespace std;

/*
https://www.welcomekakao.com/learn/courses/30/lessons/42897
집들이 동그랗게 배치되어 있는데, 인접한 두 집을 털면 경보가 울린다.
도둑이 훔칠 수 있는 돈의 최댓값을 return.
dp[n]은 n칸 집까지 최대 훔친 돈
*/

int solution(vector<int> money) {

	int size = money.size();

	vector<int> dp(size);
	vector<int> dp2(size);

	//1) 0번째 집을 방문한 경우
	dp[0] = money[0];
	dp[1] = money[0];	//인접한 집은 방문할 수 없으므로

	for (int i = 2; i < size - 1; i++) {
		dp[i] = max(dp[i - 1], dp[i - 2] + money[i]); // 방문 X vs 방문 O
	}

	//2) 0번째 집에 반문하지 않은 경우
	dp2[0] = 0;
	dp2[1] = money[1];	//dp[1]은 money[1]집 훔쳐야 최대이므로

	for (int i = 2; i < size; i++) {
		dp2[i] = max(dp2[i - 1], dp2[i - 2] + money[i]);
	}

	return max(dp[size - 2], dp2[size - 1]);
}

int main(void) {

	vector<int> money = { 1,2,3,1 };	//각 집에 있는 돈
	int answer = solution(money);	//도둑이 훔칠 수 있는 돈의 최댓값

	cout << answer;
	return 0;
}
