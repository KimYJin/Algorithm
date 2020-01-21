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

			//�ٸ��� ���������� Ʈ��
			 if (q.size() == bridge_length) {
				sum -= q.front();
				q.pop();
			}
			else {
				//���� Ʈ���� �ٸ��� �߰��� �� ���� ��
				if (truck_weight + sum <= weight) {
					q.push(truck_weight);
					sum += truck_weight;
					++answer;
					break;
				}
				//�׷��� ���� ��-> queue�� 0 ����
				else {
					q.push(0);
					++answer;
				}

			}
		}
	}//������ Ʈ�� �����ϸ� �����

	return answer+bridge_length;	//������ Ʈ���� ������ �ð� ������
}

int main() {

	int bridge_length = 2;
	int weight = 10;
	vector<int> truck_weights = { 7,4,5,6 };

	int answer = solution(bridge_length, weight, truck_weights);

	cout << answer;
}