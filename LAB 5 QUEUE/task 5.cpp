#include <iostream>
#include <string>
using namespace std;

class Queue {
private:
    string documents[100];
    int front, rear;

public:
    Queue() {
        front = 0;
        rear = -1;
    }
    void enqueue(string name) {
        if (rear == 99) {
            cout << "Print Queue is Full!\n";
        }
        else {
            rear++;
            documents[rear] = name;
            cout << "Document Added Successfully!\n";
        }
    }
    void dequeue() {
        if (front > rear) {
            cout << "Print Queue is Empty!\n";
        }
        else {
            cout << "Printing Document: "
                << documents[front] << endl;
            front++;
        }
    }
    void frontDocument() {
        if (front > rear) {
            cout << "Print Queue is Empty!\n";
        }
        else {
            cout << "Next Document: "
                << documents[front] << endl;
        }
    }
    void display() {
        if (front > rear) {
            cout << "Print Queue is Empty!\n";
        }
        else {
            cout << "Pending Documents:\n";

            for (int i = front; i <= rear; i++) {
                cout << documents[i] << endl;
            }
        }
    }
};
int main() {
    Queue q;
    int choice;
    string name;

    do {
        cout << "\n===== DOCUMENT PRINTING SYSTEM =====\n";
        cout << "1. Add Print Job\n";
        cout << "2. Print Document\n";
        cout << "3. Next Document\n";
        cout << "4. Display Documents\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter Document Name: ";
            cin.ignore();
            getline(cin, name);
            q.enqueue(name);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.frontDocument();
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
