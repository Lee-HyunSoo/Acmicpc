#include <iostream>
#define endl '\n'

using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int t; cin >> t;
	int arr[11];
	arr[1] = 1; arr[2] = 2; arr[3] = 4;

	for (int i = 0; i < t; i++) {
		int num; cin >> num;
		for (int j = 4; j <= num; j++) {
			arr[j] = arr[j - 1] + arr[j - 2] + arr[j - 3];
		}
		cout << arr[num] << endl;
	}

	return 0;
}