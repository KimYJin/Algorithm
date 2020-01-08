#include<iostream>
#include <string>
#include <vector>
#include<queue>

using namespace std;

/*
이 문제에 핵심은 밀가루 공급하는 시점에서 밀가루를 추가할지 말지를 결정하는 것이 아닌,
밀가루가 부족해지는 시점에 밀가루를 추가할지 말지 결정하는 방식
밀가루가 필요한 시점에, 공급받을 수 있는 밀가루 양 중 가장 큰 양을 공급받는다.
*/
int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	int answer = 0;
	int dayCanRunFactory = stock;
	int index = 0;

	priority_queue<int> q;

	while(dayCanRunFactory < k) {
		while (index < dates.size() && dayCanRunFactory >= dates[index]) { //받을 수 있는 밀가루는 큐에 넣기
			q.push(supplies[index]);
			++index;
		}

		dayCanRunFactory += q.top();	//최대 밀가루
		q.pop();
		++answer;
	}

	return answer;
}

/*
현재 공장에 남아있는 밀가루 수량 (stock),
밀가루 공급 일정(dates), 해당 시점에 공급 가능한 밀가루 수량(supplies), 
정상 공급받을 수 있는 시점 (k), k일 전까지 밀가루를 공급 받은 최소 횟수 (answer)
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
