#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

#include <string>
#include <vector>
#include<map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	vector<string>::iterator it;
	
	map<string, int> m;
	map<string, int>::iterator itm;

	for (it = participant.begin(); it != participant.end(); it++) {
		m[*it]++;
	}

	for (it = completion.begin(); it != completion.end(); it++) {
		m[*it]--;
	}

	for (itm = m.begin(); itm != m.end(); itm ++) {
		if (itm->second > 0)
		{
			answer = itm->first;
			break;
		}
	}
	cout << answer;
	return answer;
}

int main() {

	vector<string> participant = { "marina", "josipa", "nikola", "vinko", "filipa" };
	vector<string> completion = { "josipa", "filipa", "marina", "nikola" };

	solution(participant, completion);

	return 0;
}

