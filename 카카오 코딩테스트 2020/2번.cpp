#include<iostream>

#include <string>
#include <vector>
#include<list>
#include<stack>


using namespace std;

list<char> v, u;

string sol(string w) {

	if (w == "")return w;

	stack <char>S; //w가 올바른 괄호 문자열인지 검사용

				   //문자열 w를 두 "균형잡힌 괄호 문자열" u, v로 분리
	int open = 0; int close = 0; int i = 0;
	while ((open != close) || i == 0) //w가 균형잡인 괄호 문자열이 될때까지
	{
		if (w[i] == '(')
		{
			open++;
			S.push('(');
		}
		else
		{
			close++;

			if (!S.empty() && S.top() == '(')
			{
				S.pop();
			}
			else
			{
				S.push(')');
			}
		}//end else
		++i;
	}//end while

	string u = w.substr(0, i);
	string v = w.substr(i, w.size() - i);


	//문자열 u가 올바르면, 문자열 v에 대해 1단계부터 다시 수행합니다. 
	if (S.empty()) {
		return u + sol(v);
	}
	else {
		//u의 첫 번째와 마지막 문자를 제거하고,
		u = u.substr(1, u.length() - 2);

		//나머지 문자열의 괄호 방향을 뒤집어서 
		for (int j = 0; j < u.size(); j++) {
			if (u[j] == '(') {
				u[j] = ')';
			}
			else {
				u[j] = '(';

			}
		}

		return "(" + sol(v) + ")" + u;
	}
	return "";
}

//괄호가 개수는 맞지만 짝이 맞지 않은 형태
//문자열 p를 이루는 '(' 와 ')' 의 개수는 항상 같습니다.
string solution(string p) {

	string answer = sol(p);

	return answer;
}

int main(void) {

	string p = "()))((()";
	string answer = solution(p);

	cout << answer;

	return 0;
}