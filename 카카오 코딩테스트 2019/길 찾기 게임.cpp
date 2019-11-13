#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
#include<stack>

using namespace std;

//트리를 순회하는 방법은 검색을 통해 쉽게 알 수 있으므로 문제가 되지 않음
//이 문제의 핵심은 좌표 값으로 주어지는 노드들을 트리로 구성하는 부분

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

//함수에 vector 전달하고 함수에서 vector 사용할 경우, Call by Reference 
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
	
	//level(y) 내림차순으로 정렬, level이 같다면 value(x) 오른차순 정렬
	vector<Node> nodes;
	for (int i = 0; i < size; i++) {
		nodes.push_back({ i + 1, nodeinfo[i][0],nodeinfo[i][1] });
	}
	sort(nodes.begin(), nodes.end(), comp);
	
	//트리 구성
	Node* root = &nodes[0];	
	for (int i = 1; i < size; ++i) {	//주의.i는 0부터 아닌 1부터
		addNode(root, &nodes[i]);
	}

	//트리 순회
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