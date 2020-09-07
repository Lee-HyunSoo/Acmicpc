#include <iostream>
#include <vector>
#define endl '\n'

using namespace std;

struct sibal {
	int num;
	int save;
};

class Vector {
public:
	int* arr;
	int size = 0;
	int capacity = 1;

	Vector();
	void push_back(int num);
	void check() {
		for (int i = 0; i < capacity; i++) {
			cout << arr[i] << endl;
		}
	}
	int _size() {
		return size;
	}
};

Vector::Vector() {
	arr = new int[capacity];
}

void Vector::push_back(int num) {
	if (size == capacity) {
		int* newarr = new int[capacity * 2];
		for (int i = 0; i < size; i++) {
			newarr[i] = arr[i];
		}
		newarr[size] = num;
		delete[] arr;

		arr = newarr;
		capacity *= 2;
		size++;
	}
	else if (size < capacity) {
		arr[size] = num;
		size++;
	}
}



int main() {
	ios::sync_with_stdio(false);

	vector<sibal> v;
	/*vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);*/
	v.push_back({ 1, 2 });
	v.push_back({ 1, 3 });
	v.push_back({ 2, 3 });

	for (int i = 0; i < v.size(); i++) {
		cout << v[i].num << " " << v[i].save << endl;
	}

	cout << v.capacity() << endl;
	return 0;
}
