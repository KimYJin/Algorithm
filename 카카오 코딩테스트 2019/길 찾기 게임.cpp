#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
#include<stack>

using namespace std;

//Ʈ���� ��ȸ�ϴ� ����� �˻��� ���� ���� �� �� �����Ƿ� ������ ���� ����
//�� ������ �ٽ��� ��ǥ ������ �־����� ������ Ʈ���� �����ϴ� �κ�

struct Node {
	int id;
	int x, y;
	Node *left;
	Node *right;
};

bool comp(Node a, Node b) {

	if (a.y != b.y)
		return (a.y > b.y);
	
	return (a.x < b.x);
}

void addNode(Node *parent, Node* child) {

	if (child->x < parent->x) {

		if (parent->left == NULL) 
			parent->left = child;
		else 
			addNode(parent->left, child);
		
	}
	else {
		if (parent->right == NULL) 
			parent->right = child;
		else 
			addNode(parent->right, child);
		
	}
}

//�Լ��� vector �����ϰ� �Լ����� vector ����� ���, Call by Reference 
void preorder(vector<int>& ans, Node* node) {
	if (node == NULL)return;

	ans.push_back(node->id);
	preorder(ans, node->left);
	preorder(ans, node->right);
}

void postorder(vector<int>& ans, Node* node) {
		if (node == NULL)return;

		postorder(ans, node->left);
		postorder(ans, node->right);
		ans.push_back(node->id);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	
	int size = nodeinfo.size();
	
	//level(y) ������������ ����, level�� ���ٸ� value(x) �������� ����
	vector<Node> nodes;
	for (int i = 0; i < size; i++) {
		nodes.push_back({ i + 1, nodeinfo[i][0],nodeinfo[i][1] });
	}
	sort(nodes.begin(), nodes.end(), comp);
	
	//Ʈ�� ����
	Node* root = &nodes[0];	
	for (int i = 1; i < size; ++i) {	//����.i�� 0���� �ƴ� 1����
		addNode(root, &nodes[i]);
	}

	//Ʈ�� ��ȸ
	vector<vector<int>> answer{ {},{} };
	preorder(answer[0], root);
	postorder(answer[1], root);

	return answer;
}

int main() {

	vector<vector<int>> nodeinfo = { {5, 3},{11, 5},{13, 3},{3, 5},
									{6, 1},{1, 3},{8, 6},{7, 2},{2, 2} };

	vector<vector<int>> answer = solution(nodeinfo);

	return 0;
}