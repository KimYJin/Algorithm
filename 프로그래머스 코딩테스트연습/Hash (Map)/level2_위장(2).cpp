#include<iostream>

#include <string>
#include <vector>
#include<unordered_map>

using namespace std;

//서로 다른 옷의 조합의 수 구하기
int solution(vector<vector<string>> clothes) {

	unordered_map<string, vector<string>> m;	//key: 의상종류, value: 의상 리스트

	for (vector<string> c : clothes) {
		m[c[1]].push_back(c[0]);	//의상종류 별로 의상 분류
	}

	int answer = 1;

	for (unordered_map<string, vector<string>>::iterator it = m.begin(); it != m.end(); ++it) {
		answer *= it->second.size() + 1; //(입지 않는 경우 포함하기 위해 +1)
	}

	return answer -1 ;	//아무것도 입지 않는 경우 빼기
}

int main(void) {

	vector<vector<string>> clothes = { { "yellow_hat", "headgear" },{ "blue_sunglasses", "eyewear" },{ "green_turban", "headgear" } };

	int answer = solution(clothes);
	cout << answer;

	return 0;
}