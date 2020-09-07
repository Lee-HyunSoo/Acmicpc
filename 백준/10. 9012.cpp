// °ıÈ£
#include <iostream>
#include <string>
#include <stack>
#define endl '\n'
using namespace std;

stack<char> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T; cin >> T;
	int cnt = 0;

	for (int i = 0; i < T; i++) {
		string input; cin >> input;

		for (int j = 0; j < input.size(); j++) s.push(input[j]);

		if (input[0] == '(' && input[input.size() - 1] == ')') {
			while (!s.empty()) {
				if (s.top() == ')') {
					cnt++;
					s.pop();
				}
				else if (s.top() == '(') {
					cnt--;
					s.pop();
					if (cnt < 0) break;
				}
			}

			while (!s.empty()) s.pop();
			if (cnt == 0) cout << "YES" << endl;
			else cout << "NO" << endl;
			cnt = 0;
		}
		else {
			cout << "NO" << endl;
			while (!s.empty()) s.pop();
		}
	}
		
	return 0;
}