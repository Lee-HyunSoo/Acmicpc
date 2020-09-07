// DFS와 BFS
#include <iostream>
#include <stack>
#include <queue>
#define min2(a, b) a < b ? a : b
#define endl '\n'
using namespace std;

int adj_matrix[1001][1001] = { 0 };
int visit[1001] = { 0 };
int q_visit[1001] = { 0 };
stack <int> s;
queue <int> q;

void DFS(int vertex, int num);
void BFS(int vertex, int num);

int main() {
	ios::sync_with_stdio(false);

	int vertex, edge, num; cin >> vertex >> edge >> num; // 정점의 개수, 간선의 개수, 시작 정점
	int x, y; // 인접행렬 좌표

	for (int i = 1; i <= edge; i++) {
		cin >> x >> y;
		adj_matrix[x][y] = 1;
		adj_matrix[y][x] = 1;
	}

	DFS(vertex, num);
	cout << endl;
	BFS(vertex, num);

	return 0;
}

void DFS(int vertex, int num) {
	s.push(num);

	while (!s.empty()) {
		num = s.top();
		s.pop();
		for (int i = vertex; i >= 1; i--) {
			if (adj_matrix[num][i] == 1 && visit[i] != 1) s.push(i);
		}
		if (visit[num] != 1) cout << num << " ";
		visit[num] = 1;
	}
}

void BFS(int vertex, int num) {
	q.push(num);

	while (!q.empty()) {
		num = q.front();
		q.pop();
		for (int i = 1; i <= vertex; i++) {
			if (adj_matrix[num][i] == 1 && q_visit[i] != 1) q.push(i);
		}
		if (q_visit[num] != 1) cout << num << " ";
		q_visit[num] = 1;
	}
}