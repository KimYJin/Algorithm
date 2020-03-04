/*
https://www.acmicpc.net/problem/17142
연구소의 모든 빈 칸에 바이러스가 있게 되는 최소 시간을 출력한다.
비활성 바이러스가 활성 바이러스와 만나면 활성으로 변한다.
*/

#include<iostream>
#include <cstring>
#include<queue>
#include<vector>

using namespace std;

struct virus {
	int r, c;
};

const int LAB_MAX = 51, V_MAX = 11;

int lab_size = 0, active_virus_num = 0, empty_num = 0, virus_num = 0;
int result = 987654321;

int lab[LAB_MAX][LAB_MAX] = { 0, };
int dist[LAB_MAX][LAB_MAX] = { 0, };
bool active[V_MAX] = { false, };
vector<virus> virus_list;
queue<virus> q;

int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };

//시뮬레이션 - BFS
void simulate() {

	int time = 0, infect_num = 0;
	memset(dist, -1, sizeof(dist));

	for (int i = 0; i < virus_num; i++) {
		if (active[i]) {
			virus v = virus_list[i];
			q.push(v);
			dist[v.r][v.c] = 0;
		}
	}

	while (!q.empty()) {
		virus cv = q.front();
		q.pop();

		int cr = cv.r, cc = cv.c;

		for (int i = 0; i < 4; i++) {
			int nr = cr + dr[i];
			int nc = cc + dc[i];

			if (nr < 0 || nr >= lab_size || nc < 0 || nc >= lab_size
				|| dist[nr][nc] != -1 || lab[nr][nc] == 1)
				continue;

			q.push({ nr,nc });
			dist[nr][nc] = dist[cr][cc] + 1;

			if (lab[nr][nc] == 0) {	// 빈 칸
				infect_num++;
				time = dist[nr][nc];
			}
		}//end for

		 //print();
	}//end while

	if (infect_num == empty_num) {
		result = min(time, result);
	}
}

//활성 바이러스 배치 - 브루트포스
void locate(int idx, int cnt) {

	if (cnt == active_virus_num) {
		simulate();
		return;
	}
	else if (cnt > active_virus_num) {
		return;
	}

	for (int i = idx; i < virus_num; i++) {
		if (!active[i]) {
			active[i] = true;
			locate(i + 1, cnt + 1);
			active[i] = false;
		}
	}
}

int main(void) {

	cin >> lab_size >> active_virus_num;

	for (int r = 0; r < lab_size; r++) {
		for (int c = 0; c < lab_size; c++) {
			cin >> lab[r][c];

			if (lab[r][c] == 0) {
				empty_num++;
			}
			else if (lab[r][c] == 2) {
				virus_list.push_back({ r,c });
			}
		}
	}

	virus_num = virus_list.size();

	locate(0, 0);

	if (result == 987654321)
		cout << -1;
	else
		cout << result;

	return 0;
}