/*
100x100 �����ǿ��� ����, ���� ���� �� ���� �� ȸ���� ���� ���ϱ�
�� ĭ�� ���� ���ڴ� c��� char type���� �־����� 'A', 'B', 'C' �� �ϳ�
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>

using namespace std;

const int MAX = 100;
char m[MAX + 1][MAX + 1] = { 0, };

int main(void) {
	
	ifstream ifile("input (3).txt");

	if (!ifile) {
		cout << "can't open file" << endl;
		return 1;
	}
	

	for (int t = 1; t <= 10; t++) {

		int testcase = 0;
		int answer = 1;

		//cin >> T;
		ifile >> testcase;

		for (int i = 0; i < 100; i++) {
			//cin >> m[i];
			ifile >> m[i];
		}

		for (int len = MAX; len >= 1; len--) {	//ȸ�� ���� (len) �� �ͺ��� ã��

			if (answer > 1)	//����,���� �� ���̰� len�� ȸ�� ã���� Ž�� ����
				break;

			//(1) ���� Ž��
			for (int r = 0; r < MAX; r++) {
				for (int c = 0; c < MAX - len + 1; c++) {	//(r,c):len ������ ���ڿ� ������ 

					bool correct = true;

					for (int k = 0; k < len / 2; k++) {		// 0���� len�� ���ݸ�ŭ �ݺ�
						if (m[r][c + k] != m[r][c + len - k - 1]) {	//��Ī ��ġ�� ���� ������ ���� ��
							correct = false;	//�ٸ��� ȸ���� �ƴ�
							break;
						}
					}

					if (correct) //ȸ���� ã�� ���
						answer = len;
				}
			}

			//(2) ���� Ž��
			for (int r = 0; r < MAX; r++) {
				for (int c = 0; c < MAX - len + 1; c++) {	//(r,c):len ������ ���ڿ� ������ 

					bool correct = true;

					for (int k = 0; k < len / 2; k++) {		// 0���� len�� ���ݸ�ŭ �ݺ�
						if (m[r + k][c] != m[r + len - k - 1][c]) {	//��Ī ��ġ�� ���� ������ ���� ��
							correct = false;	//�ٸ��� ȸ���� �ƴ�
							break;
						}
					}

					if (correct) //ȸ���� ã�� ���
						answer = len;
				}
			}
		}
		cout << "#" << testcase << " " << answer << endl;
	}

	return 0;
}