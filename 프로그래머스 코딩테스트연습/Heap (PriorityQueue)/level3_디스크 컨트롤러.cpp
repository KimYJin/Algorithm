#include <string>
#include <vector>
#include<queue>
#include<iostream>
#include<functional>

using namespace std;

//�ҿ�ð��� ª�� �۾����� ó���ؾ� �ִ� ��� �ð��� ���� �� �ִ�.
struct cmp {
	bool operator()(vector<int>a, vector<int>b) {
		return (a[1] > b[1]);
	}
};

//�۾��� ��û���� ������� �ɸ� �ð� ���'�� �ּҰ� �����ϴ� ����.
int solution(vector<vector<int>> jobs) {
	int answer = 0;
	int index = 0;
	int currentTime = 0;

	sort(jobs.begin(), jobs.end());	//�������� ����

	priority_queue<vector<int>, vector<vector<int>>, cmp> pq;

	while (index < jobs.size() || !pq.empty()) {

		//���� �ð� ���� ������ �� �ִ� �۾����� �켱���� ť�� �߰�
		while (index < jobs.size() && currentTime >= jobs[index][0]) {
			pq.push(jobs[index]);
			++index;
		}

		//���డ���� �۾��� �ִٸ� �ҿ�ð��� �ּ��� �۾��� ����
		if (!pq.empty()) {	
			answer += (currentTime - pq.top()[0]) + pq.top()[1];	//�۾��� ���ð�,�ҿ�ð� ���ϱ�
			currentTime += pq.top()[1];		//�۾� ������ ��ģ �ð� (�ҿ�ð� ���ϱ�)
			pq.pop();
		}
		//ť�� ����ִٸ� ���� �۾� �ð����� �ѱ�
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