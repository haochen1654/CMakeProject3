#include "Vector.h"
#include <stdexcept>

using namespace std;
template<typename T>
Vector<T>::Vector(int s)
{
	if (s < 0)
		throw std::length_error{ "Vector constructor:negative size" };
	elem = new T[s];
	sz = s;
}

template<typename T>
Vector<T>::Vector(std::initializer_list<T> lst) : elem{new T[lst.size()]}, sz{static_cast<int>(lst.size())}
{
	copy(lst.  begin(), lst.end(), elem);
}

template<typename T>
T& Vector<T>::operator[](int i)
{
	if (i < 0 || size() <= i)
		throw std::out_of_range{ "Vector::operator[]" };
	
	return elem[i];
}

template<typename T>
int Vector<T>::size() const
{
	return sz;
}

template<typename T>
Vector<T>::~Vector()
{
	delete[] elem;
}

//copy construct
template<typename T>
Vector<T>::Vector(const Vector<T>& a) : elem{new T[a.sz]}, sz{a.sz}
{
	 for (int i = 0; i != sz; i++)
	 {
		 elem[i] = a.elem[i];
	 }
}

//copy assignment
template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& a)
{
	T* p = new double[a.sz];
	for (int i = 0; i != a.sz; i++)
	{
		p[i] = a.elem[i];
	}
	delete[] elem;
	elem = p;
	sz = a.sz;
	return *this;
}

//move assignment
template<typename T>
Vector<T>::Vector(Vector&& a):elem{a.elem}, sz{a.sz}
{
	a.elem = nullptr;
	a.sz = 0;
}








