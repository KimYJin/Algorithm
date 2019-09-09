#include<iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> rotate(vector<vector<int>> key,int K) {
	vector<vector<int>> rotate_key(K, vector<int>(K, 0));

	for (int i = 0; i < K; i++) {
		for (int j = 0; j < K; j++) {
			rotate_key[j][K-1 - i] = key[i][j];
		}
	}

	for (int i = 0; i < K; i++) {
		for (int j = 0; j < K; j++) {
			cout << rotate_key[i][j];
		}
		cout << endl;
	}
	cout << "****" << endl;
	return rotate_key;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	int K = key.size();
	
	for (int i = 0; i < 4; i++) //90µµ È¸Àü
	{
		key = rotate(key, K);


	}

	bool answer = true;
	return answer;
}

int main(void) {

	vector<vector<int>> key = { {0, 0,0},{1, 0, 0},{0, 1, 1} };
	vector<vector<int>> lock = {{ 1, 1, 1 }, { 1, 1, 0 }, { 1, 0, 1} };
	bool result  = solution(key, lock);

	cout << result;

	return 0;
}