// 무한 이진트리
#include <iostream>
#define endl '\n'

using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int x, y;
	int left = 0, right = 0;
	pair<int, int> root = make_pair(1, 1);
	pair<int, int> p;

	cin >> x >> y;
	p = make_pair(x, y);

	/*while (p != root) {
		if (p.first < p.second) {
			pair<int, int> temp = make_pair(p.first, p.second - p.first);
			p = temp;
			right++;
		}
		else if (p.first > p.second) {
			pair<int, int> temp = make_pair(p.first - p.second, p.second);
			p = temp;
			left++;
		}
	}*/

	while (p != root) {
		if (p.second == 1) {
			left += p.first - 1;
			break;
		}
		else if (p.first == 1) {
			right += p.second - 1;
			break;
		}
		else {
			if (p.first > p.second) {
				left += p.first / p.second;
				p.first %= p.second;
			}
			else if (p.first < p.second) {
				right += p.second / p.first;
				p.second %= p.first;
			}
		}
	}
	cout << left << " " << right << endl;
	return 0;
}