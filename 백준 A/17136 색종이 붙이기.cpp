/*
17136번 색종이 붙이기 
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

	//각 row의 마지막 col 검사한 경우 다음 row의 0 확인
	if (sc == psize) {
		solve(sr + 1, 0);
		return;
	}
	//모든 row검사 마치면 사용된 색종이 수 확인
	if (sr == psize) {
		result = min(result, cnt);
		return;
	}

	if (paper[sr][sc] == 0) {
		solve(sr, sc + 1);
		return;
	}

	//5종의 색종이 다 붙여보기
	for (int cpsize = cp_max_size; cpsize >= 1; cpsize--) {

		//색종이 여분 체크
		if (cp[cpsize] <= 0)
			continue;

		bool isPossible = true;

		//해당 크기의 색종이 붙일 수 있는지 검사
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

		 //색종이 붙이기
		takeOnOff(sr, sc, cpsize, 0);
		cp[cpsize]--;
		cnt++;

		//다음 칸 탐색
		solve(sr, sc + 1);
		
		//색종이 떼기
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