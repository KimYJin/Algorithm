/*
https://www.welcomekakao.com/learn/courses/30/lessons/43237
������ ������ �й��ϱ� ���� ���Ѿ� ���ϱ�
����Ž�� �̿��� Ǯ���� �ڵ�. ���Ѿ�=mid
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

	int min = M / size;		// ��ü ������ �����û�� ������ ������ �������� ����
	int max = budgets[size - 1];	  // ���� ū �����û�� �ִ밪���� ����
	int mid = 0;	//���Ѿ�

	while (min <= max) {

		mid = (max + min) / 2;	//���Ѿ�
		sum = 0;

		//���Ѿ׺��� ���� ��û�� ���ϰ�, ū ��û���� ���Ѿ����� ��ü�� ����
		for (int budget : budgets) {
			if (budget < mid)
				sum += budget;
			else
				sum += mid;
		}

		//cout << "min: " << min << ", mid: " << mid << " ,max: " << max << " ,compareMid: " << compareMid << " ,sum: " << sum << endl;

		if (sum > M) {	//mid�� ���� ������ ����
			max = mid - 1;
		}
		else {
			if (mid < answer) {
				answer = mid;
			}
			min = mid + 1;	//mid�� ���� ������ ����
		}
	}
	return answer;
}

int main(void) {

	cout << solution({ 120, 110, 140, 150 }, 485);

	return 0;
}