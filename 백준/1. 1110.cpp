// 더하기 사이클
#include <iostream>
#define endl '\n'
using namespace std;

int main() {
	int num, save, result = 9999, cnt = 0;
	int case1, case2;

	cin >> num;
	save = num;

	while (result != num) {
		case1 = save / 10;
		case2 = save % 10;
		result = (case2 * 10) + ((case1 + case2) % 10);
		save = result;
		cnt++;
	}

	cout << cnt;
}