// ¹Ì·ÎÅ½»ö
#include <iostream>
#include <string>
#include <queue>
#define endl '\n'

using namespace std;
queue <pair<int, int>> q;
int arr[102][102];
int visit[102][102] = { 0 };
pair <int, int> p;

void BFS(pair<int, int> p, int x, int y);

int main() {
	ios::sync_with_stdio(false);
	int x, y; cin >> x >> y;
	string input;
	p = make_pair(1, 1);

	for (int i = 1; i <= x; i++) {
		cin >> input;
		for (int j = 1; j <= y; j++) {
			arr[i][j] = input[j - 1] - '0';
		}
	}

	BFS(p, x, y);

	return 0;
}

void BFS(pair<int, int> p, int x, int y) {
	q.push(p);

	while (!q.empty()) {
		p = q.front();
		q.pop();

		if (arr[p.first + 1][p.second] != 0 && visit[p.first + 1][p.second] != 1) {
			arr[p.first + 1][p.second] = arr[p.first][p.second] + 1;
			q.push(make_pair(p.first + 1, p.second));
			visit[p.first + 1][p.second] = 1;
		}
		if (arr[p.first][p.second + 1] != 0 && visit[p.first][p.second + 1] != 1) {
			arr[p.first][p.second + 1] = arr[p.first][p.second] + 1;
			q.push(make_pair(p.first, p.second + 1));
			visit[p.first][p.second + 1] = 1;
		}
		if (arr[p.first - 1][p.second] != 0 && visit[p.first - 1][p.second] != 1) {
			arr[p.first - 1][p.second] = arr[p.first][p.second] + 1;
			q.push(make_pair(p.first - 1, p.second));
			visit[p.first - 1][p.second] = 1;
		}
		if (arr[p.first][p.second - 1] != 0 && visit[p.first][p.second - 1] != 1) {
			arr[p.first][p.second - 1] = arr[p.first][p.second] + 1;
			q.push(make_pair(p.first, p.second - 1));
			visit[p.first][p.second - 1] = 1;
		}
	}
	cout << arr[x][y] << endl;
}