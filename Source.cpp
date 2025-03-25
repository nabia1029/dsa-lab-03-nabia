#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

template <typename T>
class CustomList {
private:
    T* arr;
    int capacity;
    int count;

    bool isPrime(T num) {
        if (num < 2) return false;
        for (T i = 2; i * i <= num; i++) {
            if (num % i == 0) return false;
        }
        return true;
    }

public:
    CustomList(int size = MAX_SIZE) {
        capacity = size;
        count = 0;
        arr = new T[capacity];
    }

    CustomList(const CustomList& other) {
        capacity = other.capacity;
        count = other.count;
        arr = new T[capacity];
        for (int i = 0; i < count; i++) {
            arr[i] = other.arr[i];
        }
    }

    ~CustomList() {
        delete[] arr;
    }

    bool insert(T value) {
        if (count == capacity) return false;
        arr[count++] = value;
        return true;
    }

    T sum_ofPrime() {
        T sum = 0;
        for (int i = 0; i < count; i++) {
            if (isPrime(arr[i])) {
                sum += arr[i];
            }
        }
        return sum;
    }

    void display() {
        for (int i = 0; i < count; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    CustomList<int> customList;
    int choice, value;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert\n";
        cout << "2. Sum of Prime Numbers\n";
        cout << "3. Display List\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            if (customList.insert(value))
                cout << "Inserted successfully.\n";
            else
                cout << "Insertion failed.\n";
            break;
        case 2:
            cout << "Sum of Prime Numbers: " << customList.sum_ofPrime() << endl;
            break;
        case 3:
            customList.display();
            break;
        case 4:
            return 0;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    }
}
