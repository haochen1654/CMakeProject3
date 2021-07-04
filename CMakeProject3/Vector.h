#include <initializer_list>


template<typename T>
class Vector {
public:
	Vector(std::initializer_list<T>);
	explicit Vector(int s);
	T& operator[](int i);
	int size() const;
	~Vector();
	Vector(const Vector& a);
	Vector& operator=(const Vector& a);
	Vector(Vector&& a);
	void push_back(T t);
private:
	T* elem;
	int sz;
};

