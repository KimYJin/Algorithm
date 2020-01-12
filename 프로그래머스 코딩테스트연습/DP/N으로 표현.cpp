#include <string>
#include <vector>
#include<iostream>
#include<unordered_set>

using namespace std;

#define MAX 8

/*
N, ��ȣ, ��Ģ���길 ����ؼ� number�� ǥ�� �� �� �ִ�
��� �� N ���Ƚ���� �ּڰ��� return 
*/
int solution(int N, int number) {
	int answer = -1;
	int base = 0;
	int times = 1;

	unordered_set<int> s[MAX+1];

	for (times = 1; times <= MAX; ++times) {
		base = base * 10 + 1;	//1, 11, ...
		s[times].insert(base * N);
	}

	//N�� ��� ����: (N)
	//(2): (1)��(1)�� ����
	//(3): (1)��(2)�� ����, (2)��(1)�� ���� ...
	for (times = 2; times <= MAX; ++times) {
		for (int j = 1; j < times; ++j) {

			for (int op1 : s[j]) {
				for (int op2 : s[times - j]) {
					
					if (times - j > j)
						continue;

					s[times].insert(op1 + op2);
					s[times].insert(op1 - op2);
					s[times].insert(op1 * op2);

					if(op2 != 0)
						s[times].insert(op1 / op2);
				}
			}
		}	

		if (s[times].count(number) > 0)
		{
			answer = times;
			break;
		}
	}

	return answer;
}


int main(void) {

	int N = 5; int number = 12;

	int answer = solution(N, number);
	cout << answer;

	return 0;
}