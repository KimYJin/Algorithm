/*
��ƼĿ�� �����¿�� ��� ����, ���ʿ��� ��/�� X. 
���� �޾Ҵ� ��ƼĿ���� ���ʴ�� ����.

�ٸ� ��ƼĿ�� ��ġ�ų� ��Ʈ���� ����� �ʴ� 
�ֻ��(������ ������ ����������) ���δ�.

���� ���� ���ٸ� ��ƼĿ�� �ð� �������� 90�� ȸ���Ѵ�.
0��, 90��, 180��, 270�� ȸ������ �������� ������ ���ϸ� ������.

��Ʈ�Ͽ��� �� ���� ĭ�� ä�������� ���غ���.
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

			cout << monun_map[r][c] << " ";	//ȸ���� ���� ������ ���� ����
		}
		cout << endl;
	}
	cout << endl;
}


//ȸ��
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
				sticker_info.push_back(curs);	//��ġ ã�� ���� ��ƼĿ������ ����
			}
		}
	}

}

//�ֻ�ܿ� ���� �� ã��
bool locate() {

	int nr=0, nc=0;

	for (int r = 0; r < lab_row; r++) {
		for (int c = 0; c < lab_col; c++) {

			int cnt = 0;

			for (int s = 0; s < sticker_info.size(); s++) {
				nr = r + sticker_info[s].r;
				nc = c + sticker_info[s].c;

				//���� ����ų� �ٸ� ��ƼĿ�� ��ġ���� �˻�
				if (labtop[nr][nc] == 1 || nr < 0 || nr > lab_row - 1 || nc < 0 || nc > lab_col - 1)
					break;
				
				cnt++;
			}
			
			//��ƼĿ ���̱�
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

	//�� ��ƼĿ ���� �Է¹ޱ�
	for (int s = 0; s < monun_num; s++) {
		
		cin >> monun_row >> monun_col;

		sticker_info.clear();
		sticker_cnt = 0;

		for (int r = 0; r < monun_row; r++) {
			for (int c = 0; c < monun_col; c++) {
				
				cin >> monun_map[r][c];	//ȸ���� ���� ������ ���� ����

				if (monun_map[r][c] == 1) {
					sticker curs = { r,c };
					sticker_info.push_back(curs);	//��ġ ã�� ���� ��ƼĿ������ ����
					sticker_cnt++;	//��ƼĿ ĭ�� ��
				}
			}
		}

		//��ġ ã���� ���̰�, ��ã���� ȸ���ϱ� �ݺ�
		for (int i = 0; i < 4; i++) {
			if (locate() || i==3) //���̰ų� ������
				break;
			else {
				rotate();
			}
		}

	}
	
	cout << total_cnt;

	return 0;
}
