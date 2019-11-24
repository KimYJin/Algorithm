#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<queue>

using namespace std;

int N,L,R;
int A[50][50];	//나라별 인구수

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

		int status[50][50] = { 0, };	//나라(또는 연합국) 나타내는 고유 index
		int index = 0;
		int count[2501] = { 0, };	//index 별 이어진 나라 수
		int sum[2501] = { 0, };		//index 별 인구 수 
		
		//모두 탐색하며 연합국 찾는다.
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				if (status[y][x] == 0) {

					//연합국 탐색 시작(연합국임을 고유 index로 구분)
					++index;
					int visited[50][50] = { 0, };		
					queue<POSI> q;
					POSI posi; posi.y = y; posi.x = x;
					q.push(posi);
					visited[y][x] = 1;

					//q 안의 나라들은 같은 연합국!
					while (!q.empty())
					{
						POSI cur = q.front(); q.pop();
						
						status[cur.y][cur.x] = index;
						count[index]++;
						sum[index] += A[cur.y][cur.x];

						//4방향 탐색
						for (int dir = 0; dir < 4; dir++)
						{
							POSI next; next.y = cur.y + dy[dir]; next.x = cur.x + dx[dir];

							if (next.y < 0 || next.y >= N || next.x < 0 || next.x >= N)
								continue;

							int delta = abs(A[cur.y][cur.x] - A[next.y][next.x]); //인구 수 차이

							if (visited[next.y][next.x] == 0 && delta >= L && delta <= R)//연합
							{
								visited[next.y][next.x] = 1;
								q.push(next);
							}
						}//end: for 4방향 탐색

					}//end: while (!q.empty())

				}//end: if(status[y][x] == 0)

			}//for문
		}//for문

		//연합국 탐색 종료
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				int index = status[y][x];	//나라 또는 연합국의 시작
				int avg = sum[index] / count[index];	//연합국 아니면 1로 나눠지므로 값 그대로일것
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
