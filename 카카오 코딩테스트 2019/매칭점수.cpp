#include <string>
#include <vector>
#include<algorithm>
#include<map>
#include<iostream>

using namespace std;

struct Page {
	int index;
	int basicPoint;
	int linkNum;
	double matchingPoint;
};

bool comp(Page a, Page b) {
	if (a.matchingPoint == b.matchingPoint)
		return a.index < b.index;

	return a.matchingPoint > b.matchingPoint;
}

int solution(string word, vector<string> pages) {

	int psize = pages.size();
	int wsize = word.size();

	vector<Page> v;
	map<string, int> pageHash;

	transform(word.begin(), word.end(), word.begin(), ::tolower);	//소문자로 변환

	for (int i = 0; i < psize; i++) {

		string& s = pages[i];
		transform(s.begin(), s.end(), s.begin(), ::tolower);	//소문자로 변환

		int mid = 0, posl = 0, posr;

		// 1. <meta> tag를 찾아서 url 찾기

		while (mid <= posl) {	// <meta>여러개이므로 검사.

			posl = s.find("<meta", posl + 1); //해당 문자열을 찾은 이후에도 이어서 반복적으로 찾기 위해 +1
			posr = s.find(">", posl);
			mid = s.rfind("https://", posr);
		}
		posr = s.find("\"", mid); //url끝 위치 "로 끝남

		string url = s.substr(mid, posr - mid);

		// 2. <body> tag 에서 word 찾기
		posl = s.find("<body>", posr);

		int basicPoint = 0;

		for (int start = posl; ;) {
			start = s.find(word, start + 1);	//단어를 찾은 이후에도 이어서 반복적으로 찾기 위해 +1
			if (start == string::npos)break;	//못찾으면 npos(문자열의 끝)을 반환함. 그럴 경우 for문 중단. 
		
			if (!isalpha(s[start - 1]) && !isalpha(s[start + wsize]))	//검색어 앞뒤로 문자가 없어야함.
			{
				++basicPoint;
			}
		}

		//3.외부 링크수
		int linkNum = 0;
		for (int start = posl; ;) {

			start = s.find("<a href", start + 1);

			if (start == string::npos)break;

			++linkNum;
		}
		//cout << "url:" << url << endl << "basicPoint:" << basicPoint << endl << "linkNum:" << linkNum << endl;
	
		v.push_back({i, basicPoint, linkNum, (double)basicPoint}); //링크점수,매칭점수는 모든 page의 basicPoint,linkNum 구해야 알 수 있음.
		pageHash[url] = i;
	}

	//4.링크 점수 & 매칭 점수
	for (int i = 0; i < psize; i++) {
		
		string &s = pages[i];

		for (int posl = 0, posr=0;;) {
			
			posl = s.find("<a href",posr);
			
			if (posl == string::npos)break;

			posl = s.find("https://", posl);
			posr = s.find("\"", posl);
			
			string linkUrl = s.substr(posl, posr - posl);
			map<string, int> ::iterator it = pageHash.find(linkUrl);
			
			if (it != pageHash.end()) {
				v[it->second].matchingPoint += ((double)v[i].basicPoint / (double)v[i].linkNum); 
				//cout << it->second << "은 " << i << "-- 로부터 " << ((double)v[i].basicPoint / (double)v[i].linkNum) << endl << endl;
			}
		}
	}
	
	sort(v.begin(), v.end(), comp);	//정렬..

	return v.begin()->index;
}

int main() {

	string word = "blind";
	vector<string> pages = { "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://a.com\"/>\n</head>  \n<body>\nBlind Lorem Blind ipsum dolor Blind test sit amet, consectetur adipiscing elit. \n<a href=\"https://b.com\"> Link to b </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://b.com\"/>\n</head>  \n<body>\nSuspendisse potenti. Vivamus venenatis tellus non turpis bibendum, \n<a href=\"https://a.com\"> Link to a </a>\nblind sed congue urna varius. Suspendisse feugiat nisl ligula, quis malesuada felis hendrerit ut.\n<a href=\"https://c.com\"> Link to c </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://c.com\"/>\n</head>  \n<body>\nUt condimentum urna at felis sodales rutrum. Sed dapibus cursus diam, non interdum nulla tempor nec. Phasellus rutrum enim at orci consectetu blind\n<a href=\"https://a.com\"> Link to a </a>\n</body>\n</html>" };

	int answer = solution(word, pages);
	cout << answer;

	return 0;
}