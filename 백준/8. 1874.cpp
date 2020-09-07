// 스택 수열
#include <iostream>
#include <stack>
#define endl '\n'

using namespace std;
stack<int> s;
int arr[100001];
char answer[100001];
int save;
int cnt = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		int input; cin >> input;
		arr[i] = input;
	}
	s.push(0);

	for (int i = 1; i <= n; i++) {
		while (s.top() < arr[i]) {
			static int num = 1;
			s.push(num);
			num++;
			answer[cnt] = '+';
			cnt++;

		}
		while (s.top() > arr[i]) {
			s.pop();
			answer[cnt] = '-';
			cnt++;
		}
		if (s.top() == arr[i]) {
			save = s.top();
			s.pop();
			answer[cnt] = '-';
			cnt++;
		}
		if (arr[i] > save) {
			cout << "NO" << endl;
			exit(0);
		}
	}

	for (int i = 0; i < cnt; i++) {
		cout << answer[i] << endl;
	}

	return 0;
}