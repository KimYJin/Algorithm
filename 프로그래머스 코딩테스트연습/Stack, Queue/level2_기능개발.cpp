#include <string>
#include <vector>
#include<iostream>
#include<queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {

	vector<int> answer;	//각 배포마다 몇 개의 기능이 배포되는지
	queue<int> q;

	for (int i = 0; i < progresses.size(); ++i) {

		int p = progresses[i];
		int s = speeds[i];
		int day = 0;

		while (p < 100) {
			p += s;
			++day;
		}
		q.push(day);	
	}

	while (!q.empty()) {

		int count = 1;
		int day = q.front();
		q.pop();

		while (!q.empty() && day >= q.front()) {
				q.pop();
				++count;
		}
		answer.push_back(count);
	}

	return answer;
}

int main() {

	vector<int> progresses = { 93,30,55 };	//배포 순서 및 진행 상태
	vector<int> speeds = {1,30,5};	//각 기능의 개발 속도(%)

	vector<int> answer = solution(progresses, speeds);

	for (int a : answer) {
		cout << a << " ";
	}
}