// ±×¸²
#include <iostream>
#include <queue>
#include <algorithm>
#define endl '\n'

using namespace std;

int arr[502][502];
int visit[502][502] = { 0 };
queue <pair<int, int>> q;
void BFS(int height, int width);

int main() {
	ios::sync_with_stdio(false);
	int height, width; cin >> height >> width;
	for (int i = 1; i <= height; i++) {
		for (int j = 1; j <= width; j++) {
			cin >> arr[i][j];
		}
	}
	BFS(height, width);
	return 0;
}

void BFS(int height, int width) {
	int num = 0, area = 0;
	pair <int, int> data;
	vector <int> v;
	for (int i = 1; i <= height; i++) {
		for (int j = 1; j <= width; j++) {
			area = 0;
			if (arr[i][j] == 1 && visit[i][j] == 0) {
				q.push(make_pair(i, j));
				visit[i][j] = 1;
				num++;
				area++;
			}
			while (!q.empty()) {
				data = q.front();
				q.pop();
				if (arr[data.first][data.second + 1] == 1 && visit[data.first][data.second + 1] == 0) {
					q.push(make_pair(data.first, data.second + 1));
					visit[data.first][data.second + 1] = 1;
					area++;
				}
				if (arr[data.first][data.second - 1] == 1 && visit[data.first][data.second - 1] == 0) {
					q.push(make_pair(data.first, data.second - 1));
					visit[data.first][data.second - 1] = 1;
					area++;
				}
				if (arr[data.first + 1][data.second] == 1 && visit[data.first + 1][data.second] == 0) {
					q.push(make_pair(data.first + 1, data.second));
					visit[data.first + 1][data.second] = 1;
					area++;
				}
				if (arr[data.first - 1][data.second] == 1 && visit[data.first - 1][data.second] == 0) {
					q.push(make_pair(data.first - 1, data.second));
					visit[data.first - 1][data.second] = 1;	
					area++;
				}
			}
			if(area != 0)
				v.push_back(area);
		}	
	}
	cout << num << endl;
	sort(v.begin(), v.end());
	if (num == 0) cout << 0 << endl;
	else cout << v[v.size() - 1] << endl;
}