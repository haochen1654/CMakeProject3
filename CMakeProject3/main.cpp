#include "Vector.cpp"
#include <iostream>

using namespace std;

int main() {
	Vector<int> v = Vector<int>(5);
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
		cout << " size is :" << v.size() << "capacity is :" << v.capacity();
	}

	for (int i = 0; i < v.size(); i ++) {
		cout << v[i];
	}

	return 0;
}