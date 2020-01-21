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
			//������
			if (arrangement[i-1] == '(') {	//s.top()=='('���� Ǯ�� �ȵ�. ))�� ��� top�� )�� ���� ����
				s.pop();
				answer += s.size();
			}
			//������� ��
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
