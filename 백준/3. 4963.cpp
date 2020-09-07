// ¼¶ÀÇ °³¼ö
#include <iostream>
#include <queue>
#define endl '\n'

using namespace std;
int arr[52][52];
int visit[52][52] = { 0 };
queue <pair<int, int>> q;
void BFS(int width, int height);

int main() {
	ios::sync_with_stdio(false);
	int width, height; cin >> width >> height;

	while (width != 0 && height != 0) {
		for (int i = 1; i <= height; i++) {
			for (int j = 1; j <= width; j++) {
				cin >> arr[i][j];
			}
		}
		BFS(width, height);
		for (int i = 1; i <= height; i++) {
			for (int j = 1; j <= width; j++) {
				arr[i][j] = 0;
				visit[i][j] = 0;
			}
		}
		cin >> width >> height;
	}
	return 0;
}

void BFS(int width, int height) {
	pair<int, int> p;
	int cnt = 0;
	for (int i = 1; i <= height; i++) {
		for (int j = 1; j <= width; j++) {
			if (arr[i][j] == 1 && visit[i][j] == 0) {
				q.push(make_pair(i, j));
				visit[i][j] = 1;
				cnt++;
			}

			while (!q.empty()) {
				p = q.front();
				q.pop();

				if (arr[p.first + 1][p.second] == 1 && visit[p.first + 1][p.second] == 0) {
					q.push(make_pair(p.first + 1, p.second));
					visit[p.first + 1][p.second] = 1;
				}
				if (arr[p.first - 1][p.second] == 1 && visit[p.first - 1][p.second] == 0) {
					q.push(make_pair(p.first - 1, p.second));
					visit[p.first - 1][p.second] = 1;
				}
				if (arr[p.first][p.second + 1] == 1 && visit[p.first][p.second + 1] == 0) {
					q.push(make_pair(p.first, p.second + 1));
					visit[p.first][p.second + 1] = 1;
				}
				if (arr[p.first][p.second - 1] == 1 && visit[p.first][p.second - 1] == 0) {
					q.push(make_pair(p.first, p.second - 1));
					visit[p.first][p.second - 1] = 1;
				}
				if (arr[p.first - 1][p.second - 1] == 1 && visit[p.first - 1][p.second - 1] == 0) {
					q.push(make_pair(p.first - 1, p.second - 1));
					visit[p.first - 1][p.second - 1] = 1;
				}
				if (arr[p.first - 1][p.second + 1] == 1 && visit[p.first - 1][p.second + 1] == 0) {
					q.push(make_pair(p.first - 1, p.second + 1));
					visit[p.first - 1][p.second + 1] = 1;
				}
				if (arr[p.first + 1][p.second - 1] == 1 && visit[p.first + 1][p.second - 1] == 0) {
					q.push(make_pair(p.first + 1, p.second - 1));
					visit[p.first + 1][p.second - 1] = 1;
				}
				if (arr[p.first + 1][p.second + 1] == 1 && visit[p.first + 1][p.second + 1] == 0) {
					q.push(make_pair(p.first + 1, p.second + 1));
					visit[p.first + 1][p.second + 1] = 1;
				}
			}
		}
	}
	cout << cnt << endl;
}