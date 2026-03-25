//#include <iostream>
//using namespace std;
//
//
//template <typename T>
//class AbstractQueue {
//public:
//    virtual void enQueue(T value) = 0;
//    virtual T deQueue() = 0;
//    virtual T front() const = 0;
//    virtual bool isEmpty() const = 0;
//    virtual bool isFull() const = 0;
//    virtual ~AbstractQueue() {}
//};
//
//
//template <typename T>
//class myQueue : public AbstractQueue<T> {
//private:
//    T* arr;
//    int frontIndex;
//    int rearIndex;
//    int maxSize;
//
//public:
//    
//    myQueue(int size) {
//        maxSize = size;
//        arr = new T[maxSize];
//        frontIndex = -1;
//        rearIndex = -1;
//    }
//
//    
//    ~myQueue() {
//        delete[] arr;
//    }
//
//    
//    void enQueue(T value) {
//        if (isFull()) {
//            cout << "Queue is Full!\n";
//            return;
//        }
//
//        if (isEmpty()) {
//            frontIndex = 0;
//        }
//
//        rearIndex++;
//        arr[rearIndex] = value;
//        cout << "Inserted: " << value << endl;
//    }
//
//    
//    T deQueue() {
//        if (isEmpty()) {
//            cout << "Queue is Empty!\n";
//            return T(); 
//        }
//
//        T removed = arr[frontIndex];
//        frontIndex++;
//
//        if (frontIndex > rearIndex) {
//            frontIndex = rearIndex = -1;
//        }
//
//        return removed;
//    }
//
//    
//    T front() const {
//        if (isEmpty()) {
//            cout << "Queue is Empty!\n";
//            return T();
//        }
//        return arr[frontIndex];
//    }
//
//   
//    bool isEmpty() const {
//        return (frontIndex == -1);
//    }
//
//    
//    bool isFull() const {
//        return (rearIndex == maxSize - 1);
//    }
//
//    
//    void display() const {
//        if (isEmpty()) {
//            cout << "Queue is Empty!\n";
//            return;
//        }
//
//        cout << "Queue elements: ";
//        for (int i = frontIndex; i <= rearIndex; i++) {
//            cout << arr[i] << " ";
//        }
//        cout << endl;
//    }
//};
//
//
//int main() {
//    int size;
//    cout << "Enter size of queue: ";
//    cin >> size;
//
//    myQueue<int> q(size);
//
//    int choice, value;
//
//    do {
//        cout << "\n===== Queue Menu =====\n";
//        cout << "1. Enqueue\n";
//        cout << "2. Dequeue\n";
//        cout << "3. Front\n";
//        cout << "4. Display\n";
//        cout << "5. Check Empty\n";
//        cout << "6. Check Full\n";
//        cout << "0. Exit\n";
//        cout << "Enter choice: ";
//        cin >> choice;
//
//        switch (choice) {
//        case 1:
//            cout << "Enter value: ";
//            cin >> value;
//            q.enQueue(value);
//            break;
//
//        case 2:
//            cout << "Removed: " << q.deQueue() << endl;
//            break;
//
//        case 3:
//            cout << "Front element: " << q.front() << endl;
//            break;
//
//        case 4:
//            q.display();
//            break;
//
//        case 5:
//            cout << (q.isEmpty() ? "Queue is Empty\n" : "Queue is NOT Empty\n");
//            break;
//
//        case 6:
//            cout << (q.isFull() ? "Queue is Full\n" : "Queue is NOT Full\n");
//            break;
//
//        case 0:
//            cout << "Exiting...\n";
//            break;
//
//        default:
//            cout << "Invalid choice!\n";
//        }
//
//    } while (choice != 0);
//
//    return 0;
//}