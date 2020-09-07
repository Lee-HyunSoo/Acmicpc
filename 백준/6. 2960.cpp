// 에라토스테네스의 체
#include <iostream>
#define endl '\n'

using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int num, k; cin >> num >> k;

	int arr[1000], cnt = 0, result = 0;

	for (int i = 2; i <= num; i++) {
		arr[i] = i;
	}

	for (int i = 2; i <= num; i++) {
		if (arr[i] == 0) continue;
		for (int j = i; j <= num; j += i) {
			if (arr[j] == 0) continue;
			result = arr[j];
			arr[j] = 0;
			cnt++;
			if (cnt == k) break;
		}
		if (cnt == k) break;
	}

	cout << result << endl;

	return 0;
}