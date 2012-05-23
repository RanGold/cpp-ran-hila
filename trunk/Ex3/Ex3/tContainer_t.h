#include "IndexOutOfBoundsException.h"
#include <iostream>
#include <algorithm>
using namespace std;

template <class T>
struct eq {
	eq(const T* compareTo) : _compareTo(compareTo) {}
	bool operator()(T * currentVal) const { return  *currentVal == *_compareTo; }
private:
	const T* _compareTo;
};

template <class T, template <class T1, class = allocator<T1>> class Cont>
class tContainer_t {

public:
	tContainer_t() {}
	virtual ~tContainer_t() {}

	bool empty() const { return _container.empty(); }
	size_t size() const { return _container.size(); }
	void push_back(const T& val) { _container.push_back((T*)&val); }
	void push_back(const T *val) { _container.push_back((T*)val); }
	T& front() { return *(_container.front()); }
	const T& front() const { return *(_container.front()); }
	T& back() { return *(_container.back()); }
	const T& back() const { return *(_container.back()); }
	
	T* find(const T& compareToElement) const { 
		const_iter_t& iter = internalFind(compareToElement);
		return (iter != _container.end() ? *iter : 0);
	}

	T* remove(const T& removeElement) {
		const_iter_t& iter = internalFind(removeElement);
		if (iter == _container.end()){
			return 0;
		} else {
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

	void clearAndDeleteElements() {
		const_iter_t& iter = _container.begin();

		for (;iter != _container.end(); iter++) {
			delete *iter;
		}

		_container.clear();
	}

	T& operator[](unsigned int index) const {
		if (index >= this->size()) {
			throw IndexOutOfBoundsException("tContainer_t::operator[] : index out of range");
		} else if (typeid(_container) == typeid(vector<T*>)) {
			return *((*((vector<T*>*)((void*)&_container)))[index]);
		} else {
			const_iter_t& iter = _container.begin();
			int i = 0;
			for (;iter != _container.end(); iter++) {
				if (i == index) {
					break;
				}

				i++;
			}

			return **iter;
		}
	}

	void print() const { 
		cout << "tContainer_t:" << endl;
		const_iter_t& iter = _container.begin();
		for (;iter != _container.end(); iter++) {
			cout << '\t' << **iter << endl;
		}

		cout << endl;
	}

private:
	Cont<T*> _container;
	typedef typename Cont<T*>::const_iterator	const_iter_t;
	typedef typename Cont<T*>::iterator			iter_t;

	tContainer_t(const tContainer_t& cont);
	const tContainer_t& operator=(const tContainer_t& cont);

	const_iter_t internalFind(const T& compareToValue) const {
		const_iter_t& iter = _container.begin();
		iter = find_if(iter, _container.end(), eq<T>(&compareToValue));
		return iter;
	}
};