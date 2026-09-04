#include <iostream>

class CircularQueue {
private:
    int* arr;
    int front;
    int rear;
    int capacity;

public:
    // Constructor
    CircularQueue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = -1;
        rear = -1;
    }

    // Destructor to free dynamically allocated memory
    ~CircularQueue() {
        delete[] arr;
    }

    // Check if queue is full
    bool isFull() const {
        return (rear + 1) % capacity == front;
    }

    // Check if queue is empty
    bool isEmpty() const {
        return front == -1;
    }

    // Insert an element (Enqueue)
    void enqueue(int value) {
        if (isFull()) {
            std::cout << "Queue Overflow: Cannot enqueue " << value << "\n";
            return;
        }

        if (isEmpty()) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }

        arr[rear] = value;
        std::cout << "Enqueued: " << value << "\n";
    }

    // Remove an element (Dequeue)
    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue Underflow: Queue is empty\n";
            return;
        }

        std::cout << "Dequeued: " << arr[front] << "\n";

        // If only one element was left, reset the queue
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
    }

    // Get the front element
    void peek() const {
        if (isEmpty()) {
            std::cout << "Queue is empty\n";
            return;
        }
        std::cout << "Front element: " << arr[front] << "\n";
    }

    // Display elements of the queue
    void display() const {
        if (isEmpty()) {
            std::cout << "Queue is empty\n";
            return;
        }

        std::cout << "Queue elements: ";
        int i = front;
        while (true) {
            std::cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % capacity;
        }
        std::cout << "\n";
    }
};

int main() {
    CircularQueue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50); // Queue is now full
    q.display();

    q.enqueue(60); // Should trigger overflow

    q.dequeue();
    q.dequeue();
    q.display();

    q.enqueue(60); // Takes advantage of wrapped space
    q.enqueue(70);
    q.display();

    q.peek();

    return 0;
}