/*
17136�� ������ ���̱� 
https://www.acmicpc.net/problem/17136
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int psize = 10;
const int cp_max_size = 5;
const int INF = 987654321;
int result = INF;

int paper[psize][psize] = { 0, };
vector <int> cp(cp_max_size+1, 5);
int cnt = 0;

void takeOnOff(int sr, int sc, int cpsize, int n){
	for (int r = sr; r < sr + cpsize; r++) {
		for (int c = sc; c < sc + cpsize; c++) {
			paper[r][c] = n;
		}
	}
}

void solve(int sr, int sc) {

	//�� row�� ������ col �˻��� ��� ���� row�� 0 Ȯ��
	if (sc == psize) {
		solve(sr + 1, 0);
		return;
	}
	//��� row�˻� ��ġ�� ���� ������ �� Ȯ��
	if (sr == psize) {
		result = min(result, cnt);
		return;
	}

	if (paper[sr][sc] == 0) {
		solve(sr, sc + 1);
		return;
	}

	//5���� ������ �� �ٿ�����
	for (int cpsize = cp_max_size; cpsize >= 1; cpsize--) {

		//������ ���� üũ
		if (cp[cpsize] <= 0)
			continue;

		bool isPossible = true;

		//�ش� ũ���� ������ ���� �� �ִ��� �˻�
		for (int r = sr; r < sr + cpsize; r++) {
			for (int c = sc; c < sc + cpsize; c++) {

				if (r >= psize || c >= psize || c < 0 || r < 0 || paper[r][c] == 0)
				{
					isPossible = false;
					break;
				}
			}//end for c
			if (!isPossible)
				break;
		}//end for r
		
		if (!isPossible)
			continue;

		 //������ ���̱�
		takeOnOff(sr, sc, cpsize, 0);
		cp[cpsize]--;
		cnt++;

		//���� ĭ Ž��
		solve(sr, sc + 1);
		
		//������ ����
		takeOnOff(sr, sc, cpsize, 1);
		cp[cpsize]++;
		cnt--;

	}//end for cpsize
}

int main(void) {

	for (int i = 0; i < psize; i++) {
		for (int j = 0; j < psize; j++) {
			cin >> paper[i][j];
		}
	}

	solve(0, 0);

	if (result == INF)
		cout << "-1";
	else
		cout << result;

}