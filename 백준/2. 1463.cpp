#include <iostream>
#define endl '\n'
#define min2(a, b) a < b ? a : b
#define min3(a, b, c) a < b ? (a < c ? a : c) : (b < c ? b : c)

using namespace std;

int arr[1000001];

int main() {
	ios::sync_with_stdio(false);
	int num; cin >> num;
	arr[1] = 0, arr[2] = 1;

	for (int i = 3; i <= num; i++) {
		if (i % 3 == 0) arr[i] = min2((arr[i / 3] + 1), arr[i - 1] + 1);
		else if (i % 2 == 0) arr[i] = min2((arr[i / 2] + 1), arr[i - 1] + 1);
		else arr[i] = arr[i - 1] + 1;
	}

	cout << arr[num] << endl;
	return 0;
}