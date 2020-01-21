#include<iostream>
#include <string>
#include <vector>

using namespace std;

void dfs(vector<int> numbers, int target, int sum, int k);
int answer = 0;
//numbers 숫자들을 더하거나 빼서 target 값 만드는 방법의 수
int solution(vector<int> numbers, int target) {

	dfs(numbers, target, 0, 0);

	return answer;
}

void dfs(vector<int> numbers, int target, int sum, int depth) {

	//0 부터 numbers.size()-1 까지의 number 부호(+,-)셋팅 완료라면
	if (depth == numbers.size()) {

		if (sum == target)	//number에 담긴 숫자들을 연산했을 때 타겟넘버와 일치하면
			answer++;
	}
	else {
		dfs(numbers, target, sum + numbers[depth], depth + 1);		// k위치 : +number
		dfs(numbers, target, sum - numbers[depth], depth + 1);// k위치 : -number 
	}
}


int main(void) {

	vector<int> numbers = { 1, 1,1,1,1 };
	int target = 3;

	int answer = solution(numbers, target);

	cout << answer;

	return 0;
}