#include <string>
#include <vector>
#include<algorithm>

#include<iostream>

using namespace std;

//���� ��ȣ �������� 
bool comp(pair<int,int> a, pair<int,int> b) {
	return a.second < b.second;
}

int solution(vector<int> food_times, long long k) {

	//�ʱ�ȭ
	vector <pair<int, int>> v;
	for (int i = 0; i < food_times.size(); i++) {
		if(food_times[i]>0)
			v.push_back(make_pair(food_times[i],i+1));
	}
	
	//���� ��(�ҿ�ð�)�� �������� ����
	sort(v.begin(), v.end());

	int dish_num = v.size();	//���� ���� ��
	int prev_time = 0;
	for (vector <pair<int, int>> ::iterator it = v.begin(); it != v.end(); ++it, --dish_num) {
		
		//����. int*int�� int���� ���� �� �����Ƿ� longlong���� ����
		long long time = (long long)(it->first - prev_time) * dish_num;

		if (time == 0) continue;	//it->second - prev_time ==0 �Ǵ� dish_num==0 �� ���

		if (time <= k) {
			k -= time;
			prev_time = it->first;
		}
		else {
			k %= dish_num;
			sort(it, v.end(), comp);	 //���� ��ȣ �� ����
			
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