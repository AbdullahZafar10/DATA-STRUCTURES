#include <iostream>
using namespace std;

class Queue {
private:
    int tickets[100];
    int front, rear;

public:
    Queue() {
        front = 0;
        rear = -1;
    }
    void enqueue(int ticket_id) {
        if (rear == 99) {
            cout << "Queue is Full!\n";
        }
        else {
            rear++;
            tickets[rear] = ticket_id;
            cout << "Ticket Added Successfully!\n";
        }
    }
    void dequeue() {
        if (front > rear) {
            cout << "No Pending Tickets!\n";
        }
        else {
            cout << "Ticket Removed: " << tickets[front] << endl;
            front++;
        }
    }

    void frontTicket() {
        if (front > rear) {
            cout << "No Pending Tickets!\n";
        }
        else {
            cout << "Next Ticket: " << tickets[front] << endl;
        }
    }
    void display() {
        if (front > rear) {
            cout << "No Pending Tickets!\n";
        }
        else {
            cout << "Pending Tickets: ";

            for (int i = front; i <= rear; i++) {
                cout << tickets[i] << " ";
            }

            cout << endl;
        }
    }
};
int main() {
    Queue q;
    int choice, ticket_id;

    do {
        cout << "\n===== CUSTOMER SUPPORT SYSTEM =====\n";
        cout << "1. Add New Ticket\n";
        cout << "2. Remove Ticket\n";
        cout << "3. Next Ticket\n";
        cout << "4. Display Tickets\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter 4-digit Ticket ID: ";
            cin >> ticket_id;

            if (ticket_id >= 1000 && ticket_id <= 9999) {
                q.enqueue(ticket_id);
            }
            else {
                cout << "Invalid Ticket ID! Enter 4 digits.\n";
            }
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.frontTicket();
            break;

        case 4:
            q.display();
            break;

        case 5:
            cout << "Program Ended.\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 5);

    return 0;
}
