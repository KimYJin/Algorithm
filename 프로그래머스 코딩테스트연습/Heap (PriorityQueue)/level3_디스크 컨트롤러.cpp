#include <string>
#include <vector>
#include<queue>
#include<iostream>
#include<functional>

using namespace std;

//소요시간이 짧은 작업부터 처리해야 최단 평균 시간을 구할 수 있다.
struct cmp {
	bool operator()(vector<int>a, vector<int>b) {
		return (a[1] > b[1]);
	}
};

//작업의 요청부터 종료까지 걸린 시간 평균'의 최소값 리턴하는 문제.
int solution(vector<vector<int>> jobs) {
	int answer = 0;
	int index = 0;
	int currentTime = 0;

	sort(jobs.begin(), jobs.end());	//오름차순 정렬

	priority_queue<vector<int>, vector<vector<int>>, cmp> pq;

	while (index < jobs.size() || !pq.empty()) {

		//현재 시간 기준 실행할 수 있는 작업들은 우선순위 큐에 추가
		while (index < jobs.size() && currentTime >= jobs[index][0]) {
			pq.push(jobs[index]);
			++index;
		}

		//실행가능한 작업이 있다면 소요시간이 최소인 작업을 실행
		if (!pq.empty()) {	
			answer += (currentTime - pq.top()[0]) + pq.top()[1];	//작업의 대기시간,소요시간 더하기
			currentTime += pq.top()[1];		//작업 실행을 마친 시간 (소요시간 더하기)
			pq.pop();
		}
		//큐가 비어있다면 다음 작업 시간으로 넘김
		else {	
			currentTime = jobs[index][0];
		}
	}
	
	return answer/jobs.size();
}

int main(void) {

	vector<vector<int>> jobs = { {0,3},{1,9},{2,6} };
	int answer = solution(jobs);
	cout << answer;

	return 0;
}