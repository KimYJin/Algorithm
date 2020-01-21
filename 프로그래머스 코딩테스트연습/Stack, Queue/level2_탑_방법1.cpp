#include <string>
#include <vector>
#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

/*
2019/12/03 10:05pm ~
*/

vector<int> solution(vector<int> heights) {
	vector<int> answer;
	int n = heights.size();
	
	for (int i = 0; i < n; i++) {
		
		bool check = false;

		for (int j = i - 1; j >= 0; j--) {
			if (heights[i] < heights[j]) {
				answer.push_back(j+1);
				check = true;
				break;
			}
		}
		if (check == false) {
			answer.push_back(0);
		}
	}

	return answer;
}

int main() {

	vector<int> heights = { 6,9,5,7,4 };

	vector<int> answer = solution(heights);

	for (int i : answer)
		cout << i << " ";
}