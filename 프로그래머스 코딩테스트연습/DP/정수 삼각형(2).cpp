
#include <string>
#include <vector>
#include<iostream>
#include<algorithm>

using namespace std;

/*
삼각형의 정보가 담긴 배열 triangle이 매개변수로 주어질 때, 
꼭대기에서 바닥까지 이어지는 경로 중 거쳐간 숫자의 '최댓값'을 return
*/
int solution(vector<vector<int>> triangle) {

	int answer = 0;
	int tri_size = triangle.size();
	
	for (int i = 1; i < tri_size; i++) {

		int line_size = triangle[i].size();

		for (int j = 0; j < line_size; j++) {
			
			if (j == 0) {	//맨 좌측 노드
				triangle[i][j] += triangle[i - 1][j];
			}
			else if (j == i) {	//맨 우측 노드
				triangle[i][j] += triangle[i - 1][j - 1];
			}
			else {
				triangle[i][j] += max(triangle[i - 1][j], triangle[i - 1][j - 1]);
			}
		}
	}

	answer = *max_element(triangle[tri_size - 1].begin(), triangle[tri_size - 1].end());
	
	return answer;
}

int main(void) {

	vector<vector<int>> triangle = {{ 7 }, { 3, 8 }, { 8, 1, 0 }, { 2, 7, 4, 4 }, { 4, 5, 2, 6, 5 }};
	int result = solution(triangle);

	cout << result;
	return 0;
}