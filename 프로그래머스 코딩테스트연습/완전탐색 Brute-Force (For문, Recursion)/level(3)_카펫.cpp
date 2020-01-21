#include <string>
#include <vector>
#include<iostream>

using namespace std;

vector<int> solution(int brown, int red) {
	vector<int> answer;
	int r_garo,r_sero; int b_garo, b_sero;
	for (r_sero = 1; r_sero <= red; r_sero++) {
		r_garo = red / r_sero;
		if (red % r_sero != 0 || r_garo < r_sero)
			continue;

		if ((r_garo + 2)*(r_sero + 2) == brown + red)
		{
			answer.push_back(r_garo + 2);
			answer.push_back(r_sero + 2);
			break;
		}

	}

	return answer;
}

int main(void) {

	int brown=10, red=2;
	vector<int>  answer = solution(brown, red);

	for(int i:answer)
		cout << i;

	return 0;
}