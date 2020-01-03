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
				break;	//효율성	
			}
		}
		answer.push_back(time);

	}

	return answer;
}

int main(void) {

	vector<int> prices = { 1, 2, 3, 2, 3 };	//초 단위로 기록된 주식가격
	vector<int> answer = solution(prices);	//각 초 기준 가격이 떨어지지 않은 초 기간

	for (int a : answer) {
		cout << a;
	}

	return 0;
}