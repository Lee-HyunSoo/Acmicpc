// 회전하는 큐
#include <iostream>
#define endl '\n'

using namespace std;
int arr[51];

struct qNode {
	int data;
	struct qNode* link = NULL;
};

class Queue {
public:
	struct qNode* front = NULL;
	struct qNode* back = NULL;
	void push(int data);
	void pop();
	int size();
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	Queue q;
	int N, M; cin >> N >> M;
	int cnt = 0;
	for (int i = 1; i <= N; i++)
		q.push(i);	
	for (int i = 0; i < M; i++) {
		int data; cin >> data;
		arr[i] = data;
	}

	for (int i = 0; i < M; i++) {
		int pos = 1;
		qNode* temp = q.front;
		while (temp->data != arr[i]) {
			temp = temp->link;
			pos++;
		}

		if (q.size() % 2 == 0) {
			if (pos <= (q.size() / 2)) {
				while (q.front->data != arr[i]) {
					qNode* n1 = q.front;
					q.back = q.front;
					q.front = n1->link;
					cnt++;
				}
			}
			if (pos > (q.size() / 2)) {
				while (q.front->data != arr[i]) {
					qNode* n2 = q.front;
					while (n2->link != q.back) n2 = n2->link;
					q.front = q.back;
					q.back = n2;
					cnt++;
				}
			}
		}
		if ((q.size() % 2 != 0)) {
			if (pos <= (q.size() / 2) + 1) {
				while (q.front->data != arr[i]) {
					qNode* n1 = q.front;
					q.back = q.front;
					q.front = n1->link;
					cnt++;
				}
			}
			if (pos > (q.size() / 2) + 1) {
				while (q.front->data != arr[i]) {
					qNode* n2 = q.front;
					while (n2->link != q.back) n2 = n2->link;
					q.front = q.back;
					q.back = n2;
					cnt++;
				}
			}
		}

		if (q.front->data == arr[i])	 q.pop();
	}
	cout << cnt << endl;
	return 0;
}

void Queue::push(int data) {
	qNode* newNode = new qNode;
	newNode->data = data;

	if (this->front == NULL) {
		this->front = newNode;
		this->back = newNode;
	}
	else {
		this->back->link = newNode;
		this->back = newNode;
		this->back->link = this->front;
	}
}

void Queue::pop() {
	qNode* temp = this->front;
	if (this->front == NULL) {
		this->front = NULL;
		this->back = NULL;
		return;
	}
	else {
		this->front = temp->link;
		this->back->link = this->front;
		delete(temp);
	}
}

int Queue::size() {
	qNode* temp = this->front;
	int size = 1;
	if (this->front == NULL) return 0;
	while (temp != this->back) {
		temp = temp->link;
		size++;
	}
	return size;
}