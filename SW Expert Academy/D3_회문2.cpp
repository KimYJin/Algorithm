/*
100x100 글자판에서 가로, 세로 직선 중 가장 긴 회문의 길이 구하기
각 칸의 들어가는 글자는 c언어 char type으로 주어지며 'A', 'B', 'C' 중 하나
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>

using namespace std;

const int MAX = 100;
char m[MAX + 1][MAX + 1] = { 0, };

int main(void) {
	
	ifstream ifile("input (3).txt");

	if (!ifile) {
		cout << "can't open file" << endl;
		return 1;
	}
	

	for (int t = 1; t <= 10; t++) {

		int testcase = 0;
		int answer = 1;

		//cin >> T;
		ifile >> testcase;

		for (int i = 0; i < 100; i++) {
			//cin >> m[i];
			ifile >> m[i];
		}

		for (int len = MAX; len >= 1; len--) {	//회문 길이 (len) 긴 것부터 찾기

			if (answer > 1)	//가로,세로 중 길이가 len인 회문 찾으면 탐색 종료
				break;

			//(1) 가로 탐색
			for (int r = 0; r < MAX; r++) {
				for (int c = 0; c < MAX - len + 1; c++) {	//(r,c):len 길이의 문자열 시작점 

					bool correct = true;

					for (int k = 0; k < len / 2; k++) {		// 0부터 len의 절반만큼 반복
						if (m[r][c + k] != m[r][c + len - k - 1]) {	//대칭 위치의 왼쪽 오른쪽 문자 비교
							correct = false;	//다르면 회문이 아님
							break;
						}
					}

					if (correct) //회문을 찾은 경우
						answer = len;
				}
			}

			//(2) 세로 탐색
			for (int r = 0; r < MAX; r++) {
				for (int c = 0; c < MAX - len + 1; c++) {	//(r,c):len 길이의 문자열 시작점 

					bool correct = true;

					for (int k = 0; k < len / 2; k++) {		// 0부터 len의 절반만큼 반복
						if (m[r + k][c] != m[r + len - k - 1][c]) {	//대칭 위치의 왼쪽 오른쪽 문자 비교
							correct = false;	//다르면 회문이 아님
							break;
						}
					}

					if (correct) //회문을 찾은 경우
						answer = len;
				}
			}
		}
		cout << "#" << testcase << " " << answer << endl;
	}

	return 0;
}