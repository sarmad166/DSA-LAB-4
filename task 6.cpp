#include <iostream>
using namespace std;

// Package structure
struct Package {
    int id;
    string address;
    int startTime;
    int endTime;
};

class DeliveryQueue {
private:
    Package* arr;
    int front, rear, size, capacity;

public:
    DeliveryQueue(int cap) {
        capacity = cap;
        arr = new Package[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    ~DeliveryQueue() {
        delete[] arr;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    // Add package
    void enqueue(Package p) {
        if (isFull()) {
            cout << "Queue is Full!\n";
            return;
        }

        rear = (rear + 1) % capacity;
        arr[rear] = p;
        size++;

        cout << "Package " << p.id << " added.\n";
    }

    // Remove package
    void dequeue() {
        if (isEmpty()) {
            cout << "No packages.\n";
            return;
        }

        cout << "Delivered Package ID: " << arr[front].id << endl;
        front = (front + 1) % capacity;
        size--;
    }

    // Show front
    void frontPackage() {
        if (isEmpty()) {
            cout << "No packages.\n";
            return;
        }

        Package p = arr[front];
        cout << "Front Package -> ID: " << p.id
            << ", Address: " << p.address
            << ", Time: " << p.startTime << "-" << p.endTime << endl;
    }

    // Check delivery time
    void timeToDeliver(int currentTime) {
        while (!isEmpty()) {
            Package p = arr[front];

            if (currentTime > p.endTime) {
                cout << "Package " << p.id << " expired!\n";
                front = (front + 1) % capacity;
                size--;
            }
            else {
                cout << "Package " << p.id << " can be delivered.\n";
                break;
            }
        }
    }

    // Display all
    void display() {
        if (isEmpty()) {
            cout << "No packages in queue.\n";
            return;
        }

        cout << "Packages in Queue:\n";
        int i = front;

        for (int count = 0; count < size; count++) {
            Package p = arr[i];

            cout << "ID: " << p.id
                << ", Address: " << p.address
                << ", Time: " << p.startTime << "-" << p.endTime << endl;

            i = (i + 1) % capacity;
        }
    }
};

int main() {
    int n;
    cout << "Enter queue capacity: ";
    cin >> n;

    DeliveryQueue dq(n);

    int choice;

    do {
        cout << "\n===== Delivery System =====\n";
        cout << "1. Add Package\n";
        cout << "2. Deliver Package\n";
        cout << "3. Check Front\n";
        cout << "4. Display All\n";
        cout << "5. Check Time\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            Package p;
            cout << "Enter ID: ";
            cin >> p.id;
            cout << "Enter Address: ";
            cin >> p.address;
            cout << "Start Time: ";
            cin >> p.startTime;
            cout << "End Time: ";
            cin >> p.endTime;

            dq.enqueue(p);
            break;
        }

        case 2:
            dq.dequeue();
            break;

        case 3:
            dq.frontPackage();
            break;

        case 4:
            dq.display();
            break;

        case 5: {
            int currentTime;
            cout << "Enter current time: ";
            cin >> currentTime;
            dq.timeToDeliver(currentTime);
            break;
        }

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}