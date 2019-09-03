#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

#include <string>
#include <vector>
#include<algorithm>

using namespace std;

bool comp(string a, string b) {
	return a + b > b + a;
}

string solution(vector<int> numbers) {

	vector<string> v;

	for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
		v.push_back(to_string(*it));
	}

	sort(v.begin(), v.end(), comp);

	string answer = "";
	for (string str : v) {
		answer += str;
	}
	if (answer[0] == '0') answer = "0"; //입력:{0, 0, 0, 0} -> 출력:0 이어야함

	cout << answer;
	return answer;
}

int main() {

	vector<int> numbers = {0,0,0,0,0 };	
	solution(numbers);

	return 0;
}
