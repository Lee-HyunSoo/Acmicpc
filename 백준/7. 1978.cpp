//소수찾기

#include <iostream>
#define endl '\n'

using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int n; cin >> n;
	int arr[1000], cnt = 0;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 2; i <= n; i++) {
		if (arr[i] == 0) continue;
		for (int j = i + i; j <= n; j += i) {
			if (arr[j] % i == 0) cnt++;
		}
	}

	for (int i = 2; i <= n; i++) {
		if (arr[i] != 0) cout << arr[i] << endl;
	}
}