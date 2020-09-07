// 수 정렬하기
#include <iostream>
#define endl '\n'

using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int num, save, arr[1000];
	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < num; i++) {
		for (int j = i; j < num - 1; j++) {
			if (arr[i] > arr[j + 1]) {
				save = arr[i];
				arr[i] = arr[j + 1];
				arr[j + 1] = save;
			}
		}
	}

	for (int i = 0; i < num; i++) {
		cout << arr[i] << endl;
	}

}