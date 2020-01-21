/*
https://www.welcomekakao.com/learn/courses/30/lessons/43237
국가의 예산을 분배하기 위한 상한액 구하기
이진탐색 이용해 풀이한 코드
*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> budgets, int M) {

	long long sum = 0;
	int answer = 0;
	int size = budgets.size();

	sort(budgets.begin(), budgets.end());

	for (int budget : budgets)
		sum += budget;

	if (sum <= M)
		return budgets[size - 1];

	int min = M / size;		// 전체 예산을 예산요청의 개수로 나누어 최저값을 설정
	int max = budgets[size - 1];	  // 가장 큰 예산요청을 최대값으로 설정
	int mid = 0;	//상한액
	int compareMid = 0;		//비교를 위한 이전에 구한 상한액

	while (true) {

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

		//상한값의 변화가 더이상 없다면 종료
		if (mid == compareMid) {
			answer = mid;
			break;
		}

		if (sum > M)	//mid의 좌측 범위만 남김
			max = mid;
		else
			min = mid;	//mid의 우측 범위만 남김

		compareMid = mid;	//비교를 위해 이전 mid 저장
	}
	return answer;
}

int main(void) {

	cout << solution({ 120, 110, 140, 150 }, 485);

	return 0;
}