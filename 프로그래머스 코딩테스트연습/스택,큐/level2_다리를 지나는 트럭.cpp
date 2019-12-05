#include <string>
#include <vector>
#include<iostream>
#include<map>
#include<queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	
	int answer = 0;

	map <int, int>::iterator iter;
	map <int, int> m;			//index, move
	queue <pair<int,int>> q;	//index, weight
	int sum = 0;

	for (int i=0;i < truck_weights.size(); ++i) {
		q.push(make_pair(i,truck_weights[i]));
	}


	for (int time = 1; ; ++time) {

		//트럭 이동
		for (iter = m.begin(); iter != m.end(); ) {
			if (iter->second < bridge_length) {
				++m[iter->first];
				++iter;
			}
			else {
				sum -= truck_weights[iter->first];
				iter = m.erase(iter);
			}
		}		

		//다리위로 트럭 진입
		if (q.front().second + sum <= weight) {
			int idx = q.front().first;
			sum += q.front().second;
			q.pop();
			m.insert(make_pair(q.front().first, 1));
		}

		if (m.empty()) {
			answer = time;
			break;
		}	
	}	

	return answer;
}

int main() {

	int bridge_length = 2;
	int weight = 10;
	vector<int> truck_weights = { 7,4,5,6 };

	int answer = solution(bridge_length, weight, truck_weights);

	cout << answer;
}