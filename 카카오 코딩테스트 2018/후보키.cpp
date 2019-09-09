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

int countbit(int n) {
	int count = 0;

	while (n) {
		if (n&1) count++;
		n = n >> 1;
	}

	return count;
}

bool comp(int a, int b) {
	int x = countbit(a);
	int y = countbit(b);

	return x > y;
}

bool unique(vector<vector<string>> relation, int tupleNum, int attributeNum, int subset) {
	
	//��� Ʃ�ÿ���
	for (int t = 0; t < tupleNum - 1; t++) {
		for (int t2 = t+1; t2 < tupleNum; t2++) {

			bool isSame = true;	

			//subset �� �����ϴ� �� �Ӽ� ���� ���ϼ� �˻�
			for (int a = 0; a < attributeNum; a++)	
			{
				if ((subset & 1 << a) == 0) // 1,100,100,1000 �� ��->�����ϴ� �Ӽ� �˾Ƴ� (ex.{�й�,�̸� 0011} �� ��� {�й� 0001},{�̸� 0010} ���� �˻�)
					continue;

				//** if ((subset & 1 << a) == 1) �������� �Ʒ� if�� �����ϸ� �ȵȴ�. subset{0011�й�,�̸�} & a{0010 �̸�} -> 0010 ,�� 1�� �ƴ� ���� �����Ƿ�  **

				if (relation[t][a] != relation[t2][a]) //2���� Ʃ�� �� �Ӽ� �� �� �Ӽ� �ϳ��� �ٸ���, ������ �Ӽ� �߰� �� ���ص� �̹� ������ (�й� ��-> �ٸ���, �̸� �� �ʿ�x)
				{	
					isSame = false;
					break;
				}	
			}
			if (isSame)	// Ʃ�� �� ������ �� ���ϼ�X
				return false;
		}
	}
	return true;	//��� Ʃ�ÿ��� ���ϼ� ����
}

int solution(vector<vector<string>> relation) {
	int answer = 0;
	int tupleNum = relation.size();
	int attributeNum = relation.front().size();
	
	vector<int> candidateKey;
	vector<int> ::iterator iter;

	int subsetNum = (1 << attributeNum) -1;	//�� �κ������� ���� (0000,0001,, ~ 1111)

	for (int subset = 1; subset <= subsetNum; subset++)		//0�� �������̴� ����
	{
		if (unique(relation, tupleNum, attributeNum, subset))	//���ϼ� �˻�
			candidateKey.push_back(subset);

	}

	//��Ʈ 1�� ���� ������ ����
	sort(candidateKey.begin(), candidateKey.end(), comp);
	
	//�ּҼ� �˻�
	while (!candidateKey.empty()) {
		int subset = candidateKey.back();
		candidateKey.pop_back();
		answer++;
		
		for (iter = candidateKey.begin(); iter != candidateKey.end();) {
			if ((*iter & subset) == subset)
				iter = candidateKey.erase(iter);	//���� iterator 
			else
				++iter;
		}
	}

	cout << answer;
	return answer;
}

int main() {

	vector<vector<string>> relation =
	{ {"100", "ryan", "music", "2"},{"200", "apeach", "math", "2"},
	{"300", "tube", "computer", "3"},{"400", "con", "computer", "4"},
	{"500", "muzi", "music", "3"},{"600", "apeach", "music", "2"}};

	int answer = solution(relation);

	return 0;
}

