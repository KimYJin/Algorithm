/*
�Ը��Ǵ��� https://www.acmicpc.net/problem/17471
������ �� ���� ���ű��� ������ �ϰ�, ���ű��� ������ ��� ����Ǿ� �־�� �Ѵ�.
�� ���ű��� ���Ե� �α��� ������ �ּڰ��� ���ض�.
*/

#include<vector>
#include<algorithm>
#include<iostream>
#include<queue>
#include<cstring>


using namespace std;

const int MAX = 10;
int N;
int people[MAX+1] = { 0, };
bool connect[MAX+1][MAX+1] = { 0, };
bool selected[MAX+1] = { 0, };
bool check[MAX + 1] = { 0, };
int gap = 1000;

void input() {

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> people[i];
	}

	int temp,j;
	for (int i = 1; i <= N; i++) {
		cin >> temp;	//�� ������ ������ ���� ��

		//�� ������ ������ ������ ��ȣ
		for (int t = 1; t <= temp; t++) {
			cin >> j;	
			connect[i][j] = true;
		}
	}
}

bool isConnect(int s,int total,bool tag, int *people_num) {

	//s ������ �������� ����� ���� ��� ã��
	memset(check, false, sizeof(check));
	int count = 0;

	queue<int> q;
	q.push(s);
	check[s] = true;
	*people_num = people[s];
	count++;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 1; i <= N; i++) {
			if (selected[i]==tag && connect[cur][i] && !check[i]) {
				check[i] = true;
				count++;
				*people_num += people[i];
				q.push(i);
			}
		}	
	 }

	//��� ���� ���θ� ��ȯ
	if (count == total)
		return true;
	else
		return false;

}

void combination(int s,int count) {
	int people_num1 = 0, people_num2 = 0;
	bool allConnected1 = false , allConnected2= false;

	//2���� ������ ���ű��� �ߺ��˻� ���� ���� �ݸ� �˻�
	if (count > N / 2)
		return;

	allConnected1 = isConnect(s, count, true, &people_num1);

	//���ű��� ��� ����� ���, �ٸ� ���ű��� �˻�
	if (allConnected1) {

		for (int i = 1; i <= N; i++) {
			if (!selected[i]) {
				allConnected2 = isConnect(i, N - count, false, &people_num2);
				break;
			}
		}

		//�� ���ű� ��� ��������� �α��� ���� ���ϱ�
		if (allConnected2) {
			gap = min(abs(people_num1 - people_num2), gap);
		}
	}

	for (int i = 1; i <= N; i++) {
		if (!selected[i]) {
			selected[i] = true;
			combination(i, count + 1);
			selected[i] = false;
		}
	}
}

int main(void) {

	input();

	for (int i = 1; i <= N; i++) {
		selected[i]=true;
		combination(i,1);
		selected[i] = false;
	}
	if (gap == 1000) {
		cout<< -1;
	}
	else {
		cout << gap;
	}

	return 0;
}
