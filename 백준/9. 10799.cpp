// ¼è¸·´ë±â
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#define endl '\n'

using namespace std;
deque<char> q;
vector<int> v;
vector<pair<int, int>> razer[100001];
pair<int, int> stick[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string input; cin >> input;

	for (int i = 0; i < input.size(); i++) {
		q.push_back(input[i]);
		if (input[i] == '(' && input[i + 1] != ')') {
			v.push_back(i);
		}
		if (input[i] == ')' && input[i - 1] != '(') {
			v.push_back(i);
		}
	}
	
	while (!v.empty()) {
		for (int i = 0; i < input.size() - 1; i++) {
			if (input[i] == '(' && input[i + 1] == ')') {
				static int n = 0;
				stick[n] = make_pair(v[i], v[i + 1]);
				v.
			}
		}
	}
	
	return 0;
}