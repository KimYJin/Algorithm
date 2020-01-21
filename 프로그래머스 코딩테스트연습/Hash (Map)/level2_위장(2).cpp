#include<iostream>

#include <string>
#include <vector>
#include<unordered_map>

using namespace std;

//���� �ٸ� ���� ������ �� ���ϱ�
int solution(vector<vector<string>> clothes) {

	unordered_map<string, vector<string>> m;	//key: �ǻ�����, value: �ǻ� ����Ʈ

	for (vector<string> c : clothes) {
		m[c[1]].push_back(c[0]);	//�ǻ����� ���� �ǻ� �з�
	}

	int answer = 1;

	for (unordered_map<string, vector<string>>::iterator it = m.begin(); it != m.end(); ++it) {
		answer *= it->second.size() + 1; //(���� �ʴ� ��� �����ϱ� ���� +1)
	}

	return answer -1 ;	//�ƹ��͵� ���� �ʴ� ��� ����
}

int main(void) {

	vector<vector<string>> clothes = { { "yellow_hat", "headgear" },{ "blue_sunglasses", "eyewear" },{ "green_turban", "headgear" } };

	int answer = solution(clothes);
	cout << answer;

	return 0;
}