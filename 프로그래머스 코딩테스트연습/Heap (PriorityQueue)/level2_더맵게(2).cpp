#include<iostream>

#include <string>
#include <vector>
#include <queue>
#include<functional>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;

	//�ʱ�ȭ
	priority_queue<int, vector<int>, greater<int>> p; //�ֻ��� �ּڰ�
	for (int s : scoville) {
		p.push(s);
	}

	int i = 0;
	while (p.size() > 0) {
		if (p.top() >= K) //�ּڰ��� K �̻��̸� ��� ���� K�̻�
		{
			answer = i;
			break;
		}
		else 
		{
			//��� ���� K �̻����� ���� �� ���� �� -1�� return
			if (p.size() < 2)return -1;

			//���� 
			i++;
			int first = p.top();
			p.pop();
			int second = p.top();
			p.pop();
			int mix = first + second * 2;
			p.push(mix);
		}
	}

	return answer;
}

int main(void) {

	vector<int> scoville = { 1, 2, 3, 9, 10, 12 };
	int K = 7;

	int answer = solution(scoville, K);

	cout << answer;

	return 0;
}