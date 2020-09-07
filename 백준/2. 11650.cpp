#include <iostream>
#include <algorithm>
#define endl '\n'

using namespace std;

pair<int, int> p[100000];

bool compare(pair<int, int> p1, pair<int, int> p2);

int main() {
	ios::sync_with_stdio(false);
	int num, x, y;
	pair<int, int> save;
	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> x >> y;
		p[i] = make_pair(x, y);
	}

	sort(p, p + num, compare);

	/*for (int i = 0; i < num; i++) {
		for (int j = i; j < num; j++) {
			if (p[i].first > p[j].first) {
				save = p[i];
				p[i] = p[j];
				p[j] = save;
			}

			if (p[i].first == p[j].first) {
				if (p[i].second > p[j].second) {
					save = p[i];
					p[i] = p[j];
					p[j] = save;
				}
			}
		}
	}*/

	for (int i = 0; i < num; i++) {
		cout << p[i].first << " " << p[i].second << endl;
	}
}

bool compare(pair<int, int> p1, pair<int, int> p2) {
	if (p1.first == p2.first) {
		return p1.second < p2.second;
	}
	else {
		return p1.first < p2.first;
	}
}