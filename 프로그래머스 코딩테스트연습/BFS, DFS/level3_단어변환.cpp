#include <string>
#include <vector>
#include<iostream>
#include<queue>

using namespace std;

bool check[50] = { false };	//꼭 추가해서 불필요한 시간 줄이기

/*
begin을 target으로 변환하는 최소 단계를 return 
1. 한 번에 한 개의 알파벳만 바꿀 수 있습니다.
2. words에 있는 단어로만 변환할 수 있습니다.
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
		
		//한 알파벳만 다른 경우 변환
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