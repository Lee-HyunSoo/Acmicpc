// 다항함수의 미분
#include <iostream>
#include <cstring>
#define endl '\n'

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	string input; cin >> input;

	int stop = 0, cnt = 0;

	for (int i = 0; i < input.size(); i++) {
		if (input[i] == 'x') {
			stop = i;
			for (int i = 0; i < stop; i++)
				cout << input[i];
		}
		if (input[0] == 'x') {
			cout << "1" << endl;
			break;
		}
		if (input[0] == '-' && input[1] == 'x') {
			cout << "-1" << endl;
			break;
		}
		if (input[i] != 'x') {
			cnt++;
			if (cnt == input.size()) cout << "0" << endl;
		}
	}

	return 0;
}