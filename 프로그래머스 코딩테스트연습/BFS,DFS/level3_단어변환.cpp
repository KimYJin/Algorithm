#include <string>
#include <vector>
#include<iostream>
#include<queue>

using namespace std;

bool check[50] = { false };	//�� �߰��ؼ� ���ʿ��� �ð� ���̱�

/*
begin�� target���� ��ȯ�ϴ� �ּ� �ܰ踦 return 
1. �� ���� �� ���� ���ĺ��� �ٲ� �� �ֽ��ϴ�.
2. words�� �ִ� �ܾ�θ� ��ȯ�� �� �ֽ��ϴ�.
*/
int solution(string begin, string target, vector<string> words) {

	int answer = 0;
	int len = begin.size();
	
	queue<pair<string,int>> q;
	q.push(make_pair(begin,0));

	while (!q.empty()) {
		string cur_s = q.front().first;
		int cur_i = q.front().second;

		q.pop();

		if (target == cur_s) {
			answer = cur_i;
			break;
		}
		
		//�� ���ĺ��� �ٸ� ��� ��ȯ
		for (int w = 0; w<words.size(); ++w) {
			string word = words[w];
			int dif = 0;
			for (int i = 0; i < len; i++) {
				if (check[w] != true) {
					if (word[i] != cur_s[i]) {
						dif++;
					}
				}
			}
			if (dif == 1) {
				check[w] = true;	
				q.push(make_pair(word, cur_i + 1));
				cout << word << " " << cur_i + 1 << endl;
			}
		}
	}

	return answer;
}

int main() {
	string begin = "hit", target = "cog";
	vector<string> words={ "hot", "dot", "dog", "lot", "log", "cog" };
	int answer = solution(begin,target,words);
	cout << answer;
}