#include <iostream>
using namespace std;

class CircularLinkedList {
private:
    struct Node {
        int data;
        Node* next;

        Node(int value) : data(value), next(nullptr) {}
    };

    Node* tail = nullptr;

public:
    // Insert a node at the end
    void insert(int value) {
        Node* newNode = new Node(value);

        if (tail == nullptr) {
            tail = newNode;
            tail->next = tail;  // Points to itself
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Delete the first node containing the given value
    void remove(int value) {
        if (tail == nullptr)
            return;

        Node* current = tail->next;
        Node* previous = tail;

        do {
            if (current->data == value) {
                // Only one node in the list
                if (current == tail && current->next == tail) {
                    delete current;
                    tail = nullptr;
                } else {
                    previous->next = current->next;

                    if (current == tail)
                        tail = previous;

                    delete current;
                }
                return;
            }

            previous = current;
            current = current->next;

        } while (current != tail->next);
    }

    // Display the list
    void display() const {
        if (tail == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = tail->next; // Head node

        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != tail->next);

        cout << endl;
    }

    // Destructor
    ~CircularLinkedList() {
        if (tail == nullptr)
            return;

        Node* head = tail->next;
        tail->next = nullptr; // Break the circle

        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    CircularLinkedList list;

    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);

    cout << "Circular linked list: ";
    list.display();

    list.remove(20);

    cout << "After deleting 20: ";
    list.display();

    list.remove(40);

    cout << "After deleting 40: ";
    list.display();

    return 0;
}
