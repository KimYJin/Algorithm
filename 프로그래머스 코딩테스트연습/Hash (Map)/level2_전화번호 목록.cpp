#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {

	vector<string>::iterator it1, it2;

	for (string s1 : phone_book) {
		for (string s2 : phone_book) {
			if (s1 != s2) {

				if (s1.size() <= s2.size()) {	//속도 줄이기 위해 추가
					//cout << s1 << " " << s2 << endl;
					if (s1 == s2.substr(0, s1.size())) {
						return false;
					}
				}
			}
		}
	}
	return true;
}

int main(void) {

	vector<string> phone_book =	{ "12", "123", "1235", "567","88" };

	bool answer = solution(phone_book);
	
	cout << answer;

	return 0;
}