#include "Vector.cpp"
#include <iostream>

using namespace std;
struct Entry {
	string name;
	int number;
};

int main() {
	Vector<int> v = Vector<int>(5);
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
		cout << " size is : " << v.size() << " capacity is : " << v.capacity() << endl;
	}

	for (int i = 0; i < v.size(); i ++) {
		cout << v[i] << endl;
	}
	return 0;
}