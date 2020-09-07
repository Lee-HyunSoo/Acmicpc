#include <iostream>
#include <cstring>
#define endl '\n'

using namespace std;

int num_score(char str[], int score, int count);

int main() {
	int num, score = 0, count = 0;
	int grade[100];
	char str[80];

	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> str;
		grade[i] = num_score(str, score, count);
	}

	for (int i = 0; i < num; i++) {
		cout << grade[i] << endl;
	}
}

int num_score(char str[], int score, int count) {
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == 'X')
			count = 0;

		if (str[i] == 'O') {
			count++;
			score += count;
		}
		else if (i > 1 && str[i - 1] == '0') {
			count++;
			score += count;
		}
	}

	return score;
}