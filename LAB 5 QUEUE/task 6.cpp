#include <iostream>
using namespace std;

struct Package {
    int id;
    char address[50];
    int startTime;
    int endTime;
};

class Queue {
private:
    Package arr[100];
    int front, rear;

public:
    Queue() {
        front = 0;
        rear = -1;
    }
    void enqueue(int id, char address[], int start, int end) {
        if (rear == 99) {
            cout << "Queue is Full!\n";
        }
        else {
            rear++;

            arr[rear].id = id;

            int i = 0;
            while (address[i] != '\0') {
                arr[rear].address[i] = address[i];
                i++;
            }
            arr[rear].address[i] = '\0';

            arr[rear].startTime = start;
            arr[rear].endTime = end;

            cout << "Package Added Successfully!\n";
        }
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty!\n";
        }
        else {
            cout << "Package Delivered: "
                << arr[front].id << endl;
            front++;
        }
    }
    void frontPackage() {
        if (isEmpty()) {
            cout << "Queue is Empty!\n";
        }
        else {
            cout << "\nPackage ID: " << arr[front].id;
            cout << "\nAddress: " << arr[front].address;
            cout << "\nStart Time: " << arr[front].startTime;
            cout << "\nEnd Time: " << arr[front].endTime << endl;
        }
    }
    bool isEmpty() {
        return front > rear;
    }
    void display() {
        if (isEmpty()) {
            cout << "No Packages Available!\n";
        }
        else {
            for (int i = front; i <= rear; i++) {
                cout << "\nPackage ID: " << arr[i].id;
                cout << "\nAddress: " << arr[i].address;
                cout << "\nTime Window: "
                    << arr[i].startTime << " - "
                    << arr[i].endTime << endl;
            }
        }
    }
    void timeToDeliver(int currentTime) {
        if (isEmpty()) {
            cout << "No Packages Available!\n";
            return;
        }

        while (!isEmpty() &&
            currentTime > arr[front].endTime) {

            cout << "Package Expired: "
                << arr[front].id << endl;

            front++;
        }

        if (isEmpty()) {
            cout << "No Packages Left!\n";
        }
        else if (currentTime < arr[front].startTime) {
            cout << "Package is Not Ready Yet!\n";
        }
        else {
            cout << "Package Can Be Delivered Now!\n";
            cout << "Package ID: " << arr[front].id << endl;
        }
    }
};
int main() {
    Queue q;

    int choice, id, start, end, currentTime;
    char address[50];

    do {
        cout << "\n===== PACKAGE DELIVERY SYSTEM =====\n";
        cout << "1. Add Package\n";
        cout << "2. Deliver Package\n";
        cout << "3. Front Package\n";
        cout << "4. Display Packages\n";
        cout << "5. Check Delivery Time\n";
        cout << "6. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter Package ID: ";
            cin >> id;

            cout << "Enter Address (use underscores for spaces): ";
            cin >> address;

            cout << "Enter Start Time (0-23): ";
            cin >> start;

            cout << "Enter End Time (0-23): ";
            cin >> end;

            q.enqueue(id, address, start, end);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.frontPackage();
            break;

        case 4:
            q.display();
            break;

        case 5:
            cout << "Enter Current Time (0-23): ";
            cin >> currentTime;

            q.timeToDeliver(currentTime);
            break;

        case 6:
            cout << "Program Ended!\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 6);

    return 0;
}
