#include<iostream>

#include <string>
#include <vector>
#include<unordered_map>

using namespace std;

//비트마스크로 풀었는데 시간초과난 풀이. 
//서로 다른 옷의 조합의 수 구하기
int solution(vector<vector<string>> clothes) {
	
	unordered_map<string, vector<string>> m;	//key: 의상종류, value: 의상 명 리스트

	for (vector<string> c : clothes) {
		m[c[1]].push_back(c[0]);	//의상종류 별로 의상 분류
	}


	//벡터로 변환
	vector <vector<string>> v;
	for (unordered_map<string, vector<string>>::iterator it = m.begin(); it != m.end(); ++it)
	{
		v.push_back(it->second);
	}

	int kindNum = v.size();	//의상종류 수
	int kindCom = (1 << kindNum) - 1; //비트로 의상종류 조합 구하기 ex. 1<<2 -1 = [100] -1 = [11]
	int answer = 0;

	for (int k = 1; k <= kindCom; k++)	//진부분집합(하루에 최소 1개 의상 입으므로 공집합 제외) ex.01,10,11
	{
		int temp = 1;
		for (int i = 0; i < kindNum; i++) {	
			
			if ((k & 1 << i) == 0) continue;	//입은 의상 ex. 01,10 

			temp *= v[i].size();	//ex. 11이라면 옷종류 01,10 별 의상 수 곱
		}
	
		answer += temp;
	}
	
	return answer;
}

int main(void) {

	vector<vector<string>> clothes = { {"yellow_hat", "headgear"},{"blue_sunglasses", "eyewear"},{"green_turban", "headgear"} };

	int answer = solution(clothes);
	cout << answer;

	return 0;
}