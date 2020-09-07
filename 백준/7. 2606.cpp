#include <iostream>
#include <stack>
#include <queue>

#define endl '\n'
using namespace std;

int adj_matrix[101][101] = { 0 };
int s_visit[101] = { 0 };
int q_visit[101] = { 0 };

stack <int> s;
queue <int> q;

void DFS(int vertex, int n);

int main() {
	ios::sync_with_stdio(false);

	int vertex, edge; cin >> vertex >> edge;
	int x, y;

	for (int i = 1; i <= edge; i++) {
		cin >> x >> y;
		adj_matrix[x][y] = 1;
		adj_matrix[y][x] = 1;
	}

	DFS(vertex, 1);

}

void DFS(int vertex, int n) {
	s.push(n);
	int cnt = -1;
	while (!s.empty()) {
		n = s.top();
		s.pop();
		for (int i = vertex; i >= 1; i--) {
			if (adj_matrix[n][i] == 1 && s_visit[i] != 1) s.push(i);
		}
		if (s_visit[n] != 1) cnt++;
		s_visit[n] = 1;
	}
	cout << cnt << endl;
}