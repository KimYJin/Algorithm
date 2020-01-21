#include<iostream>

#include <string>
#include <vector>
#include<algorithm>
#include<functional>

using namespace std;


/*효율성 테스트 통과 못한 풀이*/
int solution(vector<int> scoville, int K) {

	int i = 0;
	int answer = 0;

	while (scoville.size() > 0) {

		sort(scoville.begin(), scoville.end(), greater<int>()); //내림차순

		//모든 음식의 스코빌 지수가 K 이상일 때 -> 반복하여 섞는 최소 횟수 리턴
		if (scoville.back() >= K) {
			answer = i;
			break;

		}

		// K 이상으로 만들 수 없는, 더이상 섞을 수 없는 경우에는 -1 return
		if (scoville.size() < 2)
		{
			return -1;
		}
		//섞은 음식의 스코빌 = (가장 안매운 음식의 스코빌)+(2번째로 안매운 음식의 스코빌* 2)
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