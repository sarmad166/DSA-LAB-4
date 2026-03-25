#include <iostream>
using namespace std;

class TicketQueue {
private:
    int* arr;
    int front, rear, size, capacity;

public:
    // Constructor
    TicketQueue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    // Destructor
    ~TicketQueue() {
        delete[] arr;
    }

    bool isEmpty() {
        return (size == 0);
    }

    bool isFull() {
        return (size == capacity);
    }

    // Add new ticket
    void enqueue(int ticket_id) {
        if (isFull()) {
            cout << "Queue is Full! Cannot add more tickets.\n";
            return;
        }

        if (ticket_id < 1000 || ticket_id > 9999) {
            cout << "Invalid Ticket ID! Enter 4-digit number.\n";
            return;
        }

        rear = (rear + 1) % capacity;
        arr[rear] = ticket_id;
        size++;

        cout << "Ticket " << ticket_id << " added.\n";
    }

    // Resolve ticket
    void dequeue() {
        if (isEmpty()) {
            cout << "No tickets to resolve.\n";
            return;
        }

        cout << "Ticket " << arr[front] << " resolved.\n";
        front = (front + 1) % capacity;
        size--;
    }

    // Show front ticket
    void frontTicket() {
        if (isEmpty()) {
            cout << "No pending tickets.\n";
            return;
        }

        cout << "Next Ticket: " << arr[front] << endl;
    }

    // Display all tickets
    void display() {
        if (isEmpty()) {
            cout << "No pending tickets.\n";
            return;
        }

        cout << "Pending Tickets: ";
        int i = front;

        for (int count = 0; count < size; count++) {
            cout << arr[i] << " ";
            i = (i + 1) % capacity;
        }
        cout << endl;
    }
};

int main() {
    int n;
    cout << "Enter queue capacity: ";
    cin >> n;

    TicketQueue tq(n);

    int choice, id;

    do {
        cout << "\n===== Customer Support Menu =====\n";
        cout << "1. Add Ticket\n";
        cout << "2. Resolve Ticket\n";
        cout << "3. Next Ticket\n";
        cout << "4. Display Tickets\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter 4-digit Ticket ID: ";
            cin >> id;
            tq.enqueue(id);
            break;

        case 2:
            tq.dequeue();
            break;

        case 3:
            tq.frontTicket();
            break;

        case 4:
            tq.display();
            break;

        case 0:
            cout << "Exiting system...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}