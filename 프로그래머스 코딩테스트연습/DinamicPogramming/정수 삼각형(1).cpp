#include <string>
#include <vector>
#include<iostream>

using namespace std;

/*
삼각형의 정보가 담긴 배열 triangle이 매개변수로 주어질 때, 
꼭대기에서 바닥까지 이어지는 경로 중 거쳐간 숫자의 '최댓값'을 return
*/
int solution(vector<vector<int>> triangle) {
	int answer = 0;

	vector<vector<int>> sum = triangle;

	int tri_size = triangle.size();
	
	for (int i = 1; i < tri_size; i++) {

		int line_size = triangle[i].size();

		for (int j = 0; j < line_size; j++) {
			
			if((j < line_size - 1) &&(sum[i][j] < triangle[i][j] + sum[i - 1][j]))
					sum[i][j] = triangle[i][j] + sum[i - 1][j];

			if((j - 1 >= 0) && (sum[i][j] < triangle[i][j] + sum[i - 1][j - 1]))
					sum[i][j] = triangle[i][j] + sum[i - 1][j - 1];
			
		}
	}
	/*
	for (vector<int> s : sum) {
		for (int i : s) {
			cout << i << " ";
		}
		cout << endl;
	}*/

	for (int i = 0; i < sum[tri_size - 1].size(); ++i) {
		if (answer < sum[tri_size - 1][i])
			answer = sum[tri_size - 1][i];
	}
	
	return answer;
}

int main(void) {

	vector<vector<int>> triangle = {{ 7 }, { 3, 8 }, { 8, 1, 0 }, { 2, 7, 4, 4 }, { 4, 5, 2, 6, 5 }};
	int result = solution(triangle);

	cout << result;

	return 0;
}

