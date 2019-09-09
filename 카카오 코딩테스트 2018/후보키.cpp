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
	
	//모든 튜플에서
	for (int t = 0; t < tupleNum - 1; t++) {
		for (int t2 = t+1; t2 < tupleNum; t2++) {

			bool isSame = true;	

			//subset 이 포함하는 각 속성 별로 유일성 검사
			for (int a = 0; a < attributeNum; a++)	
			{
				if ((subset & 1 << a) == 0) // 1,100,100,1000 과 비교->포함하는 속성 알아냄 (ex.{학번,이름 0011} 일 경우 {학번 0001},{이름 0010} 각각 검사)
					continue;

				//** if ((subset & 1 << a) == 1) 조건으로 아래 if문 실행하면 안된다. subset{0011학번,이름} & a{0010 이름} -> 0010 ,즉 1이 아닌 값이 나오므로  **

				if (relation[t][a] != relation[t2][a]) //2개의 튜플 간 속성 비교 시 속성 하나라도 다르면, 나머지 속성 추가 비교 안해도 이미 유일함 (학번 비교-> 다르면, 이름 비교 필요x)
				{	
					isSame = false;
					break;
				}	
			}
			if (isSame)	// 튜플 간 비교했을 때 유일성X
				return false;
		}
	}
	return true;	//모든 튜플에서 유일성 만족
}

int solution(vector<vector<string>> relation) {
	int answer = 0;
	int tupleNum = relation.size();
	int attributeNum = relation.front().size();
	
	vector<int> candidateKey;
	vector<int> ::iterator iter;

	int subsetNum = (1 << attributeNum) -1;	//총 부분집합의 개수 (0000,0001,, ~ 1111)

	for (int subset = 1; subset <= subsetNum; subset++)		//0은 공집합이니 제외
	{
		if (unique(relation, tupleNum, attributeNum, subset))	//유일성 검사
			candidateKey.push_back(subset);

	}

	//비트 1이 많은 순으로 정렬
	sort(candidateKey.begin(), candidateKey.end(), comp);
	
	//최소성 검사
	while (!candidateKey.empty()) {
		int subset = candidateKey.back();
		candidateKey.pop_back();
		answer++;
		
		for (iter = candidateKey.begin(); iter != candidateKey.end();) {
			if ((*iter & subset) == subset)
				iter = candidateKey.erase(iter);	//다음 iterator 
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

