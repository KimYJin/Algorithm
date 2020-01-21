/*
https://www.welcomekakao.com/learn/courses/30/lessons/42862
���� ü������ �ִ� �л��� �ٷ� �չ�ȣ/�޹�ȣ�� �л����Ը� ü������ �����ش�.
ü�������� ���� �� �ִ� �л��� �ִ��� return.
���� ü������ ������ �л��� �������ϴ� ��� �ϳ��� �������ߴٰ� �����ϸ�,
���� ü������ �ϳ��̱⿡ �ٸ� �л����Դ� ü������ ������ �� �����ϴ�.
*/

#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {

	vector<int> v(n, 1);	//��ü �л� n
	
	for (int i = 0; i < lost.size(); i++)	//ü������ �������� �л��� lost
		v[lost[i]-1] -= 1;

	for (int i = 0; i < reserve.size(); i++)	//���� ü������ �ִ� �л��� reserve
		v[reserve[i]-1] += 1;

	for (int i = 0; i < n; i++) {
		if (v[i] < 1) {
			if (i - 1 > 0 && v[i - 1] > 1) {
				v[i] += 1;
				v[i - 1] -= 1;
				continue;
			}
			if (i + 1 < n && v[i + 1] > 1) {
				v[i] += 1;
				v[i + 1] -= 1;
				continue;
			}
		}
	}

	int answer = 0;

	for (int count : v) {
		if (count > 0)
			answer++;
	}

	return answer;
}

int main(void) {
	cout << solution(5, { 2,4 }, { 1,3,5 });
}