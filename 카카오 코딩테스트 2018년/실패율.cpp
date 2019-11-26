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
		return (i.second < j.second);	//실패율이 같은 스테이지가 있다면 작은 번호의 스테이지가 먼저 오도록
	else
		return i.first > j.first;	//실패율이 높은 스테이지부터 내림차순으로 정렬.
}

vector<int> solution(int N, vector<int> stages) {
	
	vector<int> answer;

	vector<pair<double, int>> pv;
	vector<pair<double, int>>::iterator iterv;

	double user = stages.size();

	int a[502] = { 0 };	

	//현재 스테이지에 멈춘 사용자 수
	for (int stage : stages) {
		a[stage] = a[stage] + 1;
	}

	//실패율 계산
	for (int stage = 1; stage < N + 1; stage++)
	{
		if(a[stage]==0)		// 또는 if (user == 0). 스테이지에 도달한 사용자가 0명인 경우 예외 처리해야함***
			pv.push_back(make_pair(0,stage));
		else
			pv.push_back(make_pair((double)a[stage]/user, stage));

		user = user - a[stage];
	}

	//sort by value 내림차순 정렬.. 
	sort(pv.begin(), pv.end(), comp);

	for (iterv = pv.begin(); iterv != pv.end(); iterv++)
	{
		answer.push_back(iterv->second);
		cout << iterv->first << "	" << iterv->second << endl;
	}

	return answer;
}

int main() {

	int N = 5;	//전체 스테이지의 개수 N
	vector<int> stages = { 2, 1, 2, 6, 2, 4, 3, 3 };	//게임 이용자의 현재 스테이지 번호가 담긴 배열 stages
														//N + 1 은 마지막 스테이지 까지 클리어 한 사용자
	solution(N, stages);

	return 0;
}

