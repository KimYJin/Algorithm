#include<iostream>

#include <string>
#include <vector>
#include<list>
#include<stack>


using namespace std;

list<char> v, u;

string sol(string w) {

	if (w == "")return w;

	stack <char>S; //w�� �ùٸ� ��ȣ ���ڿ����� �˻��

				   //���ڿ� w�� �� "�������� ��ȣ ���ڿ�" u, v�� �и�
	int open = 0; int close = 0; int i = 0;
	while ((open != close) || i == 0) //w�� �������� ��ȣ ���ڿ��� �ɶ�����
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


	//���ڿ� u�� �ùٸ���, ���ڿ� v�� ���� 1�ܰ���� �ٽ� �����մϴ�. 
	if (S.empty()) {
		return u + sol(v);
	}
	else {
		//u�� ù ��°�� ������ ���ڸ� �����ϰ�,
		u = u.substr(1, u.length() - 2);

		//������ ���ڿ��� ��ȣ ������ ����� 
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

//��ȣ�� ������ ������ ¦�� ���� ���� ����
//���ڿ� p�� �̷�� '(' �� ')' �� ������ �׻� �����ϴ�.
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