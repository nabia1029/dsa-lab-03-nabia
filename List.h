#include <iostream>
using namespace std;

template <typename Type>
class List {
protected:
	Type* arr;
	int maxSize;
	int currentSize;

public:
	// Parameterized constructor with default arguments
	List(int size = 10) : maxSize(size), currentSize(0), arr(new Type[maxSize]) {}
	List(const List& other) : maxSize(other.maxSize), currentSize(other.currentSize), arr(new Type[other.maxSize]) {
		for (int i = 0; i < currentSize; ++i) {
			arr[i] = other.arr[i];
		}
	}
	virtual ~List() {
		delete[] arr;
	}

	// Abstract functions
	virtual void addElementAtFirstIndex(Type element) = 0;
	virtual void addElementAtLastIndex(Type element) = 0;
	virtual Type removeElementFromEnd() = 0;
	virtual void removeElementFromStart() = 0;
	int getCurrentSize() const {
		return currentSize;
	}

	int getMaxSize() const {
		return maxSize;
	}

	Type getElementAtIndex(int index) const {
		if (index < 0 || index >= currentSize) {
			cout << "Index out of range" << endl;
			return Type();
		}
		return arr[index];
	}
};