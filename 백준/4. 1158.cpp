// 요세푸스 문제
#include <iostream>
#define endl '\n'

using namespace std;

struct qNode {
	int data;
	qNode* link = NULL;
};

class Queue {
public:
	qNode* front = NULL;
	qNode* back = NULL;

	void push(int data);
	void pop();
	int size();
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	Queue q;
	int N, K; cin >> N >> K; // 큐의크기, k번째 사람 삭제

	for (int i = 1; i <= N; i++) {
		q.push(i);
	}

	cout << "<";
	while (q.size() > 1) {
		for (int j = 1; j < K; j++) {
			qNode* temp = q.front;
			q.back = q.front;
			q.front = temp->link;
		}
		cout << q.front->data;
		q.pop();
		cout << ", ";
	}
	cout << q.front->data;
	q.pop();
	cout << ">";

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