#include<iostream>
#include <string>
#include <vector>

using namespace std;

void dfs(vector<int> numbers, int target, int sum, int k);
int answer = 0;
//numbers ���ڵ��� ���ϰų� ���� target �� ����� ����� ��
int solution(vector<int> numbers, int target) {

	dfs(numbers, target, 0, 0);

	return answer;
}

void dfs(vector<int> numbers, int target, int sum, int depth) {

	//0 ���� numbers.size()-1 ������ number ��ȣ(+,-)���� �Ϸ���
	if (depth == numbers.size()) {

		if (sum == target)	//number�� ��� ���ڵ��� �������� �� Ÿ�ٳѹ��� ��ġ�ϸ�
			answer++;
	}
	else {
		dfs(numbers, target, sum + numbers[depth], depth + 1);		// k��ġ : +number
		dfs(numbers, target, sum - numbers[depth], depth + 1);// k��ġ : -number 
	}
}


int main(void) {

	vector<int> numbers = { 1, 1,1,1,1 };
	int target = 3;

	int answer = solution(numbers, target);

	cout << answer;

	return 0;
}