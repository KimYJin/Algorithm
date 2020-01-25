/*
https://swexpertacademy.com/main/talk/solvingClub/problemView.do?contestProbId=AV2b7Yf6ABcBBASw&solveclubId=AV6kld8aisgDFASb&problemBoxTitle=A%ED%98%95+%EC%A4%80%EB%B9%84+%EB%AC%B8%EC%A0%9C&problemBoxCnt=4&probBoxId=AV_W57U6ACQDFAX7
���̰� B �̻��� ž �߿��� ž�� ���̿� B�� ���̰� ���� ���� ���� ���
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>

using namespace std;

const int MAX = 20;

vector<int> height(MAX, 0);
int T = 0; //testcase
int N = 0;	// ���� ��
int B = 0; //���� ����
int answer = 0;

void dfs(int sum, int index) {
	if (index > N)
		return;

	if (sum >= B)
		answer = min(sum,answer);	//B �̻� �� �ּڰ�

	dfs(sum + height[index], index + 1);
	dfs(sum, index + 1);	
}

int main(void) {

	/*
	ifstream ifile("input (2).txt");	//ifstream ��ü ifile����

	if (!ifile) {	//��ü ���� ����
		cout << "can't open file" << endl;
		return 1;
	}

	ifile >> T;

	for(int t=1;t<=4;t++)	{
		
		int total_sum = 0;

		ifile >> N >> B;

		for (int i = 0; i < N; i++) {
			ifile >> height[i];
			total_sum += height[i];
		}
		*/
	cin >> T;

	for (int t = 1; t <= T; t++) {

		int total_sum = 0;

		cin >> N >> B;

		for (int i = 0; i < N; i++) {
			cin >> height[i];
			total_sum += height[i];
		}

		//Ǯ��
		answer = total_sum;
		dfs(0, 0);

		cout << "#" << t << " " << (answer - B) << endl;
	}

	//ifile.close();
	return 0;
}

