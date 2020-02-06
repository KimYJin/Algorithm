/*
�迭������4 https://www.acmicpc.net/problem/17406
�迭 A�� �� = �� �࿡ �ִ� ��� ���� �� �� �ּڰ�
ȸ�� ���� (r, c, s) =  ��������� (r-s, c-s), �ֿ����ϴ� (r+s, c+s)�� ���簢���� �ð� �������� �� ĭ�� ������.
ȸ�� ������ ��� �� ���� ����ؾ� �ϸ�, ������ ���Ƿ� ���ص� �ȴ�
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

int R=0, C=0, N=0;//�迭 ����,����,ȸ������ ����
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

		for (int d = 0; d < 4; d++) { //�簢�� �º�,�Ʒ���,�캯,���� �� (�ð�ݴ�)
			while (1) {
				int nr = r + dr[d];
				int nc = c + dc[d];

				if (nr < sr || nr >er || nc < sc || nc > ec ) //���� ����� ���� ����
					break;

				if (nr == sr && nc == sc) {	//�ٽ� ù��ġ�� ���ƿ��� ��
					B[r][c] = temp;
					break;
				}

				B[r][c] = B[nr][nc];
				r = nr, c = nc;
			}
		}
		sr++, sc++, er--, ec--;	//�簢�� ��������� ĭ, �ֿ����ϴ� ĭ -> �̵�
	}
	
}

void solve(int depth) {

	if (depth == N) {
		copyMap();
		for (int i = 0; i < turn_order.size(); i++) {
			rotate(pos[turn_order[i]]);	//ȸ��
			//test();
		}
		findMin();	//�ּڰ� ã��
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