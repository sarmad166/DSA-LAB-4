#include <iostream>
#include <stack>
using namespace std;

class QueueUsingStacks {
private:
    stack<int> s1, s2;

public:

    // Enqueue
    void enqueue(int x) {
        s1.push(x);
        cout << "Inserted: " << x << endl;
    }

    // Helper function to transfer
    void transfer() {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }

    // Dequeue
    int dequeue() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is Empty!\n";
            return -1;
        }

        if (s2.empty()) {
            transfer();
        }

        int val = s2.top();
        s2.pop();
        return val;
    }

    // Front element
    int front() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is Empty!\n";
            return -1;
        }

        if (s2.empty()) {
            transfer();
        }

        return s2.top();
    }

    // Display queue
    void display() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is Empty!\n";
            return;
        }

        stack<int> temp1 = s1;
        stack<int> temp2 = s2;

        // First print s2 (front side)
        cout << "Queue elements: ";
        while (!temp2.empty()) {
            cout << temp2.top() << " ";
            temp2.pop();
        }

        // Store s1 elements in another stack to reverse
        stack<int> temp3;
        while (!temp1.empty()) {
            temp3.push(temp1.top());
            temp1.pop();
        }

        while (!temp3.empty()) {
            cout << temp3.top() << " ";
            temp3.pop();
        }

        cout << endl;
    }
};

// Main function with menu
int main() {
    QueueUsingStacks q;
    int choice, value;

    do {
        cout << "\n===== Queue using Stacks Menu =====\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Front\n";
        cout << "4. Display\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            q.enqueue(value);
            break;

        case 2:
            cout << "Removed: " << q.dequeue() << endl;
            break;

        case 3:
            cout << "Front: " << q.front() << endl;
            break;

        case 4:
            q.display();
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