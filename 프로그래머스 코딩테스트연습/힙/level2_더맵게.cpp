#include<iostream>

#include <string>
#include <vector>
#include<algorithm>
#include<functional>

using namespace std;


/*ȿ���� �׽�Ʈ ��� ���� Ǯ��*/
int solution(vector<int> scoville, int K) {

	int i = 0;
	int answer = 0;

	while (scoville.size() > 0) {

		sort(scoville.begin(), scoville.end(), greater<int>()); //��������

		//��� ������ ���ں� ������ K �̻��� �� -> �ݺ��Ͽ� ���� �ּ� Ƚ�� ����
		if (scoville.back() >= K) {
			answer = i;
			break;

		}

		// K �̻����� ���� �� ����, ���̻� ���� �� ���� ��쿡�� -1 return
		if (scoville.size() < 2)
		{
			return -1;
		}
		//���� ������ ���ں� = (���� �ȸſ� ������ ���ں�)+(2��°�� �ȸſ� ������ ���ں�* 2)
		else 
		{
			i++;

			int first = scoville.back();
			scoville.pop_back();

			int second = scoville.back();
			scoville.pop_back();

			int mix = first + second * 2;
			scoville.push_back(mix);
		}
	}

	return answer;
}

int main(void) {

	vector<int> scoville = { 1, 2, 3, 9, 10, 12 };
	int K = 7;

	int answer = solution(scoville, K);

	cout << answer;

	return 0;
}