// ¼ö Ã£±â
#include <iostream>
#include <algorithm>
#define endl '\n'

using namespace std;

bool BinarySearch(int* arr, int len, int key);

int main() {
	ios::sync_with_stdio(false);
	int arr1[100000], arr2[100000];

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr1[i];
	}

	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> arr2[i];
	}

	sort(arr1, arr1 + n);

	for (int i = 0; i < m; i++) {
		cout << BinarySearch(arr1, n, arr2[i]) << endl;
	}

	return 0;
}

bool BinarySearch(int* arr, int len, int key) {
	int start = 0;
	int end = len - 1;
	int mid;

	while (end - start >= 0) {
		mid = (start + end) / 2;

		if (arr[mid] == key)
			return true;
		else if (arr[mid] > key)
			end = mid - 1;
		else
			start = mid + 1;
	}
	return false;
}