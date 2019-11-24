#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<queue>

using namespace std;

int N,L,R;
int A[50][50];	//���� �α���

struct POSI {
	int y, x;
};

const int dx[4] = { 0,0,-1,+1 };
const int dy[4] = { -1,+1,0,0 };

int main() {

	cin >> N >> L >> R;
	for (int y = 0; y < N; y++)	{
		for (int x = 0; x < N; x++)	{
			cin >> A[y][x];
		}
	}

	int update_count = 0;
	bool is_update = true;

	while (is_update) {

		is_update = false;

		int status[50][50] = { 0, };	//����(�Ǵ� ���ձ�) ��Ÿ���� ���� index
		int index = 0;
		int count[2501] = { 0, };	//index �� �̾��� ���� ��
		int sum[2501] = { 0, };		//index �� �α� �� 
		
		//��� Ž���ϸ� ���ձ� ã�´�.
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				if (status[y][x] == 0) {

					//���ձ� Ž�� ����(���ձ����� ���� index�� ����)
					++index;
					int visited[50][50] = { 0, };		
					queue<POSI> q;
					POSI posi; posi.y = y; posi.x = x;
					q.push(posi);
					visited[y][x] = 1;

					//q ���� ������� ���� ���ձ�!
					while (!q.empty())
					{
						POSI cur = q.front(); q.pop();
						
						status[cur.y][cur.x] = index;
						count[index]++;
						sum[index] += A[cur.y][cur.x];

						//4���� Ž��
						for (int dir = 0; dir < 4; dir++)
						{
							POSI next; next.y = cur.y + dy[dir]; next.x = cur.x + dx[dir];

							if (next.y < 0 || next.y >= N || next.x < 0 || next.x >= N)
								continue;

							int delta = abs(A[cur.y][cur.x] - A[next.y][next.x]); //�α� �� ����

							if (visited[next.y][next.x] == 0 && delta >= L && delta <= R)//����
							{
								visited[next.y][next.x] = 1;
								q.push(next);
							}
						}//end: for 4���� Ž��

					}//end: while (!q.empty())

				}//end: if(status[y][x] == 0)

			}//for��
		}//for��

		//���ձ� Ž�� ����
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				int index = status[y][x];	//���� �Ǵ� ���ձ��� ����
				int avg = sum[index] / count[index];	//���ձ� �ƴϸ� 1�� �������Ƿ� �� �״���ϰ�
				if (A[y][x] != avg)
				{
					A[y][x] = avg;
					is_update = true;
				}
			}
		}

		if (is_update == true)
			update_count++;
		

	}//end:while (is_update) 

	cout << update_count++;


	return 0;
}
