#include <iostream>
#define endl '\n'
#define min2(a, b) a < b ? a : b
#define min3(a, b, c) a < b ? (a < c ? a : c) : (b < c ? b : c)

using namespace std;

long long arr[100001];

int main() {
	ios::sync_with_stdio(false);
	int t; cin >> t;
	int cnt1 = 0, cnt2 = 0;
	int i = 6;

	arr[1] = 1, arr[2] = 1, arr[3] = 1; arr[4] = 2, arr[5] = 2;

	for (int i = 1; i <= 101; i++) {
		if (arr[i] == 1) cnt1++;
		if (arr[i] == 2) cnt2++;
	}

	while (t--) {
		int num; cin >> num;
		while (i <= num) {
			for (int j = 1; j <= cnt1; j++) {
				arr[i] = arr[i - 1] + 1;
				i++;
			}
			cnt1 = 0;
			for (int j = 1; j <= cnt2; j++) {
				arr[i] = arr[i - 1] + 2;
				i++;
			}
			cnt2 = 0;

			arr[i] = arr[i - 1] + arr[i - 5];
			i++;
		}
		cout << arr[num] << endl;
	}
	return 0;
}