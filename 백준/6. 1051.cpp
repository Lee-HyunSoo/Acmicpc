#include <iostream>
#define endl '\n'
using namespace std;

int arr[51][51];

int main() {
	ios::sync_with_stdio(false);
	int n, m; cin >> n >> m;
	int save, result = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			save = arr[i][j];
			for (int k = j + 1; k <= m; k++) {
				if (save == arr[i][k]) result = k - j;
				cout << result << endl;
			}
		}
	}


	return 0;
}