
#include<iostream>

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <utility>

using namespace std;
bool compare(pair<int, int> left, pair<int, int> right) {
	if (left.first > right.first) {
		return true;
	}
	else if (left.first == right.first) {
		if (left.second < right.second) {
			return true;
		}
	}
	return false;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	unordered_map<string, int> summap;
	unordered_map<string, vector<pair<int, int>>> genmap;
	for (int i = 0; i < genres.size(); i++) {
		summap[genres[i]] += plays[i];
		genmap[genres[i]].push_back(make_pair(plays[i], i));
	}
	vector<pair<int, string>> fororder;
	for (auto x : summap) {
		fororder.push_back(make_pair(x.second, x.first));
	}
	sort(fororder.begin(), fororder.end());
	while (fororder.size() > 0) {
		pair<int, string> temp = fororder.back();
		fororder.pop_back();
		vector<pair<int, int>> a = genmap[temp.second];
		sort(a.begin(), a.end(), compare);
		int lastn = 2;
		if (a.size() < 2) {
			lastn = a.size();
		}
		for (int i = 0; i < lastn; i++) {
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