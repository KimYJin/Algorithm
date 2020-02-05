/*
게리맨더링 https://www.acmicpc.net/problem/17471
구역을 두 개의 선거구로 나눠야 하고, 선거구의 구역은 모두 연결되어 있어야 한다.
두 선거구에 포함된 인구의 차이의 최솟값을 구해라.
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
		cin >> temp;	//각 구역과 인접한 구역 수

		//각 구역과 인접한 구역의 번호
		for (int t = 1; t <= temp; t++) {
			cin >> j;	
			connect[i][j] = true;
		}
	}
}

bool isConnect(int s,int total,bool tag, int *people_num) {

	//s 구역을 시작으로 연결된 구역 모두 찾기
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

	//모두 연결 여부를 반환
	if (count == total)
		return true;
	else
		return false;

}

void combination(int s,int count) {
	int people_num1 = 0, people_num2 = 0;
	bool allConnected1 = false , allConnected2= false;

	//2개로 나뉘는 선거구의 중복검사 방지 위해 반만 검사
	if (count > N / 2)
		return;

	allConnected1 = isConnect(s, count, true, &people_num1);

	//선거구가 모두 연결된 경우, 다른 선거구도 검사
	if (allConnected1) {

		for (int i = 1; i <= N; i++) {
			if (!selected[i]) {
				allConnected2 = isConnect(i, N - count, false, &people_num2);
				break;
			}
		}

		//두 선거구 모두 연결됐으면 인구수 차이 구하기
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
