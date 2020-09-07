// 피시방 알바
#include <iostream>
#define endl '\n'
using namespace std;

int main() {
	int num, seat, cnt = 0;
	int arr[101] = { 0 };
	cin >> num;

	for (int i = 1; i <= num; i++) {
		cin >> seat;
		if (arr[seat + 1] == 0) arr[seat + 1] = 1;
		else cnt++;
	}
	cout << cnt;
}