/*
https://www.welcomekakao.com/learn/courses/30/lessons/49189
1번 노드에서 가장 멀리 떨어진 노드의 개수를 구하기.
가장 멀리 떨어진 노드란 최단경로의 간선 개수가 가장 많은 노드를 의미.
*/

#include<vector>
#include<iostream>
#include<queue>
#include<functional>	//for greater<int>()
#include<algorithm>	//for sort

using namespace std;

int solution(int n, vector<vector<int>> edge) {	//노드 개수, 간선 정보
	int answer = 0;
	int start = 1;

	vector<vector<int>> graph(n+1,vector<int>());
	vector<int> dist(n+1,0);
	vector<bool>visit(n + 1, false);
	queue<int> q;

	//노드 사이의 양방향 간선 정보 초기화
	for (int i = 0; i < edge.size(); i++) {
			graph[edge[i][0]].push_back(edge[i][1]);
			graph[edge[i][1]].push_back(edge[i][0]);
	}

	//시작점 초기화
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

	//edge 배열 각 행 {a, b}는 a번 노드와 b번 노드 사이에 간선이 있다는 의미
	cout << solution(6, { {3, 6},{4, 3},{3, 2},{1, 3},{1, 2},{2, 4},{5, 2} });

	return 0;
}