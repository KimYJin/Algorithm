#include <string>
#include <vector>
#include<iostream>
#include<queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	
	int answer = 0;

	queue<int> q;
	int size = truck_weights.size();
	int sum = 0;

	for (int i = 0; i < size; ++i) {
		
		int truck_weight = truck_weights[i];

		while (1) {

			//다리를 빠져나가는 트럭
			 if (q.size() == bridge_length) {
				sum -= q.front();
				q.pop();
			}
			else {
				//다음 트럭이 다리에 추가될 수 있을 때
				if (truck_weight + sum <= weight) {
					q.push(truck_weight);
					sum += truck_weight;
					++answer;
					break;
				}
				//그렇지 않을 때-> queue에 0 삽입
				else {
					q.push(0);
					++answer;
				}

			}
		}
	}//마지막 트럭 진입하면 종료됨

	return answer+bridge_length;	//마지막 트럭이 나오는 시간 더해줌
}

int main() {

	int bridge_length = 2;
	int weight = 10;
	vector<int> truck_weights = { 7,4,5,6 };

	int answer = solution(bridge_length, weight, truck_weights);

	cout << answer;
}