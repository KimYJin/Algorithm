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

	//나올 수 있는 순열 중 최댓값구하기 위해 내림차순 정렬
	string sortedNumbers = numbers;
	sort(sortedNumbers.begin(), sortedNumbers.end(), comp);
	
	//소수 구하기 - 에라토스테네스의 체
	int size = stoi(sortedNumbers);
	noprime[0] = true; noprime[1] = true;

	for (int i = 2; i <= sqrt(size); i++) {	//2,3,4,,,
		if (!noprime[i]) {
			for (int j = i*i; j <= size; j = j + i) //2의 배수,3의배수,,지워나감
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