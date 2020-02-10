/*
캐슬 디펜스 https://www.acmicpc.net/problem/17135
궁수 3명이 거리가 D이하인 적 중에서 가장 가까운 적 공격. 여럿이면 가장 왼쪽에 있는 적을 공격
공격이 끝나면, 적이 아래로 한 칸 이동.
궁수의 공격으로 제거할 수 있는 적의 최대 수를 계산
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 20;
int R = 0, C = 0, D = 0;
int map[MAX][MAX] = { 0, };
int copy_map[MAX][MAX] = { 0, };
int check[MAX] = { 0, };

vector<int> pos;
int result = 0;
int cur_R = 0;

void test() {

	for (int i = 0; i < cur_R; i++) {
		for (int j = 0; j < C; j++) {
			cout<< copy_map[i][j]<<" ";
		}
		cout << endl;
	}
	cout << endl;
}

void copyMap() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			copy_map[i][j] = map[i][j];
		}
	}
}

void simulate() {

	int num = 0;	//죽인 적의 수
	cur_R = R;

	while(1) {

		bool isExist = false;	//적의 존재 여부

		//궁수가 겨누는 적의 위치,거리
		vector<pair<int, int>> target_pos(3);
		vector<int> target_distance(3,100);

		//(1) 공격할 적 찾기
		for (int r = cur_R - 1; r >= 0; r--) {
			for (int c = 0; c < C; c++) {
				if (copy_map[r][c] == 1) {
					isExist = true;

					//3명의 궁수와 적의 거리 계산
					for (int i = 0; i < 3; i++) {

						//적: map[i][j], 궁수: map[R][pos[p]]
						int dis = abs(cur_R - r) + abs(pos[i] - c);

						if (dis <= D) {
							if ((dis < target_distance[i]) || (dis == target_distance[i] && c < target_pos[i].second))
							{
								target_pos[i].first = r;	//궁수의 타겟 정보 업데이트
								target_pos[i].second = c;
								target_distance[i] = dis;
							}
						}
					}
				}
			}
		}

		if (!isExist)	//적 없으면 종료
		{
			if (result < num) {
				result = num;
				//cout << "**죽인수: " << num << " 최대값: " << result << endl;
			}
			break;
		}

		//(2) 공격
		for (int i = 0; i < 3; i++) {
			if (target_distance[i] < 100) {	//겨누는 적의 위치정보가 있고,
				int r = target_pos[i].first, c = target_pos[i].second;

				if (copy_map[r][c] == 1) {	//적을 다른 궁수가 죽이지 않았다면 -> 제거.
					copy_map[r][c] = 0;
					num++;
				}
			}
		}
		
		for (int i = 0; i < 3; i++) {
			//cout << "*궁수 공격: " << target_pos[i].first <<","<< target_pos[i].second << " (거리:" << target_distance[i] << ")" << endl;
		}

		//(3) 적이 성으로 전진
		cur_R--;
		//cout << "*전진!" << endl;
		//test();

	} //end while

}

//궁수 위치 정하기
void locate(int cnt) {

	if (cnt == 3) {
		copyMap();
		/*
		cout << "----시작-----" << endl;
		for (int i = 0; i < cur_R; i++) {
			for (int j = 0; j < C; j++) {
				cout << copy_map[i][j] << " ";
			}
			cout << endl;
		}

		cout << endl << "궁수위치: " << pos[0] << pos[1] << pos[2] << endl;
		*/
		simulate(); //게임 시뮬레이트
		return;
	}
	
	for (int i = 0; i < C; i++) {
		if (!check[i]) {

			check[i] = true;
			pos.push_back(i);
			
			locate(cnt + 1);

			check[i] = false;
			pos.pop_back();
		}
	}

}

int main(void) {

	cin >> R >> C >> D;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
		}
	}

	locate(0);	//궁수 위치 정하기

	cout << result;

	return 0;
}