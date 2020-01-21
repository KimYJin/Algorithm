#include <string>
#include <vector>
#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

vector<string> answer;
int t_size = 0;
bool check = false;	//최종 경로를 찾았는지 여부

void dfs(vector<vector<string>> tickets, string next, vector<string> route, vector<bool> visit) {
	
	//모든 도시를 방문한 경우 탐색종료
	if (route.size() == t_size) {
		route.push_back(next);	//마지막 도착지를 경로에 추가
		answer = route;	
		check = true;	//추가적인 탐색이 일어나지 않도록 '최종경로 찾았음'을 표시
		return;
	}

	//1.방문 가능한 도시 탐색
	for (int i = 0; i < t_size; i++) {
	
		if (check == true) 	break;	//최종경로 찾았으면 추가적인 탐색(for문) 중단

		//2.도시 방문
		if (tickets[i][0] == next && !visit[i]) {
			route.push_back(tickets[i][0]);
			visit[i] = true;

			//3.재귀 - 다음 도시 탐색
			dfs(tickets, tickets[i][1],route, visit);

			//4.위 dfs함수 종료되면, for반복문을 위해 원상복귀(방문취소)
			route.pop_back();
			visit[i] = false;
		}
	}
}

vector<string> solution(vector<vector<string>> tickets) {
	
	t_size = tickets.size();
	vector<bool> visit(t_size, false);
	
	//1.알파벳 순 정렬
	sort(tickets.begin(), tickets.end());

	//2.출발지 ICN 찾기
	for (int i = 0; i < t_size; i++) {

		if (tickets[i][0] == "ICN") {
		
			answer.push_back(tickets[i][0]);	//ICN을 여행경로에 추가
			visit[i] = true;
			
			dfs(tickets, tickets[i][1],answer, visit);	//3.ICN 기준으로 경로 탐색
			
			if (check == true) {	//4-1.모든 도시 방문가능한 경로라면 결과 출력
				return answer;
			}
			else{	//4-2.모든 도시를 방문하지 못하는 경로였다면 다음 ICN 찾기 위해 방문취소 처리
				answer.pop_back();
				visit[i] = false;
			}
		}
	}
	return answer;
}

int main() {
	
	vector<vector<string>> tickets = { {"ICN", "SFO"},{"ICN", "ATL"},{"SFO", "ATL"},{"ATL", "ICN"},{"ATL","SFO" } };

	vector<string> answer = solution(tickets);

	for(string s:answer)
		cout << s<<" ";
}