/*
https://www.welcomekakao.com/learn/courses/30/lessons/43238
�Ա��ɻ縦 ��ٸ��� ��� �� n, 
�� �ɻ���� �Ѹ� �� �ɻ� �ð��� ��� �迭 times
��� ����� �ɻ縦 �޴µ� �ɸ��� �ð��� �ּڰ� = mid
*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> times) {

	sort(times.begin(), times.end());

	long long max = (long long)times.back() * n;	//���� ���� �ɻ���� ��� ������� �Ѹ� �ɻ�
	long long min = 1;		//1�� �ɸ��� �ɽð��� 1�� �ɻ�
	long long mid = 0;		//�� �ɻ� �ð�

	int size = times.size();
	long long answer = max;
	long long people_sum = 0;

	while (min <= max) {

		people_sum = 0;
		mid = (min + max) / 2;

		for (int i = 0; i < size; i++) {
			people_sum += mid / times[i];	//�� �ɻ������� mid �ð����� �ɻ��� ���
		}

		if (people_sum < n) {
			min = mid + 1;
		}
		else {
			if (answer > mid) {
				answer = mid;	//�ɻ� �ð��� �ּڰ� ã��
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

