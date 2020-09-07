// queue
#include <iostream>
#define endl '\n'

using namespace std;

struct qNode {
	int data;
	struct qNode* link = NULL;
};

class Queue {
public:
	struct qNode* frontNode = NULL;
	struct qNode* backNode = NULL;

	void push(int data);
	int pop();
	int size();
	int empty();
	int front();
	int back();
};

void Queue::push(int data) {
	qNode* newNode = new qNode;
	newNode->data = data;

	if (this->frontNode == NULL) {
		this->frontNode = newNode;
		this->backNode = newNode;
	}
	else {
		this->backNode->link = newNode;
		this->backNode = newNode;
	}
}

int Queue::pop() {
	qNode* temp = this->frontNode;

	if (this->frontNode == NULL) return -1;
	else {
		int num = this->frontNode->data;
		this->frontNode = temp->link;
		delete temp;
		return num;
	}
}

int Queue::size() {
	qNode* temp = this->frontNode;
	int cnt = 0;

	while (temp != NULL) {
		cnt++;
		temp = temp->link;
	}
	return cnt;
}

int Queue::empty() {
	if (this->frontNode == NULL) return 1;
	else return 0;
}

int Queue::front() {
	if (this->frontNode == NULL) return -1;
	else return this->frontNode->data;
}

int Queue::back() {
	if (this->frontNode == NULL) return -1;
	else return this->backNode->data;
}

int main() {
	Queue q;
	int num; cin >> num;

	for (int i = 0; i < num; i++) {
		string input; cin >> input;

		if (input == "push") {
			int num; cin >> num;
			q.push(num);
		}
		if (input == "pop")
			cout << q.pop() << endl;
		if (input == "size")
			cout << q.size() << endl;
		if (input == "empty")
			cout << q.empty() << endl;
		if (input == "front")
			cout << q.front() << endl;
		if (input == "back")
			cout << q.back() << endl;
	}

	return 0;
}

/*struct qNode {
	int data;
	struct qNode* link = NULL;
};

struct qType {
	struct qNode* frontNode = NULL;
	struct qNode* backNode = NULL;
};

class Queue {
public:
	void push(qType* t, int data);
	int pop(qType* t);
	int size(qType* t);
	int empty(qType* t);
	int front(qType* t);
	int back(qType* t);
};

/*void Queue::push(qType* t, int data) {
	qNode* newNode = new qNode;
	newNode->data = data;

	if (t->frontNode == NULL) {
		t->frontNode = newNode;
		t->backNode = newNode;
	}
	else {
		t->backNode->link = newNode;
		t->backNode = newNode;
	}
}

int Queue::pop(qType* t) {
	if (t->frontNode == NULL) return -1;
	else {
		qNode* temp = t->frontNode;
		int data;
		data = t->frontNode->data;

		t->frontNode = temp->link;
		delete temp;
		return data;
	}
}

int Queue::size(qType* t) {
	int cnt = 0;

	qNode* temp = t->frontNode;
	while (temp != NULL) {
		cnt++;
		temp = temp->link;
	}
	return cnt;
}

int Queue::empty(qType* t) {
	if (t->frontNode == NULL) return 1;
	else return 0;
}

int Queue::front(qType* t) {
	if (t->frontNode == NULL) return -1;
	else return t->frontNode->data;
}

int Queue::back(qType* t) {
	if (t->frontNode == NULL) return -1;
	else return t->backNode->data;
}

int main() {
	ios::sync_with_stdio(false);
	Queue q;
	qType* t = new qType;

	int num; cin >> num;

	for (int i = 0; i < num; i++) {
		string input; cin >> input;

		if (input == "push") {
			int num; cin >> num;
			q.push(t, num);
		}
		if (input == "pop") {
			cout << q.pop(t) << endl;
		}
		if (input == "size") {
			cout << q.size(t) << endl;
		}
		if (input == "empty") {
			cout << q.empty(t) << endl;
		}
		if (input == "front") {
			cout << q.front(t) << endl;
		}
		if (input == "back") {
			cout << q.back(t) << endl;
		}
	}

	return 0;
}*/