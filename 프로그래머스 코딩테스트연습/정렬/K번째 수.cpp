#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {

	int N = commands.size();

	vector<int> answer;

	for(int c=0; c < N; c++){
		vector<int> command = commands[c];
		vector<int> temp;

		int i = command[0]; 
		int j = command[1];
		int k = command[2];

		for (vector<int>::iterator it = array.begin()+i-1; it != array.begin()+j; ++it) {
			temp.push_back(*it);
		}

		sort(temp.begin(), temp.end());
		
		answer.push_back(temp[k-1]);
		cout << temp[k - 1] << endl;
	}

	return answer;
}

int main() {

	vector<int> array = { 1, 5, 2, 6, 3, 7, 4 };
	vector<vector<int>> commands = { {2,5,3},{4,4,1},{1,7,3} };

	solution(array, commands);

	return 0;
}
