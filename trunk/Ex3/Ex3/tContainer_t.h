#include "IndexOutOfBoundsException.h"
#include <iostream>
#include <algorithm>
using namespace std;

template <class T>
struct eq {
	eq(const T* compare_to) : compare_to_(compare_to) {}
	bool operator()(T * currentVal) const { return  *currentVal == *_compareTo; }
private:
	const T* _compareTo;
};

template <class T, template <class T1, class = allocator<T1>> class Cont>
class tContainer_t {
private:
	Cont<T*> _container; //TODO remove the data member from public part
	typedef typename Cont<T*>::const_iterator	const_iter_t;
	typedef typename Cont<T*>::iterator	iter_t;

	tContainer_t(const tContainer_t& cont);
	const tContainer_t& operator=(const tContainer_t& cont);

	const_iter_t internalFind(const T& compareToValue) {
		const_iter_t& iter = _container.begin();
		iter = find_if(iter, _container.end(), eq(&compareToVal));
		return iter;
	}

public:
	tContainer_t() {}
	virtual ~tContainer_t() {}

	bool empty( ) const { return _container.empty(); }
	size_t size( ) const { return _container.size(); }
	void push_back(const T& val) { _container.push_back(&val); }
	T& front() { return *(_container.front()); }
	const T& front() const { return *(_container.front()); }
	T& back() { return *(_container.back()); }
	const T& back() const { return *(_container.back()); }
	
	T* find(const T& compareToElement) const { 
		const_iter_t iter& = internalFind(compareToElement);
		return (iter != _container.end() ? *iter : 0);
	}

	T* remove(const T& removeElement) {
		const_iter_t& iter = internalFind(removeElement);
		if (iter == _container.end()){
			return 0;
		} else {
			// TODO : check what happends when T*&
			T* element = *iter;
			_container.erase(iter);
			return element;
		}
	}

	bool removeAndDelete(const T& removeElement) {
		const_iter_t& iter = internalFind(removeElement);
		if (iter == _container.end()) {
			return false;
		} else {
			T* element = *iter;
			_container.erase(iter);
			delete element;
			return true;
		}
	}

	void clear() {
		_container.clear();
	}

	T& operator[](int index) const {

		if (index >= _container.size()) {
			throw IndexOutOfBoundsException;
		} else if (typeid(_container) == typeid(vector<T*>)) {
			return _container[index];
		} else {
			const_iter_t& iter = _container.begin();
			int i = 0;
			for (;iter != _container.end(); iter++){
				if (i == index){
					break;
				}
				i++;
			}

			return **iter;
		}
	}	
};