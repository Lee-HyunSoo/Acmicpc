#include <iostream>
#include <cmath>
#include <algorithm>

#define endl '\n'

using namespace std;
pair <int, int> arr[5];
bool compare(pair<int, int> n1, pair<int, int> n2);
int length[7];

int main() {
	ios::sync_with_stdio(false);
	int num; cin >> num;
	int x, y, result;

	while (num > 0) {
		for (int i = 1; i <= 4; i++) {
			cin >> x >> y;
			arr[i] = make_pair(x, y);
		}

		sort(arr + 1, arr + 5, compare);

		length[1] = ((arr[2].first - arr[1].first) * (arr[2].first - arr[1].first)) + ((arr[2].second - arr[1].second) * (arr[2].second - arr[1].second));
		length[2] = ((arr[3].first - arr[1].first) * (arr[3].first - arr[1].first)) + ((arr[3].second - arr[1].second) * (arr[3].second - arr[1].second));
		length[3] = ((arr[4].first - arr[2].first) * (arr[4].first - arr[2].first)) + ((arr[4].second - arr[2].second) * (arr[4].second - arr[2].second));
		length[4] = ((arr[4].first - arr[3].first) * (arr[4].first - arr[3].first)) + ((arr[4].second - arr[3].second) * (arr[4].second - arr[3].second));
		length[5] = ((arr[4].first - arr[1].first) * (arr[4].first - arr[1].first)) + ((arr[4].second - arr[1].second) * (arr[4].second - arr[1].second));
		length[6] = ((arr[3].first - arr[2].first) * (arr[3].first - arr[2].first)) + ((arr[3].second - arr[2].second) * (arr[3].second - arr[2].second));

		if (length[1] == length[2] && length[3] == length[4] && length[5] == length[6]) result = 1;
		else result = 0;

		cout << result << endl;
		num--;
	}
}

bool compare(pair<int, int> n1, pair<int, int> n2) {
	if (n1.first == n2.first) return n1.second < n2.second;
	else return n1.first < n2.first;
}