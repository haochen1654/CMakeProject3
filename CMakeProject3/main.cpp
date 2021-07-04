#include "Vector.cpp"
#include <iostream>

using namespace std;
int main() {
	Vector<double> v = Vector<double>(10);

	for (int i = 0; i < 10; i++) {
		v[i] = i;
		cout << v[i];
	}
	return 0;
}