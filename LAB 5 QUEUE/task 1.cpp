#include <iostream>
using namespace std;

template <typename T>
class AbstractQueue {
public:
    virtual void enQueue(T value) = 0;
    virtual T deQueue() = 0;
    virtual T front() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;

    virtual ~AbstractQueue() {}
};
template <typename T>
class myQueue : public AbstractQueue<T> {
private:
    T* arr;
    int size;
    int count;

public:
    myQueue(int s) {
        size = s;
        arr = new T[size];
        count = 0;
    }
    void enQueue(T value) override {
        if (isFull()) {
            cout << "Queue is Full!\n";
        }
        else {
            arr[count] = value;
            count++;
            cout << "Element inserted.\n";
        }
    }
    T deQueue() override {
        if (isEmpty()) {
            cout << "Queue is Empty!\n";
            return T();
        }

        T value = arr[0];

        for (int i = 0; i < count - 1; i++) {
            arr[i] = arr[i + 1];
        }

        count--;
        return value;
    }
    T front() const override {
        if (isEmpty()) {
            cout << "Queue is Empty!\n";
            return T();
        }

        return arr[0];
    }
    bool isEmpty() const override {
        return count == 0;
    }
    bool isFull() const override {
        return count == size;
    }
    void display() const {
        if (isEmpty()) {
            cout << "Queue is Empty!\n";
        }
        else {
            cout << "Queue elements: ";

            for (int i = 0; i < count; i++) {
                cout << arr[i] << " ";
            }

            cout << endl;
        }
    }
    ~myQueue() {
        delete[] arr;
    }
};

int main() {
    myQueue<int> q(5);
    int choice, value;

    do {
        cout << "\n===== QUEUE MENU =====\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Front\n";
        cout << "4. Display\n";
        cout << "5. Is Empty\n";
        cout << "6. Is Full\n";
        cout << "7. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            q.enQueue(value);
            break;

        case 2:
            if (!q.isEmpty())
                cout << "Deleted: " << q.deQueue() << endl;
            else
                cout << "Queue is Empty!\n";
            break;

        case 3:
            if (!q.isEmpty())
                cout << "Front element: " << q.front() << endl;
            else
                cout << "Queue is Empty!\n";
            break;

        case 4:
            q.display();
            break;

        case 5:
            if (q.isEmpty())
                cout << "Queue is Empty.\n";
            else
                cout << "Queue is Not Empty.\n";
            break;

        case 6:
            if (q.isFull())
                cout << "Queue is Full.\n";
            else
                cout << "Queue is Not Full.\n";
            break;

        case 7:
            cout << "Goodbye!\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 7);

    return 0;
}
