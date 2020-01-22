/*
https://www.welcomekakao.com/learn/courses/30/lessons/43237
������ ������ �й��ϱ� ���� ���Ѿ� ���ϱ�
����Ž������ Ǯ�� ���� �ڵ�
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

	//1.��� ��û�� ������ �� �ִ� ��쿡�� ��û�� �ݾ��� �״�� ����
	if (sum <= M)
		return *(budgets.end() - 1);	//�ִ밪�� ���Ѿ��� ��
	
	//2. �׷��� ���� ���, ���Ѿ��� ����Ͽ� �� �̻��� �����û���� ���Ѿ��� ����
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