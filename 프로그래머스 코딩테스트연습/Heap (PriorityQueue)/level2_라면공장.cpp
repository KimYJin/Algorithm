#include<iostream>
#include <string>
#include <vector>
#include<queue>

using namespace std;

/*
�� ������ �ٽ��� �а��� �����ϴ� �������� �а��縦 �߰����� ������ �����ϴ� ���� �ƴ�,
�а��簡 ���������� ������ �а��縦 �߰����� ���� �����ϴ� ���
�а��簡 �ʿ��� ������, ���޹��� �� �ִ� �а��� �� �� ���� ū ���� ���޹޴´�.
*/
int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	int answer = 0;
	int dayCanRunFactory = stock;
	int index = 0;

	priority_queue<int> q;

	while(dayCanRunFactory < k) {
		while (index < dates.size() && dayCanRunFactory >= dates[index]) { //���� �� �ִ� �а���� ť�� �ֱ�
			q.push(supplies[index]);
			++index;
		}

		dayCanRunFactory += q.top();	//�ִ� �а���
		q.pop();
		++answer;
	}

	return answer;
}

/*
���� ���忡 �����ִ� �а��� ���� (stock),
�а��� ���� ����(dates), �ش� ������ ���� ������ �а��� ����(supplies), 
���� ���޹��� �� �ִ� ���� (k), k�� ������ �а��縦 ���� ���� �ּ� Ƚ�� (answer)
*/
int main(void)
{
	int stock = 4;
	vector<int> dates = { 4,10,15 };
	vector<int> supplies = { 20,5,10 };
	int k = 30;


	int answer = solution(stock, dates, supplies, k);
	cout << answer;
	
	return 0;
}
