/*
https://www.welcomekakao.com/learn/courses/30/lessons/43237
국가의 예산을 분배하기 위한 상한액 구하기
이진탐색 이용해 풀이한 코드. 산한액=mid
*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> budgets, int M) {

	long long sum = 0;
	int answer = max;
	int size = budgets.size();

	sort(budgets.begin(), budgets.end());

	for (int budget : budgets)
		sum += budget;

	if (sum <= M)
		return budgets[size - 1];

	int min = M / size;		// 전체 예산을 예산요청의 개수로 나누어 최저값을 설정
	int max = budgets[size - 1];	  // 가장 큰 예산요청을 최대값으로 설정
	int mid = 0;	//상한액

	while (min <= max) {

		mid = (max + min) / 2;	//상한액
		sum = 0;

		//상한액보다 작은 요청은 더하고, 큰 요청들은 상한액으로 대체해 더함
		for (int budget : budgets) {
			if (budget < mid)
				sum += budget;
			else
				sum += mid;
		}

		//cout << "min: " << min << ", mid: " << mid << " ,max: " << max << " ,compareMid: " << compareMid << " ,sum: " << sum << endl;

		if (sum > M) {	//mid의 좌측 범위만 남김
			max = mid - 1;
		}
		else {
			if (mid < answer) {
				answer = mid;
			}
			min = mid + 1;	//mid의 우측 범위만 남김
		}
	}
	return answer;
}

int main(void) {

	cout << solution({ 120, 110, 140, 150 }, 485);

	return 0;
}