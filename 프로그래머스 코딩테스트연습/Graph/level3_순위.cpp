/*
https://www.welcomekakao.com/learn/courses/30/lessons/49191
������ �� n, �κ������� �нǵ� ��� ��� results�� �̿���
��Ȯ�ϰ� ������ �ű� �� �ִ� ������ ���� return.
results �迭 �� �� [A, B]�� A ������ B ������ �̰�ٴ� �ǹ�.
...
���̳��� ���α׷����� ������� �ϴ� �÷��̵� �ͼ� �˰��� ���� �̿�! 
*/

#include <string>
#include <vector>
#include <iostream>
#include<algorithm>

using namespace std;

int solution(int n, vector<vector<int>> results) {
	int answer = 0;

	vector<vector<bool>> d(n + 1, vector<bool>(n + 1, false));

	for (auto r : results) {
		d[r[0]][r[1]] = true;
	}

	//k:���İ��� ���.. �̰��� �������� 3�� for�� ����
	for (int k = 1; k <= n; k++) {
		//i:��߳�� (�¸�)
		for (int i = 1; i <= n; i++) {
			//j:������� (�й�)
			for (int j = 1; j <= n; j++) {
				if (d[i][k] && d[k][j]) {	//������ �� ��밡 �¸��ϴ� ��쵵
					d[i][j] = true;	//���� �¸��� ó��
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		
		int count = 0;

		for (int j = 1; j <= n; j++) {
			if (d[i][j] || d[j][i])	//���� �Ǻ��� �����ϸ� count����
				count++;
		}

		if (count == n - 1)	//n-1���� ���� ����� ������ ��Ȯ�� ��� �ľ� ����
			answer++;
	}

	return answer;
}

int main(void) {
	cout << solution(5, { {4, 3},{4, 2},{3, 2},{1, 2},{2, 5} });
}