/*
https://www.welcomekakao.com/learn/courses/30/lessons/42862
여벌 체육복이 있는 학생은 바로 앞번호/뒷번호의 학생에게만 체육복을 빌려준다.
체육수업을 들을 수 있는 학생의 최댓값을 return.
여벌 체육복을 가져온 학생이 도난당하는 경우 하나만 도난당했다고 가정하며,
남은 체육복이 하나이기에 다른 학생에게는 체육복을 빌려줄 수 없습니다.
*/

#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {

	vector<int> v(n, 1);	//전체 학생 n
	
	for (int i = 0; i < lost.size(); i++)	//체육복을 도난당한 학생들 lost
		v[lost[i]-1] -= 1;

	for (int i = 0; i < reserve.size(); i++)	//여벌 체육복이 있는 학생들 reserve
		v[reserve[i]-1] += 1;

	for (int i = 0; i < n; i++) {
		if (v[i] < 1) {
			if (i - 1 > 0 && v[i - 1] > 1) {
				v[i] += 1;
				v[i - 1] -= 1;
				continue;
			}
			if (i + 1 < n && v[i + 1] > 1) {
				v[i] += 1;
				v[i + 1] -= 1;
				continue;
			}
		}
	}

	int answer = 0;

	for (int count : v) {
		if (count > 0)
			answer++;
	}

	return answer;
}

int main(void) {
	cout << solution(5, { 2,4 }, { 1,3,5 });
}