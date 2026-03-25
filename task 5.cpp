#include <iostream>
using namespace std;

class PrintQueue {
private:
    string* arr;
    int front, rear, size, capacity;

public:
    // Constructor
    PrintQueue(int cap) {
        capacity = cap;
        arr = new string[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    // Destructor
    ~PrintQueue() {
        delete[] arr;
    }

    bool isEmpty() {
        return (size == 0);
    }

    bool isFull() {
        return (size == capacity);
    }

    // Add new print job
    void enqueue(string document_name) {
        if (isFull()) {
            cout << "Print Queue is Full!\n";
            return;
        }

        rear = (rear + 1) % capacity;
        arr[rear] = document_name;
        size++;

        cout << "Document \"" << document_name << "\" added to queue.\n";
    }

    // Print (remove) document
    void dequeue() {
        if (isEmpty()) {
            cout << "No documents to print.\n";
            return;
        }

        cout << "Printing: " << arr[front] << endl;
        front = (front + 1) % capacity;
        size--;
    }

    // Show front document
    void frontDoc() {
        if (isEmpty()) {
            cout << "No documents in queue.\n";
            return;
        }

        cout << "Next Document: " << arr[front] << endl;
    }

    // Display all documents
    void display() {
        if (isEmpty()) {
            cout << "No pending print jobs.\n";
            return;
        }

        cout << "Print Queue: ";
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

    PrintQueue pq(n);

    int choice;
    string name;

    do {
        cout << "\n===== Printer Menu =====\n";
        cout << "1. Add Print Job\n";
        cout << "2. Print Document\n";
        cout << "3. Check Next Document\n";
        cout << "4. Display Queue\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter document name: ";
            cin >> name;
            pq.enqueue(name);
            break;

        case 2:
            pq.dequeue();
            break;

        case 3:
            pq.frontDoc();
            break;

        case 4:
            pq.display();
            break;

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}