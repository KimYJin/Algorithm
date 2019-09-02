#include <string>
#include <vector>
#include<queue>

#include<iostream>

using namespace std;

int solution(vector<int> food_times, long long k) {
	int answer = 0;

	queue<pair<int,int>> q;

	//최소값 찾기
	vector<int> ::iterator it;
	int min = -1;
	for (it = food_times.begin(); it != food_times.end(); it++) {
		if (min > *it) { min = *it; }
	}
	int standard = 0;

	if (min > 0) {
		standard = min;
		k = k - standard * food_times.size();
	}


	//초기화 
	for (unsigned int i=0; i< food_times.size();i++)
	{
		if (food_times[i] == standard) continue;
		q.push(make_pair(i+1, food_times[i]));	//key:음식번호, value:소요시간
	}

	int dish_num=0, dish_time=0;
	while(k--){
		if (q.empty()) {
			break;
		}
		
		dish_num = q.front().first;
		dish_time = q.front().second - 1;
		q.pop();

		if (dish_time > 0)
			q.push(make_pair(dish_num, dish_time));
	}
	
	//결과
	if (q.empty())	{
		answer = -1;
	}
	else {
		answer = q.front().first;
	}
	cout << answer;
	return answer;
}

int main() {

	vector<int> food_times = { 3,1,2 };
	long long k = 5;

	int answer = solution(food_times, k);

	return 0;
}