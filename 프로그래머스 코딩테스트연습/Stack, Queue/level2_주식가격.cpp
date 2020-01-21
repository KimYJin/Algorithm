#include <string>
#include <vector>
#include<iostream>

using namespace std;

vector<int> solution(vector<int> prices) {

	vector<int> answer;
	int size = prices.size();

	for (int i = 0; i < size; ++i){
		int time = 0;
		for (int j = i + 1; j < size; ++j) {
			if (prices[i] <= prices[j]) {
				++time;
			}
			else {	
				++time;
				break;	//ȿ����	
			}
		}
		answer.push_back(time);

	}

	return answer;
}

int main(void) {

	vector<int> prices = { 1, 2, 3, 2, 3 };	//�� ������ ��ϵ� �ֽİ���
	vector<int> answer = solution(prices);	//�� �� ���� ������ �������� ���� �� �Ⱓ

	for (int a : answer) {
		cout << a;
	}

	return 0;
}