/*
https://www.welcomekakao.com/learn/courses/30/lessons/43237
국가의 예산을 분배하기 위한 상한액 구하기
이진탐색으로 풀지 않은 코드
*/

#include <string>
#include <vector>
#include<algorithm>
#include<iostream>

using namespace std;

int solution(vector<int> budgets, int M) {
	
	sort(budgets.begin(), budgets.end());

	long long sum = 0;
	for (int temp : budgets) {
		sum += temp;
	}

	//1.모든 요청이 배정될 수 있는 경우에는 요청한 금액을 그대로 배정
	if (sum <= M)
		return *(budgets.end() - 1);	//최대값이 상한액이 됨
	
	//2. 그렇지 않은 경우, 상한액을 계산하여 그 이상인 예산요청에는 상한액을 배정
	int avg = M / budgets.size();
	long long under_sum = 0;
	int size = budgets.size();

	for (int b : budgets) {
		if (b < avg) {
			under_sum += b;
			size--;
			avg = (M - under_sum) / (size);
		}
		else
			return avg;
	}
}

int main(void) {

	cout << solution({ 110, 115, 120,125, 130 }, 485);

	return 0;
}