#include <string>
#include <vector>
#include<unordered_map>
#include <algorithm>
#include <utility>

using namespace std;

//재생횟수 내림차순, 횟수같을 땐 음악번호 오름차순
bool compare(pair<int, int> left, pair<int, int> right) {
	if (left.first == right.first) {
		return left.second < right.second;
	}

	return left.first > right.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {

	vector<int> answer;

	unordered_map<string, int> summap;	// key: 장르, value: 장르 별 재생횟수 총 합
	unordered_map<string, vector<pair<int, int>>> genmap;	// key: 장르, vlaue: 벡터<음악 번호, 음악 재생횟수> 

	for (int i = 0; i < genres.size(); i++) {
		summap[genres[i]] += plays[i];
		genmap[genres[i]].push_back(make_pair(plays[i], i));	//장르 별 벡터<음악 번호, 음악 재생횟수>에 추가
	}

	// map을 vector로 변환 (정렬 위해) 후 정렬
	vector<pair<int, string>> fororder;
	for (auto x : summap) {
		fororder.push_back(make_pair(x.second, x.first));	//x.second = 장르별 재생횟수 총합, x.first 장르
	}
	sort(fororder.begin(), fororder.end()); // 장르 별 음악 재생 횟수 오름차순 정렬

	//장르 별 최대 재생 음악 2곡씩 추출
	while (fororder.size() > 0) {

		pair<int, string> temp = fororder.back(); //음악 재생 수 가장 많은 장르
		fororder.pop_back();

		vector<pair<int, int>> a = genmap[temp.second];	//장르 별 벡터 <음악번호, 음악재생횟수>
		sort(a.begin(), a.end(), compare);

		for (int i = 0; i < a.size(); i++) {

			if (i == 2)break;//(1곡 이상이므로 2곡 아닌 1곡일 수도 있다는 점 주의)

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