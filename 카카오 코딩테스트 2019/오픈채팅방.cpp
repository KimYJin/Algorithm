#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<queue>
#include <string>
#include <vector>
#include<sstream>
#include<map>

using namespace std;


vector<string> solution(vector<string> record) {
	string id, nick, state;
	map<string, string> idmap;

	for (string s : record)		//�� ���ڿ�
	{
		//���� ���� �ܾ� ����
		stringstream ss(s);

		ss >> state;
		ss >> id;
		ss >> nick;

		if (state == "Enter") {
			idmap[id] = nick;
		}
		else if (state == "Change") {
			idmap[id] = nick;
		}
	}
	vector<string> answer;
	for (string s : record)		//�� ���ڿ�
	{
		//���� ���� �ܾ� ����
		stringstream ss(s);

		ss >> state;
		ss >> id;
		ss >> nick;

		if (state == "Enter") {
			answer.insert(answer.end(), idmap[id] + "���� ���Խ��ϴ�.");
		}
		else if (state == "Leave") {
			answer.insert(answer.end(), idmap[id] + "���� �������ϴ�.");
		}
	}

	
	for (string s : answer)		//�� ���ڿ�
	{
		cout << s << endl;
	}

	return answer;
}

int main() {

	vector<string> record = { "Enter uid1234 Muzi",
		"Enter uid4567 Prodo",
		"Leave uid1234",
		"Enter uid1234 Prodo",
		"Change uid4567 Ryan" };
		
	solution(record);

	return 0;
}

