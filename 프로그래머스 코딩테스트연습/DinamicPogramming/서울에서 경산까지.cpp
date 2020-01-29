/*
https://www.welcomekakao.com/learn/courses/30/lessons/42899
서울에서 출발해 다른 도시를 정해진 순서대로 딱 한 번 방문한 후 경산으로 도착
K시간 이내로 여행하며 모을 수 있는 최대 모금액
dp[i][j] -> i 도시에, j 시간의 최대 모금액
travel 배열의 각 행은 [도보 시간, 도보 모금액, 자전거 시간, 자전거 모금액]
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

	for (int i = 1; i < t_size; i++) {	//도시

		for (int j = 0; j <= K; j++) {	//시간

			if (dp[i - 1][j] == 0) //이전 도시에 j시간에 도착한 기록이 없으면 무시
				continue;	

			//현 도시까지 모은 모금액 vs 이전 도시로부터 도보로 이동해 더해진 모금액
			if (j + travel[i][0] <= K)
				dp[i][j + travel[i][0]] = max(dp[i][j + travel[i][0]], dp[i - 1][j] + travel[i][1]);

			//현 도시까지 모은 모금액 vs 이전 도시로부터 현도시까지 자전거로 이동해 더해진 모금액
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

