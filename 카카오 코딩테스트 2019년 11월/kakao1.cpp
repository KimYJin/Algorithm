#include<iostream>
#include<stack>
#include<vector>

using namespace std;

const int MAX = 30;
int doll[MAX] = { 0, };

int solution(vector<vector<int>> board, vector<int> moves) {
	
	int answer = 0;// ��Ʈ���� ����� ����

	stack<int> s;

	int size = board[0].size();

	//���� ���� ����
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


	for (int m : moves) {	//ũ���� ��ġ

		int c = m - 1;

		int r = doll[c];	//�������� ����

		//���� ������ ����
		if (r >= size)	break;

		//���� �ű��
		s.push(board[r][c]);
		board[r][c] = 0;
		doll[c] += 1;

		//���� ��Ʈ����
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
				//cout << "�ٸ�.���󺹱�" << endl;
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
