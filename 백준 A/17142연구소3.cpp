//모든 빈 칸에 바이러스를 퍼뜨리는 최소 시간 구하기
//활성 바이러스가 비활성 바이러스가 있는 칸으로 가면 비활성 바이러스가 활성으로 변한다.
//0은 빈 칸, 1은 벽, 2는 바이러스를 놓을 수 있는 위치

using namespace std;

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

struct virus {
	int r, c, t;
};

const int MAX = 50;
int lab[MAX][MAX] = { 0, };
int copy_lab[MAX][MAX] = { 0, };
int size_lab = 0, virus_num = 0;
bool check[MAX][MAX] = { false, };
int time = 0;
int result = 987654321;
vector<virus> virus_list;

int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };

void copy() {
	for (int r = 0; r < size_lab; r++) {
		for (int c = 0; c < size_lab; c++) {
			copy_lab[r][c] = lab[r][c];
		}
	}
}

//모든 빈칸에 바이러스 퍼뜨렸는지 검사
bool isAll() {

	for (int r = 0; r < size_lab; r++) {
		for (int c = 0; c < size_lab; c++) {
			if (copy_lab[r][c] == 0) {
				return false;
			}
		}
	}
	return true;
}
/*
void print() {
	cout << "** TESTING **" << endl;

	for (int r = 0; r < size_lab; r++) {
		for (int c = 0; c < size_lab; c++) {
				cout << copy_lab[r][c] <<" ";
		}
		cout << endl;
	}
	cout << "* time: " << time << endl;
}*/

void simulation() {

	int cr,cc,ct,nr,nc;
	bool isChange=false;
	time = 0;
	
	queue<virus> q;

	for (virus v : virus_list) {
		q.push(v);
	}

	while (!q.empty()) {
		virus cv = q.front();
		q.pop();

		cr = cv.r;
		cc = cv.c;
		ct = cv.t;

		//4방향 탐색
		for (int i = 0; i < 4; i++) {
			nr = cr + dr[i];
			nc = cc + dc[i];

			if (nr<0 || nr > size_lab - 1 || nc < 0 || nc > size_lab - 1)
				continue;

			if (copy_lab[nr][nc] == 0) {
				copy_lab[nr][nc] = 1;
				virus nv = { nr,nc,ct + 1 };
				q.push(nv);
			}
		}
	}
	time = ct;
}

//완전탐색 - 바이러스 배치
void location(int cnt) {

	if (cnt == virus_num) {
		copy();
		simulation();
		//print();
		if (isAll()) {
			result = min(time, result);
			//cout << endl << "** RESULT :" << result << endl << endl;
		}
		return;
	}
	
	for (int r = 0; r < size_lab; r++) {
		for (int c = 0; c < size_lab; c++) {
			if (lab[r][c]==2 && !check[r][c])	{
				virus v = { r,c,0 };
				virus_list.push_back(v);
				check[r][c] = true;
				location(cnt + 1);
				check[r][c] = false;
				virus_list.pop_back();
			}
		}
	}	
}

int main(void) {

	cin >> size_lab >> virus_num;

	for (int r = 0; r < size_lab; r++) {
		for (int c = 0; c < size_lab; c++) {
			cin >> lab[r][c];
		}
	}

	location(0);

	if (result == 987654321)
		cout << -1;
	else
		cout << result;

	return 0;
}