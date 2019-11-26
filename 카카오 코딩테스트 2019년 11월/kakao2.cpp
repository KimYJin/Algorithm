#include<iostream>

#include <string>
#include <vector>
#include<sstream>
#include<map>
#include<algorithm>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
	return a.second > b.second;
}

vector<int> solution(string input) {
	vector<int> answer;
	vector<pair<int, int>> v;
	map<string, int> m;
	
	//'{','}' 제거
	string s;
	for (int i = 0; i < input.size(); i++) {
		if (input[i]!='}' && input[i] != '{') {
			s += input[i];
		}
	}
	//cout << s << endl;;

	//숫자 추출
	string token;
	stringstream ss(s);

	while (getline(ss, token, ',')) {
		//cout << token << '\n';
		m[token]++;
	}

	map<string, int>::iterator iter;

	for (iter = m.begin(); iter != m.end(); iter++)
	{
		//cout << "Key : " << iter->first << " Value : " << iter->second << endl;
		int key = stoi(iter->first);
		int value = iter->second;
		v.push_back(make_pair(key, value));
		//cout << "Key : " << key << " Value : " << value << endl;
	}

	//정렬
	sort(v.begin(), v.end(), comp);
	
	vector <pair<int, int>> ::iterator iter2;

	for (iter2 = v.begin(); iter2 != v.end(); iter2++)
	{
		//cout << "Key : " << iter2->first << " Value : " << iter2->second << endl;
		answer.push_back(iter2->first);
	}
	
	return answer;
}

int main(void) {

	string s = "{{1,2,3},{2,1},{1,2,44,3},{2}}";

	vector<int> answer = solution(s);
	for (int a : answer) {
		cout << a << " ";
	}
	return 0;
}
