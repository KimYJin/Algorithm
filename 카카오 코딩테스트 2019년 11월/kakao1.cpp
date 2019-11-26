#include<iostream>
#include<stack>
#include<vector>

using namespace std;

const int MAX = 30;
int doll[MAX] = { 0, };

int solution(vector<vector<int>> board, vector<int> moves) {
	
	int answer = 0;// 터트려져 사라진 인형

	stack<int> s;

	int size = board[0].size();

	//인형 쌓인 높이
	for (int c = 0; c < size; c++){
		for (int r = 0; r < size; r++) {
			if (board[r][c]==0) { 
				doll[c]++;
			}
			else {
				break;
			}
		}
		//cout << c << " : " << doll[c] << " " << endl;
	}


	for (int m : moves) {	//크레인 위치

		int c = m - 1;

		int r = doll[c];	//인형쌓인 높이

		//인형 없으면 무시
		if (r >= size)	break;

		//인형 옮기기
		s.push(board[r][c]);
		board[r][c] = 0;
		doll[c] += 1;

		//인형 터트리기
		if (s.size() > 1) {

			int first = s.top(); s.pop();
			int second = s.top();

			if (first == second) {
				s.pop();
				answer += 2;
				//cout << "first: " << first << " second: " << second << endl;
			}
			else {
				s.push(first);
				//cout << "다름.원상복귀" << endl;
			}
		}

	}
	
	return answer;
}

int main(void) {

	vector<vector<int>> board = { {0, 0, 0, 0, 0} ,
	{0, 0, 1, 0, 3},
	{0, 2, 5, 0, 1},
	{4, 2, 4, 4, 2},
	{3, 5, 1, 3, 1} };

	vector<int> moves = { 1,5,3,5,1,2,1,4 };

	int answer =  solution(board, moves);
	cout << answer;

	return 0;
}
