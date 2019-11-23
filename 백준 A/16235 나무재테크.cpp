#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int N;	//�� NxN
int T; // ���� ��
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

TREE init_trees[100];	//trees[cur]�� �־��ֱ� ���� sorting�ϱ� ����
queue<TREE> babyTree;
queue<TREE> trees[2];	//currentYear, nextYear �����ư��� �̿��� ��
queue<TREE> breeding;	//���̰� 5����� ������ �ܿ￡ ������ ������
queue<TREE> deadTree;

bool cmp(TREE &a, TREE &b)
{
	return a.age < b.age;
}


//��: �ڽ��� ���̸�ŭ ����� �԰�, ���̰� 1 �����Ѵ�.
void spring() {

	//�� ĭ�� ���� ������ ������, ���̰� � �������� ����� �Դ´�.
	while (!babyTree.empty())
	{
		TREE tree = babyTree.front();	babyTree.pop();

		if (nutrient[tree.y][tree.x] >= tree.age) //�ڽ��� ���̸�ŭ ����� �԰�, ���̰� 1 ����
		{
			nutrient[tree.y][tree.x] -= tree.age;
			++tree.age;
			trees[Next].push(tree);
		}
		// �ڽ��� ���̸�ŭ ����� ���� �� ���� ������ ����
		//���� �������� ���̸� 2�� ���� ���� ������ �ִ� ĭ�� ������� �߰��ȴ�. 
		else
		{
			deadTree.push(tree);
		}
	}
	while (!trees[Cur].empty())
	{
		TREE tree = trees[Cur].front();
		trees[Cur].pop();

		if (nutrient[tree.y][tree.x] >= tree.age) //�ڽ��� ���̸�ŭ ����� �԰�, ���̰� 1 ����
		{
			nutrient[tree.y][tree.x] -= tree.age;
			++tree.age;
			trees[Next].push(tree);

			if (tree.age % 5 == 0)
				breeding.push(tree); // ���̰� 5����� ������ �ܿ￡ ������ ������
		}
		// �ڽ��� ���̸�ŭ ����� ���� �� ���� ������ ����
		//���� �������� ���̸� 2�� ���� ���� ������ �ִ� ĭ�� ������� �߰��ȴ�. 
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

//����: ���̰� 5����� ������ ����. ������ 8�� ĭ�� ���̰� 1�� ������ �����.
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

//�ܿ�: �Է����� �־��� ���A[r][c]�� �� ĭ�� �߰��Ѵ�.
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
			cin >> add[y][x];		//�ܿ￡ �� ĭ ���� �߰��� ��� ��
			nutrient[y][x] = 5; //���� ó���� ����� ��� ĭ�� 5��ŭ ����ִ�
		}
	}

	//�󵵰� ���� ������ ����
	for (int t = 0; t < T; t++)
	{
		cin >> init_trees[t].y >> init_trees[t].x >> init_trees[t].age;
		--init_trees[t].y;	//���������� 0 �̾ƴ� 1���� �����̹Ƿ�
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
