#include <string>
#include<iostream>
#include <vector>
#include<algorithm>
#include<functional>
#include<queue>

using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;

	queue<pair<int, int>> q;
	for (int i = 0; i < priorities.size(); i++) {
		q.push(make_pair(i, priorities[i]));
	}

	//최대값인지 알기 위해 내림차순한 벡터
	vector<int> sv =  priorities;
	sort(sv.begin(),sv.end(), greater<int>());

	int order = 0;
	while(!q.empty()) {
		pair<int,int> temp = q.front();
		if (temp.second < sv[order]) {
			q.pop();
			q.push(temp);
		}
		else {
			if (temp.first == location) {
				answer = order+1;
				break;
			}
			++order;
			q.pop();
		}
	}

	return answer;
}

int main(void) {

	vector<int> priorities = { 1, 1, 9, 1, 1, 1 };
	int location = 0;
	int answer = solution(priorities, location);
	cout << answer;

	return 0;
}