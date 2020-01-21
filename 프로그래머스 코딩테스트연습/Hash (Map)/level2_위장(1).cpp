#include<iostream>

#include <string>
#include <vector>
#include<unordered_map>

using namespace std;

//��Ʈ����ũ�� Ǯ���µ� �ð��ʰ��� Ǯ��. 
//���� �ٸ� ���� ������ �� ���ϱ�
int solution(vector<vector<string>> clothes) {
	
	unordered_map<string, vector<string>> m;	//key: �ǻ�����, value: �ǻ� �� ����Ʈ

	for (vector<string> c : clothes) {
		m[c[1]].push_back(c[0]);	//�ǻ����� ���� �ǻ� �з�
	}


	//���ͷ� ��ȯ
	vector <vector<string>> v;
	for (unordered_map<string, vector<string>>::iterator it = m.begin(); it != m.end(); ++it)
	{
		v.push_back(it->second);
	}

	int kindNum = v.size();	//�ǻ����� ��
	int kindCom = (1 << kindNum) - 1; //��Ʈ�� �ǻ����� ���� ���ϱ� ex. 1<<2 -1 = [100] -1 = [11]
	int answer = 0;

	for (int k = 1; k <= kindCom; k++)	//���κ�����(�Ϸ翡 �ּ� 1�� �ǻ� �����Ƿ� ������ ����) ex.01,10,11
	{
		int temp = 1;
		for (int i = 0; i < kindNum; i++) {	
			
			if ((k & 1 << i) == 0) continue;	//���� �ǻ� ex. 01,10 

			temp *= v[i].size();	//ex. 11�̶�� ������ 01,10 �� �ǻ� �� ��
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