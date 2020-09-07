// ½ºÅÃ
#include <iostream>
#define endl '\n'

using namespace std;

struct stackNode {
	int data;
	stackNode* link;
};

stackNode* topNode;

class Stack {
public:
	void push(int data);
	int pop();
	int size();
	int empty();
	int top();
};

int main() {
	ios::sync_with_stdio(false);
	Stack stack;
	int num; cin >> num;

	for (int i = 0; i < num; i++) {
		string input; cin >> input;

		if (input == "push") {
			int num; cin >> num;
			stack.push(num);
		}
		else if (input == "pop") {
			cout << stack.pop() << endl;
		}
		else if (input == "size") {
			cout << stack.size() << endl;
		}
		else if (input == "empty") {
			cout << stack.empty() << endl;
		}
		else if (input == "top") {
			cout << stack.top() << endl;
		}
	}

	return 0;
}

void Stack::push(int data) {
	stackNode* temp = new stackNode;
	temp->data = data;

	if (topNode == NULL) {
		topNode = temp;
		temp->link = NULL;
	}
	else {
		temp->link = topNode;
		topNode = temp;
	}
}

int Stack::pop() {
	if (topNode == NULL) return -1;
	else {
		int data = topNode->data;
		topNode = topNode->link;
		return data;
	}
}

int Stack::size() {
	stackNode* temp = topNode;
	int count = 0;

	while (temp != NULL) {
		count++;
		temp = temp->link;
	}
	return count;
}

int Stack::empty() {
	if (topNode == NULL) return 1;
	else return 0;
}

int Stack::top() {
	if (topNode == NULL) return -1;
	else return topNode->data;
}