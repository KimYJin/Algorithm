#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<queue>
#include <string>
#include<functional>
#include <vector>
#include<sstream>
#include<map>
#include<algorithm>

using namespace std;

bool comp(pair<double, int> i, pair<double, int> j)
{
	if (i.first == j.first)
		return (i.second < j.second);	//�������� ���� ���������� �ִٸ� ���� ��ȣ�� ���������� ���� ������
	else
		return i.first > j.first;	//�������� ���� ������������ ������������ ����.
}

vector<int> solution(int N, vector<int> stages) {
	
	vector<int> answer;

	vector<pair<double, int>> pv;
	vector<pair<double, int>>::iterator iterv;

	double user = stages.size();

	int a[502] = { 0 };	

	//���� ���������� ���� ����� ��
	for (int stage : stages) {
		a[stage] = a[stage] + 1;
	}

	//������ ���
	for (int stage = 1; stage < N + 1; stage++)
	{
		if(a[stage]==0)		// �Ǵ� if (user == 0). ���������� ������ ����ڰ� 0���� ��� ���� ó���ؾ���***
			pv.push_back(make_pair(0,stage));
		else
			pv.push_back(make_pair((double)a[stage]/user, stage));

		user = user - a[stage];
	}

	//sort by value �������� ����.. 
	sort(pv.begin(), pv.end(), comp);

	for (iterv = pv.begin(); iterv != pv.end(); iterv++)
	{
		answer.push_back(iterv->second);
		cout << iterv->first << "	" << iterv->second << endl;
	}

	return answer;
}

int main() {

	int N = 5;	//��ü ���������� ���� N
	vector<int> stages = { 2, 1, 2, 6, 2, 4, 3, 3 };	//���� �̿����� ���� �������� ��ȣ�� ��� �迭 stages
														//N + 1 �� ������ �������� ���� Ŭ���� �� �����
	solution(N, stages);

	return 0;
}

