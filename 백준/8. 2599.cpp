#include <iostream>
#define endl '\n'

using namespace std;
void DFS(int student[][2], int answer[][3]);
void pairing();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	pairing();
	return 0;
}

void pairing() {
	int N; cin >> N;

	int student[3][2];
	int answer[3][3];
	int index = 0;

	for (int i = 0; i < 3; i++) {
		int boy, girl; cin >> boy >> girl;
		student[i][0] = boy;
		student[i][1] = girl;
		answer[i][0] = answer[i][1] = answer[i][2] = -1;
	}

	if (student[0][0] > student[1][1] + student[2][1] || student[1][0] > student[0][1] + student[2][1] || student[2][0] > student[0][1] + student[1][1]) {
		cout << 0 << endl;
		return;
	}
	DFS(student, answer);
}

void DFS(int student[][2], int answer[][3]) {
	bool finish = true;
	bool success = false;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == j) continue;
			else {
				if (answer[i][j] == -1) {
					finish = false;
					break;
				}
			}
		}
		if (finish == false) break;
	}

	if (finish == true) {
		success = true;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 2; j++) {
				if (student[i][j] != 0) {
					success = false;
					break;
				}
			}
			if (success == false) break;
		}
	}

	if (success == true) {
		cout << 1 << endl;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == j) continue;
				else {
					cout << answer[i][j] << " ";
				}
			}
			cout << endl;
		}
		exit(0);
	}


	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (answer[i][j] == -1 && i != j) {
				int temp1, temp2;
				if (student[i][0] > student[j][1]) {
					temp1 = student[j][1];
					temp2 = student[i][0];
					answer[i][j] = student[j][1];
					student[i][0] -= student[j][1];
					student[j][1] = 0;
					DFS(student, answer);
				}
				else {
					temp1 = student[j][1];
					temp2 = student[i][0];
					answer[i][j] = student[i][0];
					student[j][1] -= student[i][0];
					student[i][0] = 0;
					DFS(student, answer);
				}
				student[j][1] = temp1;
				student[i][0] = temp2;
				answer[i][j] = -1;
			}
		}
	}
}