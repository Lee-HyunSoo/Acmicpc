// 유기농 배추
#include <iostream>
#include <queue>
#define endl '\n'

using namespace std;

queue <pair<int, int>> q;
pair<int, int> p;
int arr[51][51] = { 0 };
int visit[51][51] = { 0 };
void BFS(int width, int height);

int main() {
	ios::sync_with_stdio(false);
	int T; cin >> T; // test case
	int width, height, num;
	while (T--) {
		cin >> width >> height >> num; // 가로, 세로, 배추의 위치 개수
		for (int i = 1; i <= num; i++) {
			cin >> p.first >> p.second;
			arr[p.first + 1][p.second + 1] = 1;
		}
		BFS(width, height);
		
		for (int i = 0; i < 51; i++) {
			for (int j = 0; j < 51; j++) {
				arr[i][j] = 0;
				visit[i][j] = 0;
			}
		}	
	}
	return 0;
}

void BFS(int width, int height) {
	int cnt = 0;
	pair <int, int> data;

	for (int i = 1; i <= width; i++) {
		for (int j = 1; j <= height; j++) {
			if (arr[i][j] == 1 && visit[i][j] == 0) {
				q.push(make_pair(i, j));
				visit[i][j] = 1;
				cnt++;
			}
			while (!q.empty()) {
				data = q.front();
				q.pop();
				if (arr[data.first][data.second + 1] == 1 && visit[data.first][data.second + 1] == 0) {
					q.push(make_pair(data.first, data.second + 1));
					visit[data.first][data.second + 1] = 1;
				}
				if (arr[data.first][data.second - 1] == 1 && visit[data.first][data.second - 1] == 0) {
					q.push(make_pair(data.first, data.second - 1));
					visit[data.first][data.second - 1] = 1;
				}
				if (arr[data.first + 1][data.second] == 1 && visit[data.first + 1][data.second] == 0) {
					q.push(make_pair(data.first + 1, data.second));
					visit[data.first + 1][data.second] = 1;
				}
				if (arr[data.first - 1][data.second] == 1 && visit[data.first - 1][data.second] == 0) {
					q.push(make_pair(data.first - 1, data.second));
					visit[data.first - 1][data.second] = 1;
				}
			}
		}
	}

	cout << cnt << endl;
}