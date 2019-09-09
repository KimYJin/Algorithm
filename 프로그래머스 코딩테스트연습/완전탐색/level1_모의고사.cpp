#include<iostream>
#include <string>
#include <vector>
#include<algorithm>

using namespace std;

int tester1[5] = { 1,2,3,4,5 };
int tester2[8] = { 2,1,2,3,2,4,2,5 };
int tester3[10] = { 3,3,1,1,2,2,4,4,5,5 };


vector<int> solution(vector<int> answers) {
	vector<int> answer;
	vector<int> score(3);
	int maxScore = 0;

	for (int i = 0; i < answers.size(); i++) {
		if (tester1[i % 5] == answers[i]) score[0]++;
		if (tester2[i % 8] == answers[i]) score[1]++;
		if (tester3[i % 10] == answers[i]) score[2]++;
	}


	maxScore = max({ score[0], score[1], score[2] });

	for (int i = 0; i<3; i++) {
		if (score[i] == maxScore) answer.push_back(i + 1);
	}

	return answer;
}