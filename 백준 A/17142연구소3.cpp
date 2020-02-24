//��� �� ĭ�� ���̷����� �۶߸��� �ּ� �ð� ���ϱ�
//Ȱ�� ���̷����� ��Ȱ�� ���̷����� �ִ� ĭ���� ���� ��Ȱ�� ���̷����� Ȱ������ ���Ѵ�.
//0�� �� ĭ, 1�� ��, 2�� ���̷����� ���� �� �ִ� ��ġ

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

//��� ��ĭ�� ���̷��� �۶߷ȴ��� �˻�
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

		//4���� Ž��
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

//����Ž�� - ���̷��� ��ġ
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