#include <initializer_list>


template<typename T>
class Vector {
public:
	Vector(std::initializer_list<T> lst);
	explicit Vector(int s);
	T& operator[](int i);
	int size();
	int capacity();
	void reserve(int newsz);
	~Vector();
	Vector(const Vector& a);
	Vector& operator=(const Vector& a);
	Vector(Vector&& a);
	Vector& operator=(Vector&& a);
	void push_back(const T& t);
private:
	T* elem;
	T* space;
	T* last;
};

