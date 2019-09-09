#include <string>
#include <vector>
#include<unordered_map>
#include <algorithm>
#include <utility>

using namespace std;

//���Ƚ�� ��������, Ƚ������ �� ���ǹ�ȣ ��������
bool compare(pair<int, int> left, pair<int, int> right) {
	if (left.first == right.first) {
		return left.second < right.second;
	}

	return left.first > right.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {

	vector<int> answer;

	unordered_map<string, int> summap;	// key: �帣, value: �帣 �� ���Ƚ�� �� ��
	unordered_map<string, vector<pair<int, int>>> genmap;	// key: �帣, vlaue: ����<���� ��ȣ, ���� ���Ƚ��> 

	for (int i = 0; i < genres.size(); i++) {
		summap[genres[i]] += plays[i];
		genmap[genres[i]].push_back(make_pair(plays[i], i));	//�帣 �� ����<���� ��ȣ, ���� ���Ƚ��>�� �߰�
	}

	// map�� vector�� ��ȯ (���� ����) �� ����
	vector<pair<int, string>> fororder;
	for (auto x : summap) {
		fororder.push_back(make_pair(x.second, x.first));	//x.second = �帣�� ���Ƚ�� ����, x.first �帣
	}
	sort(fororder.begin(), fororder.end()); // �帣 �� ���� ��� Ƚ�� �������� ����

	//�帣 �� �ִ� ��� ���� 2� ����
	while (fororder.size() > 0) {

		pair<int, string> temp = fororder.back(); //���� ��� �� ���� ���� �帣
		fororder.pop_back();

		vector<pair<int, int>> a = genmap[temp.second];	//�帣 �� ���� <���ǹ�ȣ, �������Ƚ��>
		sort(a.begin(), a.end(), compare);

		for (int i = 0; i < a.size(); i++) {

			if (i == 2)break;//(1�� �̻��̹Ƿ� 2�� �ƴ� 1���� ���� �ִٴ� �� ����)

			answer.push_back(a[i].second);
		}
	}

	return answer;
}

int main(void) {

	vector<string> genres = { "classic", "pop", "classic", "classic", "pop" };
	vector<int> plays = { 500, 600, 150, 800, 2500 };

	vector<int> answer = solution(genres, plays);

	for (int n : answer) {
		cout << n << endl;
	}

	return 0;
}