#include<iostream>

#include <string>
#include <vector>
#include <set>
#include<algorithm>

using namespace std;

int answer = 0;
bool noprime[10000000] = { false };
set<int> primes;


bool comp(char a, char b) {
	return a > b;
}

int solution(string numbers) {

	//���� �� �ִ� ���� �� �ִ񰪱��ϱ� ���� �������� ����
	string sortedNumbers = numbers;
	sort(sortedNumbers.begin(), sortedNumbers.end(), comp);
	
	//�Ҽ� ���ϱ� - �����佺�׳׽��� ü
	int size = stoi(sortedNumbers);
	noprime[0] = true; noprime[1] = true;

	for (int i = 2; i <= sqrt(size); i++) {	//2,3,4,,,
		if (!noprime[i]) {
			for (int j = i*i; j <= size; j = j + i) //2�� ���,3�ǹ��,,��������
			{
				noprime[j] = true;
			}
		}
	}

	sort(numbers.begin(), numbers.end());
	do {
		for (int i = 1; i <= numbers.size(); i++) {
			string sub = numbers.substr(0, i);
			int num = stoi(sub);

			if (!noprime[num]) {
				primes.insert(num);
			}
		}
	} while (next_permutation(numbers.begin(), numbers.end()));

	answer = primes.size();
	primes.clear();

	return answer;
}

int main(void) {

	string numbers = "17";
	int answer = solution(numbers);
	cout << answer;

	return 0;
}