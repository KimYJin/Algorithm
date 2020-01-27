/*
https://www.welcomekakao.com/learn/courses/30/lessons/49189
1�� ��忡�� ���� �ָ� ������ ����� ������ ���ϱ�.
���� �ָ� ������ ���� �ִܰ���� ���� ������ ���� ���� ��带 �ǹ�.
*/

#include<vector>
#include<iostream>
#include<queue>
#include<functional>	//for greater<int>()
#include<algorithm>	//for sort

using namespace std;

int solution(int n, vector<vector<int>> edge) {	//��� ����, ���� ����
	int answer = 0;
	int start = 1;

	vector<vector<int>> graph(n+1,vector<int>());
	vector<int> dist(n+1,0);
	vector<bool>visit(n + 1, false);
	queue<int> q;

	//��� ������ ����� ���� ���� �ʱ�ȭ
	for (int i = 0; i < edge.size(); i++) {
			graph[edge[i][0]].push_back(edge[i][1]);
			graph[edge[i][1]].push_back(edge[i][0]);
	}

	//������ �ʱ�ȭ
	q.push(1);
	visit[1] = true;
	dist[1] = 0;

	while (!q.empty()) {
		int start = q.front();
		q.pop();

		for (int i = 0; i < graph[start].size(); i++) {
			int end = graph[start][i];

			if (visit[end] == false) {
				q.push(end);
				visit[end] = true;
				dist[end] = dist[start] + 1;
			}
		}
	}

	sort(dist.begin(), dist.end(), greater<int>());

	int max = dist[0];
	for (int d : dist) {
		if (d == max)answer++;
		else break;
	}

	return answer;
}

int main(void) {

	//edge �迭 �� �� {a, b}�� a�� ���� b�� ��� ���̿� ������ �ִٴ� �ǹ�
	cout << solution(6, { {3, 6},{4, 3},{3, 2},{1, 3},{1, 2},{2, 4},{5, 2} });

	return 0;
}