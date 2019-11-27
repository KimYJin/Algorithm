#include <string>
#include <vector>
#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

vector<string> answer;
int t_size = 0;
bool check = false;	//���� ��θ� ã�Ҵ��� ����

void dfs(vector<vector<string>> tickets, string next, vector<string> route, vector<bool> visit) {
	
	//��� ���ø� �湮�� ��� Ž������
	if (route.size() == t_size) {
		route.push_back(next);	//������ �������� ��ο� �߰�
		answer = route;	
		check = true;	//�߰����� Ž���� �Ͼ�� �ʵ��� '������� ã����'�� ǥ��
		return;
	}

	//1.�湮 ������ ���� Ž��
	for (int i = 0; i < t_size; i++) {
	
		if (check == true) 	break;	//������� ã������ �߰����� Ž��(for��) �ߴ�

		//2.���� �湮
		if (tickets[i][0] == next && !visit[i]) {
			route.push_back(tickets[i][0]);
			visit[i] = true;

			//3.��� - ���� ���� Ž��
			dfs(tickets, tickets[i][1],route, visit);

			//4.�� dfs�Լ� ����Ǹ�, for�ݺ����� ���� ���󺹱�(�湮���)
			route.pop_back();
			visit[i] = false;
		}
	}
}

vector<string> solution(vector<vector<string>> tickets) {
	
	t_size = tickets.size();
	vector<bool> visit(t_size, false);
	
	//1.���ĺ� �� ����
	sort(tickets.begin(), tickets.end());

	//2.����� ICN ã��
	for (int i = 0; i < t_size; i++) {

		if (tickets[i][0] == "ICN") {
		
			answer.push_back(tickets[i][0]);	//ICN�� �����ο� �߰�
			visit[i] = true;
			
			dfs(tickets, tickets[i][1],answer, visit);	//3.ICN �������� ��� Ž��
			
			if (check == true) {	//4-1.��� ���� �湮������ ��ζ�� ��� ���
				return answer;
			}
			else{	//4-2.��� ���ø� �湮���� ���ϴ� ��ο��ٸ� ���� ICN ã�� ���� �湮��� ó��
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