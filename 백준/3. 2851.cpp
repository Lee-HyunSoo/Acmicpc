// ½´ÆÛ ¸¶¸®¿À
#include <iostream>
#define endl

using namespace std;

int main() {
	int num[10], sum = 0, save;

	for (int i = 0; i < 10; i++) {
		cin >> num[i];
	}

	for (int i = 0; i < 10; i++) {
		sum += num[i];

		if (sum == 100) {
			cout << sum;
			break;
		}

		if (sum > 100) {
			save = sum - num[i];
			if ((100 - save) < (sum - 100)) {
				cout << save;
				break;
			}
			else if ((100 - save) == (sum - 100)) {
				cout << sum;
				break;
			}
			else if ((100 - save) > (sum - 100)) {
				cout << sum;
				break;
			}
		}
	}

	if (sum < 100) {
		cout << sum;
	}

	return 0;
}