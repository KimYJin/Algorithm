#include <string>
#include <vector>
#include<algorithm>

#include<iostream>

using namespace std;

//음식 번호 오름차순 
bool comp(pair<int,int> a, pair<int,int> b) {
	return a.second < b.second;
}

int solution(vector<int> food_times, long long k) {

	//초기화
	vector <pair<int, int>> v;
	for (int i = 0; i < food_times.size(); i++) {
		if(food_times[i]>0)
			v.push_back(make_pair(food_times[i],i+1));
	}
	
	//음식 양(소요시간)순 오름차순 정렬
	sort(v.begin(), v.end());

	int dish_num = v.size();	//남은 음식 수
	int prev_time = 0;
	for (vector <pair<int, int>> ::iterator it = v.begin(); it != v.end(); ++it, --dish_num) {
		
		//주의. int*int는 int범위 넘을 수 있으므로 longlong으로 선언
		long long time = (long long)(it->first - prev_time) * dish_num;

		if (time == 0) continue;	//it->second - prev_time ==0 또는 dish_num==0 인 경우

		if (time <= k) {
			k -= time;
			prev_time = it->first;
		}
		else {
			k %= dish_num;
			sort(it, v.end(), comp);	 //음식 번호 순 정렬
			
			return (it+k)->second;
		}
	}

	return -1;
}

int main() {

	vector<int> food_times = { 3,1,2 };
	long long k = 5;

	int answer = solution(food_times, k);

	return 0;
}