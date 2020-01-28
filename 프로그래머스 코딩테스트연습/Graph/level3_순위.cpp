/*
https://www.welcomekakao.com/learn/courses/30/lessons/49191
선수의 수 n, 부분적으로 분실된 경기 결과 results를 이용해
정확하게 순위를 매길 수 있는 선수의 수를 return.
results 배열 각 행 [A, B]는 A 선수가 B 선수를 이겼다는 의미.
...
다이나믹 프로그래밍을 기반으로 하는 플로이드 와샬 알고리즘 원리 이용! 
*/

#include <string>
#include <vector>
#include <iostream>
#include<algorithm>

using namespace std;

int solution(int n, vector<vector<int>> results) {
	int answer = 0;

	vector<vector<bool>> d(n + 1, vector<bool>(n + 1, false));

	for (auto r : results) {
		d[r[0]][r[1]] = true;
	}

	//k:거쳐가는 노드.. 이것을 기준으로 3중 for문 생성
	for (int k = 1; k <= n; k++) {
		//i:출발노드 (승리)
		for (int i = 1; i <= n; i++) {
			//j:도착노드 (패배)
			for (int j = 1; j <= n; j++) {
				if (d[i][k] && d[k][j]) {	//나한테 진 상대가 승리하는 경우도
					d[i][j] = true;	//나의 승리로 처리
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		
		int count = 0;

		for (int j = 1; j <= n; j++) {
			if (d[i][j] || d[j][i])	//승패 판별이 가능하면 count증가
				count++;
		}

		if (count == n - 1)	//n-1번의 승패 결과가 있으면 정확한 등수 파악 가능
			answer++;
	}

	return answer;
}

int main(void) {
	cout << solution(5, { {4, 3},{4, 2},{3, 2},{1, 2},{2, 5} });
}