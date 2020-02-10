/*
ĳ�� ���潺 https://www.acmicpc.net/problem/17135
�ü� 3���� �Ÿ��� D������ �� �߿��� ���� ����� �� ����. �����̸� ���� ���ʿ� �ִ� ���� ����
������ ������, ���� �Ʒ��� �� ĭ �̵�.
�ü��� �������� ������ �� �ִ� ���� �ִ� ���� ���
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

	int num = 0;	//���� ���� ��
	cur_R = R;

	while(1) {

		bool isExist = false;	//���� ���� ����

		//�ü��� �ܴ��� ���� ��ġ,�Ÿ�
		vector<pair<int, int>> target_pos(3);
		vector<int> target_distance(3,100);

		//(1) ������ �� ã��
		for (int r = cur_R - 1; r >= 0; r--) {
			for (int c = 0; c < C; c++) {
				if (copy_map[r][c] == 1) {
					isExist = true;

					//3���� �ü��� ���� �Ÿ� ���
					for (int i = 0; i < 3; i++) {

						//��: map[i][j], �ü�: map[R][pos[p]]
						int dis = abs(cur_R - r) + abs(pos[i] - c);

						if (dis <= D) {
							if ((dis < target_distance[i]) || (dis == target_distance[i] && c < target_pos[i].second))
							{
								target_pos[i].first = r;	//�ü��� Ÿ�� ���� ������Ʈ
								target_pos[i].second = c;
								target_distance[i] = dis;
							}
						}
					}
				}
			}
		}

		if (!isExist)	//�� ������ ����
		{
			if (result < num) {
				result = num;
				//cout << "**���μ�: " << num << " �ִ밪: " << result << endl;
			}
			break;
		}

		//(2) ����
		for (int i = 0; i < 3; i++) {
			if (target_distance[i] < 100) {	//�ܴ��� ���� ��ġ������ �ְ�,
				int r = target_pos[i].first, c = target_pos[i].second;

				if (copy_map[r][c] == 1) {	//���� �ٸ� �ü��� ������ �ʾҴٸ� -> ����.
					copy_map[r][c] = 0;
					num++;
				}
			}
		}
		
		for (int i = 0; i < 3; i++) {
			//cout << "*�ü� ����: " << target_pos[i].first <<","<< target_pos[i].second << " (�Ÿ�:" << target_distance[i] << ")" << endl;
		}

		//(3) ���� ������ ����
		cur_R--;
		//cout << "*����!" << endl;
		//test();

	} //end while

}

//�ü� ��ġ ���ϱ�
void locate(int cnt) {

	if (cnt == 3) {
		copyMap();
		/*
		cout << "----����-----" << endl;
		for (int i = 0; i < cur_R; i++) {
			for (int j = 0; j < C; j++) {
				cout << copy_map[i][j] << " ";
			}
			cout << endl;
		}

		cout << endl << "�ü���ġ: " << pos[0] << pos[1] << pos[2] << endl;
		*/
		simulate(); //���� �ùķ���Ʈ
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

	locate(0);	//�ü� ��ġ ���ϱ�

	cout << result;

	return 0;
}