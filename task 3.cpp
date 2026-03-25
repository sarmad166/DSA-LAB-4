//#include <iostream>
//using namespace std;
//
//// Queue ko array ke through implement kiya gaya hai
//class Queue {
//private:
//    int* arr;
//    int front, rear, size, capacity;
//
//public:
//    Queue(int cap) {
//        capacity = cap;
//        arr = new int[capacity];
//        front = 0;
//        rear = -1;
//        size = 0;
//    }
//
//    ~Queue() {
//        delete[] arr;
//    }
//
//    bool isEmpty() {
//        return (size == 0);
//    }
//
//    bool isFull() {
//        return (size == capacity);
//    }
//
//    // Enqueue function element ko queue ke end (rear) par add karta hai
//    void enqueue(int x) {
//        if (isFull()) {
//            cout << "Queue is Full!\n";
//            return;
//        }
//        rear = (rear + 1) % capacity;
//        arr[rear] = x;
//        size++;
//    }
//
//    // Dequeue function front element ko remove karta hai
//    int dequeue() {
//        if (isEmpty()) {
//            cout << "Queue is Empty!\n";
//            return -1;
//        }
//        int val = arr[front];
//        front = (front + 1) % capacity;
//        size--;
//        return val;
//    }
//
//    int getFront() {
//        if (isEmpty()) {
//            cout << "Queue is Empty!\n";
//            return -1;
//        }
//        return arr[front];
//    }
//
//    int getSize() {
//        return size;
//    }
//
//    void display() {
//        if (isEmpty()) {
//            cout << "Queue is Empty!\n";
//            return;
//        }
//
//        int i = front;
//        for (int count = 0; count < size; count++) {
//            cout << arr[i] << " ";
//            i = (i + 1) % capacity;
//        }
//        cout << endl;
//    }
//
//    // reverseK function first K elements ko reverse karta hai using stack
//    void reverseK(int k) {
//        if (k <= 1 || isEmpty()) return;
//
//        if (k > size) k = size;
//
//        int* stack = new int[k];
//        int top = -1;
//
//        for (int i = 0; i < k; i++) {
//            stack[++top] = dequeue();
//        }
//
//        while (top != -1) {
//            enqueue(stack[top--]);
//        }
//
//        // Remaining elements ko rotate kiya jata hai taake unka order same rahe
//        int remaining = size - k;
//        for (int i = 0; i < remaining; i++) {
//            enqueue(dequeue());
//        }
//
//        delete[] stack;
//    }
//};
//
//int main() {
//    int n, x, k;
//
//    cout << "Enter number of elements: ";
//    cin >> n;
//
//    Queue q(n);
//
//    cout << "Enter elements:\n";
//    for (int i = 0; i < n; i++) {
//        cin >> x;
//        q.enqueue(x);
//    }
//
//    cout << "Queue: ";
//    q.display();
//
//    cout << "Enter K: ";
//    cin >> k;
//
//    q.reverseK(k);
//
//    cout << "Output: ";
//    q.display();
//
//    return 0;
//}