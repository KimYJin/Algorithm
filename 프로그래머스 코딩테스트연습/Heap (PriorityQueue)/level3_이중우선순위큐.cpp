#include <string>
#include <vector>
#include<iostream>
#include<queue>
#include<functional>
#include<algorithm>


using namespace std;

vector<int> solution(vector<string> operations) {

	vector<int> answer;
	deque<int> dq;

	for (string op : operations) {
		
		switch (op[0])
		{
		case 'I':	//����

			//op.erase(op.begin());	
			//op.erase(op.begin());
			op = op.substr(2);

			dq.push_back(stoi(op));

			break;

		default:	

			//op.erase(op.begin());	
			//op.erase(op.begin());
			op = op.substr(2);

			if (op == "1") {	//D 1 : �ִ� ����
				if (!dq.empty()) 
					sort(dq.begin(), dq.end());	//��������
					dq.pop_back();	
			}
			else {	//D -1 : �ּڰ� ����
				if (!dq.empty()) 
					sort(dq.begin(), dq.end());
					dq.pop_front();	
			}

			break;
		}
	}

	if (!dq.empty()) {
		sort(dq.begin(), dq.end());
		answer.push_back(dq.back());	//�ִ�
		answer.push_back(dq.front());	//�ּڰ�
	}
	else {
		answer.push_back(0);
		answer.push_back(0);
	}

	return answer;
}

int main(void) {

	vector<string> operations = { "I 7","I 5","I -5","D -1" };
	vector<int> answer = solution(operations);
	for(int a: answer)
		cout << a << " ";

	return 0;
}