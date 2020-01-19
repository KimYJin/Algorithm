#include <string>
#include <vector>
#include<iostream>
#include <algorithm>

using namespace std;

#define MAX 2000

int dp[MAX][MAX] = { 0, };	//��ȭ��: D[i][j] = ���� ī�尡 i, ������ ī�尡 j��° ī���� �� �ִ� ������
int num=0;
vector<int> L, R;

/*
https://www.welcomekakao.com/learn/courses/30/lessons/42896
(1) ���� ī�� ��� (2) ���� ī�常 (3) ������ ī�常 ������ ���
dp[i][j] = ���� ī�尡 i, ������ ī�尡 j��° ī���� �� �ִ� ������
dp[i][j] = �� 3���� ��� �� �ִ밪 
*/

int step(int i, int j) {

	if (i >= num || j >= num) 
		return 0;

	if (dp[i][j] > 0)
		return dp[i][j];

	//���� �Ǵ� ���� ī�� ������ ���
	dp[i][j] = max(step(i + 1, j), step(i + 1, j + 1));

	//������ ī�� ������ ���
	if (L[i] > R[j]) {
		dp[i][j] = max(dp[i][j], step(i, j + 1) + R[j]);
	}

	return dp[i][j];
}

int solution(vector<int> left, vector<int> right) {	
	L = left; R = right;
	num = left.size();
	return step(0,0);	//���� �� �ִ� ���� ������ �ִ밪
}

int main(void) {

	vector<int> left = { 3,2,5 };	//���� ������ ī��
	vector<int> right = { 2,4,1 };	//������ ������ ī��

	int answer = solution(left,right);	//������ ��ĥ �� �ִ� ���� �ִ�

	cout << answer;
	return 0;
}
