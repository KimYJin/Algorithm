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

	transform(word.begin(), word.end(), word.begin(), ::tolower);	//�ҹ��ڷ� ��ȯ

	for (int i = 0; i < psize; i++) {

		string& s = pages[i];
		transform(s.begin(), s.end(), s.begin(), ::tolower);	//�ҹ��ڷ� ��ȯ

		int mid = 0, posl = 0, posr;

		// 1. <meta> tag�� ã�Ƽ� url ã��

		while (mid <= posl) {	// <meta>�������̹Ƿ� �˻�.

			posl = s.find("<meta", posl + 1); //�ش� ���ڿ��� ã�� ���Ŀ��� �̾ �ݺ������� ã�� ���� +1
			posr = s.find(">", posl);
			mid = s.rfind("https://", posr);
		}
		posr = s.find("\"", mid); //url�� ��ġ "�� ����

		string url = s.substr(mid, posr - mid);

		// 2. <body> tag ���� word ã��
		posl = s.find("<body>", posr);

		int basicPoint = 0;

		for (int start = posl; ;) {
			start = s.find(word, start + 1);	//�ܾ ã�� ���Ŀ��� �̾ �ݺ������� ã�� ���� +1
			if (start == string::npos)break;	//��ã���� npos(���ڿ��� ��)�� ��ȯ��. �׷� ��� for�� �ߴ�. 
		
			if (!isalpha(s[start - 1]) && !isalpha(s[start + wsize]))	//�˻��� �յڷ� ���ڰ� �������.
			{
				++basicPoint;
			}
		}

		//3.�ܺ� ��ũ��
		int linkNum = 0;
		for (int start = posl; ;) {

			start = s.find("<a href", start + 1);

			if (start == string::npos)break;

			++linkNum;
		}
		//cout << "url:" << url << endl << "basicPoint:" << basicPoint << endl << "linkNum:" << linkNum << endl;
	
		v.push_back({i, basicPoint, linkNum, (double)basicPoint}); //��ũ����,��Ī������ ��� page�� basicPoint,linkNum ���ؾ� �� �� ����.
		pageHash[url] = i;
	}

	//4.��ũ ���� & ��Ī ����
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
				//cout << it->second << "�� " << i << "-- �κ��� " << ((double)v[i].basicPoint / (double)v[i].linkNum) << endl << endl;
			}
		}
	}
	
	sort(v.begin(), v.end(), comp);	//����..

	return v.begin()->index;
}

int main() {

	string word = "blind";
	vector<string> pages = { "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://a.com\"/>\n</head>  \n<body>\nBlind Lorem Blind ipsum dolor Blind test sit amet, consectetur adipiscing elit. \n<a href=\"https://b.com\"> Link to b </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://b.com\"/>\n</head>  \n<body>\nSuspendisse potenti. Vivamus venenatis tellus non turpis bibendum, \n<a href=\"https://a.com\"> Link to a </a>\nblind sed congue urna varius. Suspendisse feugiat nisl ligula, quis malesuada felis hendrerit ut.\n<a href=\"https://c.com\"> Link to c </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://c.com\"/>\n</head>  \n<body>\nUt condimentum urna at felis sodales rutrum. Sed dapibus cursus diam, non interdum nulla tempor nec. Phasellus rutrum enim at orci consectetu blind\n<a href=\"https://a.com\"> Link to a </a>\n</body>\n</html>" };

	int answer = solution(word, pages);
	cout << answer;

	return 0;
}