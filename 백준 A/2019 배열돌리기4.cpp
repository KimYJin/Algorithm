/*
배열돌리기4 https://www.acmicpc.net/problem/17406
배열 A의 값 = 각 행에 있는 모든 수의 합 중 최솟값
회전 연산 (r, c, s) =  최좌측상단 (r-s, c-s), 최우측하단 (r+s, c+s)인 정사각형을 시계 방향으로 한 칸씩 돌린다.
회전 연산은 모두 한 번씩 사용해야 하며, 순서는 임의로 정해도 된다
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include<queue>

using namespace std;

struct POS {
	int r;
	int c;
	int s;
};

int R=0, C=0, N=0;//배열 가로,세로,회전연산 개수
const int MAX = 51;
const int MAX_N = 6;
int A[MAX][MAX] = { 0, };
int B[MAX][MAX] = { 0, };

POS pos[MAX_N];
int result = 50001;
bool check[MAX_N] = { false, };
vector<int> turn_order;

int dr[] = { 1,0,-1,0 };
int dc[] = { 0,1,0,-1 };

void input() {
	cin >> R >> C >> N;

	for (int r = 1; r <= R; r++) {
		for (int c = 1; c <= C; c++) {
			cin >> A[r][c];
		}
	}

	for (int i = 0; i < N; i++) {
		cin >> pos[i].r >> pos[i].c >> pos[i].s;
	}
}

void copyMap() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			B[i][j] = A[i][j];
		}
	}
}

void test() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cout << B[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}



void findMin() {
	for (int i = 1; i <= R; i++) {
		int sum = 0;
		for (int j = 1; j <= C; j++) {
			sum += B[i][j];
		}
		result = min(result, sum);
	}
}

void rotate(POS cur) {

	int sr = cur.r - cur.s;
	int sc = cur.c - cur.s;
	int er = cur.r + cur.s;
	int ec = cur.c + cur.s;

	int turn_count = (er - sr)/2;

	for (int i = 0; i < turn_count; i++) {
		
		int r = sr, c = sc;
		int temp = B[r][c];

		for (int d = 0; d < 4; d++) { //사각형 좌변,아랫변,우변,윗변 순 (시계반대)
			while (1) {
				int nr = r + dr[d];
				int nc = c + dc[d];

				if (nr < sr || nr >er || nc < sc || nc > ec ) //범위 벗어나면 다음 방향
					break;

				if (nr == sr && nc == sc) {	//다시 첫위치로 돌아왔을 때
					B[r][c] = temp;
					break;
				}

				B[r][c] = B[nr][nc];
				r = nr, c = nc;
			}
		}
		sr++, sc++, er--, ec--;	//사각형 최좌측상단 칸, 최우측하단 칸 -> 이동
	}
	
}

void solve(int depth) {

	if (depth == N) {
		copyMap();
		for (int i = 0; i < turn_order.size(); i++) {
			rotate(pos[turn_order[i]]);	//회전
			//test();
		}
		findMin();	//최솟값 찾기
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!check[i]) {
			check[i] = true;
			turn_order.push_back(i);
			solve(depth+1);
			check[i] = false;
			turn_order.pop_back();
		}
	}

}

int main(void) {

	input();
	solve(0);
	cout << result;
}