#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int N;	//땅 NxN
int T; // 나무 수
int Year;

int dy[8] = { -1,-1,-1,0,0,1,1,1 };
int dx[8] = { -1,0,1,-1,1,-1,0,1 };

int add[10][10] = { 0, };
int nutrient[10][10] = { 0, };

int Cur = 0;
int Next = 1;

struct TREE {
	int x; int y; int age;
};

TREE init_trees[100];	//trees[cur]에 넣어주기 전에 sorting하기 위해
queue<TREE> babyTree;
queue<TREE> trees[2];	//currentYear, nextYear 번갈아가며 이용할 것
queue<TREE> breeding;	//나이가 5배수인 나무는 겨울에 번식이 가능함
queue<TREE> deadTree;

bool cmp(TREE &a, TREE &b)
{
	return a.age < b.age;
}


//봄: 자신의 나이만큼 양분을 먹고, 나이가 1 증가한다.
void spring() {

	//한 칸에 나무 여러개 있으면, 나이가 어린 나무부터 양분을 먹는다.
	while (!babyTree.empty())
	{
		TREE tree = babyTree.front();	babyTree.pop();

		if (nutrient[tree.y][tree.x] >= tree.age) //자신의 나이만큼 양분을 먹고, 나이가 1 증가
		{
			nutrient[tree.y][tree.x] -= tree.age;
			++tree.age;
			trees[Next].push(tree);
		}
		// 자신의 나이만큼 양분을 먹을 수 없는 나무는 죽음
		//죽은 나무마다 나이를 2로 나눈 값이 나무가 있던 칸에 양분으로 추가된다. 
		else
		{
			deadTree.push(tree);
		}
	}
	while (!trees[Cur].empty())
	{
		TREE tree = trees[Cur].front();
		trees[Cur].pop();

		if (nutrient[tree.y][tree.x] >= tree.age) //자신의 나이만큼 양분을 먹고, 나이가 1 증가
		{
			nutrient[tree.y][tree.x] -= tree.age;
			++tree.age;
			trees[Next].push(tree);

			if (tree.age % 5 == 0)
				breeding.push(tree); // 나이가 5배수인 나무는 겨울에 번식이 가능함
		}
		// 자신의 나이만큼 양분을 먹을 수 없는 나무는 죽음
		//죽은 나무마다 나이를 2로 나눈 값이 나무가 있던 칸에 양분으로 추가된다. 
		else
		{
			deadTree.push(tree);
		}
	}

}

void summer() {
	while (!deadTree.empty()) {
		TREE cur_tree = deadTree.front();   deadTree.pop();
		nutrient[cur_tree.y][cur_tree.x] += (cur_tree.age / 2);
	}
}

//가을: 나이가 5배수인 나무는 번식. 인접한 8개 칸에 나이가 1인 나무가 생긴다.
void autumn()
{
	while (!breeding.empty())
	{
		TREE tree = breeding.front();
		breeding.pop();

		for (int dir = 0; dir < 8; dir++)
		{

			int y = tree.y + dy[dir];	int x = tree.x + dx[dir];

			if (y < 0 || y >= N || x < 0 || x >= N)
				continue;

			TREE baby; baby.y = y; baby.x = x; baby.age = 1;
			babyTree.push(baby);
		}
	}
}

//겨울: 입력으로 주어진 양분A[r][c]을 각 칸에 추가한다.
void winter()
{
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			nutrient[y][x] += add[y][x];
		}
	}
}

int main() {

	cin >> N >> T >> Year;

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cin >> add[y][x];		//겨울에 각 칸 마다 추가될 양분 양
			nutrient[y][x] = 5; //가장 처음에 양분은 모든 칸에 5만큼 들어있다
		}
	}

	//상도가 심은 나무의 정보
	for (int t = 0; t < T; t++)
	{
		cin >> init_trees[t].y >> init_trees[t].x >> init_trees[t].age;
		--init_trees[t].y;	//문제에서는 0 이아닌 1부터 시작이므로
		--init_trees[t].x;
	}

	sort(init_trees, init_trees + T, cmp);


	Cur = 0;
	for (int t = 0; t < T; t++)
	{
		trees[Cur].push(init_trees[t]);
	}

	while (Year--)
	{

		Next = (Cur + 1) % 2;

		spring();
		summer();
		autumn();
		winter();
		
		Cur = Next;
	}

	cout << (trees[Next].size() + babyTree.size());

	return 0;
}
