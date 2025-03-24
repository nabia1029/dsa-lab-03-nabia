#include "ArrayList.h"

int main() {
	ArrayList<int> myList(5);

	myList.addElementAtLastIndex(10);
	myList.addElementAtLastIndex(20);
	myList.addElementAtFirstIndex(5);

	cout << "Current Size: " << myList.getCurrentSize() << endl;
	cout << "Element at index 0: " << myList.getElementAtIndex(0) << endl;
	cout << "Element at index 1: " << myList.getElementAtIndex(1) << endl;
	cout << "Element at index 2: " << myList.getElementAtIndex(2) << endl;

	cout << "Removed from end: " << myList.removeElementFromEnd() << endl;
	myList.removeElementFromStart();

	cout << "Current Size after removes: " << myList.getCurrentSize() << endl;
	system("pause");
	return 0;
}