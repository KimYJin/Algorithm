#include <string>
#include<iostream>
#include <vector>
#include<algorithm>
#include<queue>

using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;

	//�ִ밪
	int max = *max_element(priorities.begin(), priorities.end());

	int count = 0;

	while (true) {
	
		for (int i = 0; i < priorities.size(); i++) {
			if (max == priorities[i]) {
				priorities[i] = 0;
				++count;
				max = *max_element(priorities.begin(), priorities.end());

				if (location == i) {
					answer = count;
					return answer;
				}
			}
		}
	}
}

int main(void) {

	vector<int> priorities = { 1, 1, 9, 1, 1, 1 };
	int location = 0;
	int answer = solution(priorities, location);
	cout << answer;

	return 0;
}