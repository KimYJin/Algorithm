/*
스티커는 상하좌우로 모두 연결, 불필요한 행/열 X. 
먼저 받았던 스티커부터 차례대로 붙임.

다른 스티커와 겹치거나 노트북을 벗어나지 않는 
최상단(여러곳 있으면 최좌측부터) 붙인다.

붙일 곳이 없다면 스티커를 시계 방향으로 90도 회전한다.
0도, 90도, 180도, 270도 회전시켜 봤음에도 붙이지 못하면 버린다.

노트북에서 몇 개의 칸이 채워졌는지 구해보자.
*/

#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

struct sticker {
	int r, c;
};

const int LAB_MAX = 41;
const int STICKER_MAX = 101;

int lab_row = 0, lab_col = 0;
int monun_num = 0, monun_row = 0, monun_col = 0;
int labtop[LAB_MAX][LAB_MAX] = { 0, };
int monun_map[STICKER_MAX][STICKER_MAX] = { 0, };
int copy_map[STICKER_MAX][STICKER_MAX] = { 0, };
int sticker_cnt = 0;
int total_cnt = 0;
vector<sticker> sticker_info;

void print_laptop() {
	for (int r = 0; r < lab_row; r++) {
		for (int c = 0; c < lab_col; c++) {
			cout << labtop[r][c] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void print_sticker() {
	for (int r = 0; r < monun_row; r++) {
		for (int c = 0; c < monun_col; c++) {

			cout << monun_map[r][c] << " ";	//회전을 위해 모눈종이 정보 저장
		}
		cout << endl;
	}
	cout << endl;
}


//회전
void rotate() {

	sticker_info.clear();

	for (int r = 0; r < monun_row; r++) {
		for (int c = 0; c < monun_col; c++) {
			copy_map[r][c] = monun_map[r][c];
		}
	}

	int temp = monun_row;
	monun_row = monun_col;
	monun_col = temp;
	
	for (int r = 0; r < monun_row; r++) {
		for (int c = 0; c < monun_col; c++) {
			monun_map[r][c] = copy_map[monun_col-c-1][r];

			if (monun_map[r][c] == 1) {
				sticker curs = { r,c };
				sticker_info.push_back(curs);	//위치 찾기 위해 스티커정보만 저장
			}
		}
	}

}

//최상단에 붙일 곳 찾기
bool locate() {

	int nr=0, nc=0;

	for (int r = 0; r < lab_row; r++) {
		for (int c = 0; c < lab_col; c++) {

			int cnt = 0;

			for (int s = 0; s < sticker_info.size(); s++) {
				nr = r + sticker_info[s].r;
				nc = c + sticker_info[s].c;

				//범위 벗어나거나 다른 스티커와 겹치는지 검사
				if (labtop[nr][nc] == 1 || nr < 0 || nr > lab_row - 1 || nc < 0 || nc > lab_col - 1)
					break;
				
				cnt++;
			}
			
			//스티커 붙이기
			if (cnt == sticker_cnt) {
				
				for (int k = 0; k < sticker_info.size(); k++) {
					nr = r + sticker_info[k].r;
					nc = c + sticker_info[k].c;

					labtop[nr][nc] = 1;
				}
				total_cnt += sticker_cnt;

				return true;
			}
		}
	}

	return false;
}


int main(void) {

	cin >> lab_row >> lab_col >> monun_num;

	//각 스티커 정보 입력받기
	for (int s = 0; s < monun_num; s++) {
		
		cin >> monun_row >> monun_col;

		sticker_info.clear();
		sticker_cnt = 0;

		for (int r = 0; r < monun_row; r++) {
			for (int c = 0; c < monun_col; c++) {
				
				cin >> monun_map[r][c];	//회전을 위해 모눈종이 정보 저장

				if (monun_map[r][c] == 1) {
					sticker curs = { r,c };
					sticker_info.push_back(curs);	//위치 찾기 위해 스티커정보만 저장
					sticker_cnt++;	//스티커 칸의 수
				}
			}
		}

		//위치 찾으면 붙이고, 못찾으면 회전하기 반복
		for (int i = 0; i < 4; i++) {
			if (locate() || i==3) //붙이거나 버리기
				break;
			else {
				rotate();
			}
		}

	}
	
	cout << total_cnt;

	return 0;
}
