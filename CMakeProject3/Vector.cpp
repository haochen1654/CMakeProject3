#include "Vector.h"
#include <stdexcept>

using namespace std;
template<typename T>
Vector<T>::Vector(int s)
{
	if (s < 0)
		throw std::length_error{ "Vector constructor:negative size" };
	elem = new T[s];
	space = elem;
	last = elem + s;
}

template<typename T>
Vector<T>::Vector(std::initializer_list<T> lst) : elem{new T[lst.size()]}
{
	int i = 0;
	for (const T& x : lst) {
		elem[i++] = x;
	}
	last = elem + s;
	space = last;
}

template<typename T>
T& Vector<T>::operator[](int i)
{
	if (i < 0 || size() <= i)
		throw std::out_of_range{ "Vector::operator[]" };
	
	return elem[i];
}

template<typename T>
int Vector<T>::size()
{
	return (int) (space - elem);
}

template<typename T>
int Vector<T>::capacity()
{
	return (int) (last - elem);
}

template<typename T>
void Vector<T>::reserve(int newsz)
{
	T* temp = new T[newsz];
	int sz = size();
	for (int i = 0; i < sz; i++)
	{
		temp[i] = elem[i];
	}
	delete[] elem;

	last = temp + newsz;
	space = temp + sz;
	elem = temp;
}

template<typename T>
Vector<T>::~Vector()
{

	delete[] elem;

}

//copy construct
template<typename T>
Vector<T>::Vector(const Vector<T>& a) : elem{new T[a.size()]}
{
	 for (int i = 0; i != a.size(); i++)
	 {
		 elem[i] = a.elem[i];
	 }
	 last = elem + a.size();
	 space = last;
}

//copy assignment
template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& a)
{
	T* p = new double[a.size()];
	for (int i = 0; i != a.size(); i++)
	{
		p[i] = a.elem[i];
	}
	delete[] elem;
	elem = p;
	last = elem + a.size();
	space = last;
	return *this;
}

//move construct
template<typename T>
Vector<T>::Vector(Vector&& a) : elem{a.elem}
{
	last = elem + a.size();
	space = last;
	a.elem = nullptr;
	a.space = nullptr;
	a.last = nullptr;
}

//move assignment
template<typename T>
Vector<T>& Vector<T>::operator=(Vector&& a)
{
	T* p = new double[a.size()];
	for (int i = 0; i != a.size(); i++)
	{
		p[i] = a.elem[i];
	}
	delete[] elem;
	elem = p;
	last = elem + a.size();
	space = last;
	a.elem = nullptr;
	a.space = nullptr;
	a.last = nullptr;
	return *this;
}

template<typename T>
void Vector<T>::push_back(const T& t)
{
	if (capacity() < size() + 1) {
		reserve(size() == 0 ? 8 : 2 * size());
	} 
	new(space) T{ t };
	++space;
}








