#include <string>
#include <vector>
#include<iostream>
#include<queue>

using namespace std;
const int MAX = 200;

queue<int> q;
int visited[MAX] = { 0, };

//��Ʈ��ũ Ž��
void dfs(int n, vector<vector<int>> computers) {

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		visited[cur] = 1;

		for (int i = 0; i < n; i++) {
			if (computers[cur][i] == 1 && visited[i] != 1) {
				q.push(i);
			}
		}
	}
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	int network = n;

	for (int i = 0; i < n; i++) {
		//�湮���� ���� ��ǻ�� �������� ��Ʈ��ũ Ž��
		if (visited[i] != 1) {
			q.push(i);
			answer++;
			dfs(n, computers);
		}
	}


	return answer;
}