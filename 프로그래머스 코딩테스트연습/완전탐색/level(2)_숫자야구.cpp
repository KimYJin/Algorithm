#include<iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> baseball) {
	int answer = 0;

	vector<int> num(3);
	
	for (int i = 1; i <= 9; i++) {
		num[0] = i;
		for (int j = 1; j <= 9; j++) {
			num[1] = j;
			for (int k = 1; k <= 9; k++) {
				num[2] = k;

				if (i == j || i == k || j == k) {
					continue;
				}

				int strike = 0;
				int ball = 0;
				vector<int> tempv(3);
				bool check = true;

				for (int b = 0; b < baseball.size(); b++) {
					
					strike = 0;
					ball = 0;

					//세자리 초기화
					int tempnum = baseball[b][0];
		
					tempv[0] = tempnum / 100;
					tempnum %= 100;
					tempv[1] = tempnum / 10;
					tempv[2] = tempnum % 10;

					//strike , ball 검사
					for (int t = 0; t < 3; t++) {
						if (num[t] == tempv[t]) {
							strike++;
						}
						else if (num[t] == tempv[(t + 1) % 3] || num[t] == tempv[(t + 2) % 3]) {
							ball++;
						}
					}
					
					if (strike != baseball[b][1] || ball != baseball[b][2]) {
						check = false;
						break;
					}
				}
				if (check == true)
					answer++;
			}
		}
	}

	return answer;
}

int main(void) {

	vector<vector<int>> baseball = { {123,1,1},{356,1,0},{327,2,0},{489,0,1} };

	int answer = solution(baseball);
	cout << answer;

	return 0;
}