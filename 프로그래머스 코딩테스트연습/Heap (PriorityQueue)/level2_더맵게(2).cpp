#include<iostream>

#include <string>
#include <vector>
#include <queue>
#include<functional>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;

	//초기화
	priority_queue<int, vector<int>, greater<int>> p; //최상위 최솟값
	for (int s : scoville) {
		p.push(s);
	}

	int i = 0;
	while (p.size() > 0) {
		if (p.top() >= K) //최솟값이 K 이상이면 모든 음식 K이상
		{
			answer = i;
			break;
		}
		else 
		{
			//모든 음식 K 이상으로 만들 수 없는 때 -1을 return
			if (p.size() < 2)return -1;

			//섞기 
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