#include <iostream>
using namespace std;

class Queue {
private:
    int s1[100], s2[100];
    int top1, top2;

public:
    Queue() {
        top1 = -1;
        top2 = -1;
    }
    void enQueue(int value) {
        top1++;
        s1[top1] = value;
        cout << "Element Inserted!\n";
    }
    int deQueue() {
        if (top1 == -1 && top2 == -1) {
            cout << "Queue is Empty!\n";
            return -1;
        }
        if (top2 == -1) {
            while (top1 != -1) {
                top2++;
                s2[top2] = s1[top1];
                top1--;
            }
        }
        int value = s2[top2];
        top2--;
        return value;
    }
    int front() {
        if (top1 == -1 && top2 == -1) {
            cout << "Queue is Empty!\n";
            return -1;
        }

        if (top2 == -1) {
            while (top1 != -1) {
                top2++;
                s2[top2] = s1[top1];
                top1--;
            }
        }

        return s2[top2];
    }
    void display() {
        if (top1 == -1 && top2 == -1) {
            cout << "Queue is Empty!\n";
            return;
        }

        cout << "Queue Elements: ";

        for (int i = top2; i >= 0; i--) {
            cout << s2[i] << " ";
        }

        for (int i = 0; i <= top1; i++) {
            cout << s1[i] << " ";
        }

        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\n===== QUEUE MENU =====\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Front\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter value: ";
            cin >> value;
            q.enQueue(value);
            break;

        case 2:
            cout << "Deleted Element: " << q.deQueue() << endl;
            break;

        case 3:
            cout << "Front Element: " << q.front() << endl;
            break;

        case 4:
            q.display();
            break;

        case 5:
            cout << "Program Ended!\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 5);

    return 0;
}
