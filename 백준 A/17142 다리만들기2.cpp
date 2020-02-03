/*
https://www.acmicpc.net/problem/17472
��� ���� �����ϱ� ���� �ٴٿ� �Ǽ��ϴ� �ٸ��� �ּڰ� ���.
�ٸ��� ������ �߰��� �ٲ�� �ȵȴ�. �ٸ��� ���̴� 2 �̻�.
��� ���� �����ϴ� ���� �Ұ����ϸ� -1�� ���.
*/

#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

int row = 0, col = 0;
const int MAX = 10;
int land_count = 0;	//�� ����
int answer = MAX*MAX;

int m[MAX][MAX] = { -1, };	//����
vector<pair<pair<int, int>, int>> bridge_list;

bool check[MAX][MAX] = { false, };
bool connect[MAX][MAX] = { false, };
bool check_bridge[MAX]= { false, };
bool check_island[MAX] = { false };

int dr[4] = { -1,0,1,0 }, dc[4] = { 0,1,0,-1 };

void input() {

	cin >> row >> col;	

	for (int r = 0; r < row; r++) {
		for (int c = 0; c < col; c++) {
			cin >> m[r][c];
		}
	}
}

void dfs(int r, int c, int n) {

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (nr < 0 || nr >= row || nc < 0 || nc >= col)
				continue;

			if (!check[nr][nc] && m[nr][nc] == 1) {
				m[nr][nc] = n;
				check[nr][nc] = true;
				dfs(nr, nc,n);
			}
		}
}

/*
���� ��ȣ ���̱�
*/
void labelLand(void) {

	//�� ��ȣ ���̱� -> DFS�� ����
	int num = 1;
	for (int r = 0; r < row; r++) {
		for (int c = 0; c < col; c++) {

			if (!check[r][c] && m[r][c] == 1) {
				m[r][c] = num;
				check[r][c] = true;
				dfs(r, c,num++);
			}
		}
	}
	land_count = num - 1;
}

/*
���� �� ���̸� �մ� �ٸ� ���ϱ�
*/
void findBridge() {
	for (int r = 0; r < row; r++) {
		for (int c = 0; c < col; c++) {

			if (m[r][c] > 0) {

				//�Ʒ��� ��ġ�� �� Ž��
				if (r + 1 < row && m[r + 1][c] == 0) {
					int start = m[r][c];
					int temp_r = r+1;
					int distance = 0;
					int end=0;

					while (temp_r < row && m[temp_r][c] == 0) {
						temp_r++;
						distance++;
					}

					if(temp_r < row)
						end = m[temp_r][c];

					if (end > 0 && start != end && distance > 1 )
						bridge_list.push_back({ { start,end }, distance });
					
				}
				//������ ��ġ�� �� Ž��
				if (c + 1 < col && m[r][c + 1] == 0) {
					int start = m[r][c];
					int temp_c = c+1;
					int distance = 0;
					int end = 0;

					while (temp_c < col && m[r][temp_c] == 0) {
						temp_c++;
						distance++;
					}
					if (temp_c < col)
						end = m[r][temp_c];

					if (end > 0 && start != end && distance > 1)
						bridge_list.push_back({ { start,end}, distance });
				}
			}
		}
	}
}

/*
��� ���� ����Ǿ� �ִ��� �˻�
*/
bool isLinkAllLand() {

	memset(check_island, false, sizeof(check_island));
	memset(connect, false, sizeof(connect));

	for (int i = 0; i < bridge_list.size(); i++) {
		if (check_bridge[i]) {
			int x = bridge_list[i].first.first;
			int y = bridge_list[i].first.second;
			connect[x][y] = connect[y][x] = true;
		}
	}

	queue<int> q;
	q.push(1);
	check_island[1] = true;

	int edge_count = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		//��� ���� ����� ���
		if (edge_count == land_count - 1) {
			return true;
		}

		for (int i = 1; i <= land_count; i++) {
			if (connect[cur][i] && !check_island[i]) {
				check_island[i] = true;
				q.push(i);
				edge_count++;
			}
		}
	}
	return false;
}

/*
�ٸ��� ����
*/
void selectBridge(int idx, int count, int sum) {

	if (count > 0 && isLinkAllLand())
		answer = min(answer, sum);

	for (int i = idx; i < bridge_list.size(); i++) {
		if (!check_bridge[i]) {
			check_bridge[i] = true;
			selectBridge(i+1, count + 1, sum + bridge_list[i].second);
			check_bridge[i]= false;
		}
	}
}

int main(void) {

	input();	//0. �Է� �ޱ�
	labelLand();	//1. ���� ��ȣ ���̱�
	findBridge();	//2. �� ���̿� ������ �� �ִ� �ٸ� ã��
	
	selectBridge(0,0,0);	//3. ��� ���� �մ� �ٸ��� �ּڰ� ���ϱ�
	
	if (answer == MAX*MAX)
		cout << -1;
	else
		cout << answer;
		
	return 0;
}
