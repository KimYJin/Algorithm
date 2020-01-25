/*
https://www.welcomekakao.com/learn/courses/30/lessons/43238
입국심사를 기다리는 사람 수 n, 
각 심사관의 한명 당 심사 시간이 담긴 배열 times
모든 사람이 심사를 받는데 걸리는 시간의 최솟값 = mid
*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> times) {

	sort(times.begin(), times.end());

	long long max = (long long)times.back() * n;	//가장 느린 심사관이 모든 사람들을 한명씩 심사
	long long min = 1;		//1분 걸리는 심시관이 1명 심사
	long long mid = 0;		//총 심사 시간

	int size = times.size();
	long long answer = max;
	long long people_sum = 0;

	while (min <= max) {

		people_sum = 0;
		mid = (min + max) / 2;

		for (int i = 0; i < size; i++) {
			people_sum += mid / times[i];	//각 심사위원이 mid 시간동안 심사한 사람
		}

		if (people_sum < n) {
			min = mid + 1;
		}
		else {
			if (answer > mid) {
				answer = mid;	//심사 시간의 최솟값 찾기
			}
			max = mid - 1;
		}

	}
	return answer;
}

int main(void) {

	cout << solution(6, {7,10});
	return 0;
}

