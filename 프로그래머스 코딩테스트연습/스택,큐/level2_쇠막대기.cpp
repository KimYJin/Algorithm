#include <string>
#include <vector>
#include<iostream>
#include<stack>

using namespace std;

int solution(string arrangement) {
	int answer = 0;

	stack<char> s;
	
	for (int i = 0; i < arrangement.length(); i++) {
		if (arrangement[i] == '(') {
			s.push('(');
		}
		else {
			//레이저
			if (arrangement[i-1] == '(') {	//s.top()=='('으로 풀면 안됨. ))인 경우 top에 )이 없기 때문
				s.pop();
				answer += s.size();
			}
			//막대기의 끝
			else {
				s.pop();
				answer++;
			}
		}
	}

	return answer;
}

int main(void) {
	
	string arrangement = "(((()(()()))(())()))(()())";
	int answer = solution(arrangement);
	cout << answer;

	return 0;
}
