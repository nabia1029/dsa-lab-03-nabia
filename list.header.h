#include "List.h"

template <typename Type>
class ArrayList : public List<Type> {
public:
	ArrayList(int size = 10) : List<Type>(size) {}

	void addElementAtFirstIndex(Type element) override {
		if (this->currentSize == this->maxSize) {
			cout << "List is full." << endl;
			return;
		}
		for (int i = this->currentSize; i > 0; --i) {
			this->arr[i] = this->arr[i - 1];
		}
		this->arr[0] = element;
		this->currentSize++;
	}

	void addElementAtLastIndex(Type element) override {
		if (this->currentSize == this->maxSize) {
			cout << "List is full." << endl;
			return;
		}
		this->arr[this->currentSize++] = element;
	}

	Type removeElementFromEnd() override {
		if (this->currentSize == 0) {
			cout << "List is empty." << endl;
			return Type();
		}
		return this->arr[--this->currentSize];
	}

	void removeElementFromStart() override {
		if (this->currentSize == 0) {
			cout << "List is empty." << endl;
			return;
		}
		for (int i = 0; i < this->currentSize - 1; ++i) {
			this->arr[i] = this->arr[i + 1];
		}
		this->currentSize--;
	}
};

