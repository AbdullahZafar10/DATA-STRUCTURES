#include <iostream>
using namespace std;

class Queue {
private:
    int arr[100];
    int front, rear;

public:
    Queue() {
        front = 0;
        rear = -1;
    }
    void enqueue(int value) {
        rear++;
        arr[rear] = value;
    }
    int dequeue() {
        return arr[front++];
    }
    int getFront() {
        return arr[front];
    }
    bool isEmpty() {
        return front > rear;
    }
    void display() {
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void reverseK(int k) {
        if (k <= 1 || isEmpty()) {
            return;
        }

        int size = rear - front + 1;

        if (k > size) {
            k = size;
        }

        int stack[100];
        int top = -1;
        for (int i = 0; i < k; i++) {
            stack[++top] = dequeue();
        }

        while (top != -1) {
            enqueue(stack[top--]);
        }

        int remaining = size - k;

        for (int i = 0; i < remaining; i++) {
            enqueue(dequeue());
        }
    }
};
int main() {
    Queue q;

    int n, value, k;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter queue elements:\n";

    for (int i = 0; i < n; i++) {
        cin >> value;
        q.enqueue(value);
    }

    cout << "Original Queue: ";
    q.display();

    cout << "Enter K: ";
    cin >> k;

    q.reverseK(k);

    cout << "Reversed Queue: ";
    q.display();

    return 0;
}
