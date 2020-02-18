/*
https://www.acmicpc.net/problem/17281
*/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int max_inning = 50;
int num_inning = 0;	//ÀÌ´× ¼ö
const int num_player = 9;

int hitter[max_inning][num_player] = { 0, };
vector <int> order(num_player);

int result = 0;

void solve(void) {
	int score = 0;
	int i = 0;

	for (int cur_inning = 0; cur_inning < num_inning; cur_inning++) {

		int cur_out = 0;
		int pos[4] = { 0, };

		while (cur_out < 3) {

			if (i >= num_player)
				i = 0;

			int hit_result = hitter[cur_inning][order[i]];
			i++;
			pos[0] = 1;

			if (hit_result == 1) {
				score += pos[3];

				for (int p = 3; p > 0; p--) {
					pos[p] = pos[p - 1];
				}
			}
			else if (hit_result == 2) {
				score += pos[3] + pos[2];

				for (int p = 3; p > 1; p--) {
					pos[p] = pos[p - 2];
				}
				pos[1] = 0;
			}
			else if (hit_result == 3) {
				score += pos[3] + pos[2] + pos[1];
				pos[3] = pos[0];
				pos[2] = pos[1] = 0;
			}
			else if (hit_result == 4) {
				score += pos[3] + pos[2] + pos[1] + pos[0];
				pos[3] = pos[2] = pos[1] = 0;
			}
			else {
				cur_out++;
			}

			//cout << hit_result << "," << score << endl;
		}//end while cur_out
	}//end for cur_inning

	result = max(result, score);
}


int main(void) {

	cin >> num_inning;

	for (int i = 0; i < num_inning; i++) {
		for (int p = 0; p < num_player; p++) {
			cin >> hitter[i][p];
		}
	}

	for (int p = 0; p < num_player; p++) {
		order[p] = p;
	}
	
	do {
		if (order[3] == 0)
			solve();

	} while (next_permutation(order.begin(), order.end()));
	
	cout << result;

	return 0;
}