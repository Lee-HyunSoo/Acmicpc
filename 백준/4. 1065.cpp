// 한수(양의 정수 x의 각 자리가 등차수열)
#include <iostream>
#define endl '\n'

using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int num; cin >> num;
	int a, b, c;
	int result, cnt = 0;;

	for (int i = 1; i <= num; i++) {
		if (i < 100) result = i;
		else if (i >= 100 && i < 1000) {
			a = i / 100;
			b = (i % 100) / 10;
			c = i % 10;
			if ((a - b) == (b - c)) cnt++;
			result = 99 + cnt;
		}
	}
	cout << result << endl;

	return 0;
}