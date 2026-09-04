#include <iostream>
using namespace std;

class SinglyLinkedList {
private:
    struct Node {
        int data;
        Node* next;

        Node(int value) : data(value), next(nullptr) {}
    };

    Node* head = nullptr;

public:
    // Insert a node at the end
    void insert(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* current = head;

        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = newNode;
    }

    // Delete the first node containing the given value
    void remove(int value) {
        if (head == nullptr)
            return;

        // If the head contains the value
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;

        while (current->next != nullptr &&
               current->next->data != value) {
            current = current->next;
        }

        // Value found
        if (current->next != nullptr) {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
        }
    }

    // Display the list
    void display() const {
        Node* current = head;

        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }

        cout << "NULL" << endl;
    }

    // Destructor
    ~SinglyLinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    SinglyLinkedList list;

    // Insert elements
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);

    cout << "Singly linked list: ";
    list.display();

    // Delete an element
    list.remove(20);

    cout << "After deleting 20: ";
    list.display();

    list.remove(40);

    cout << "After deleting 40: ";
    list.display();

    return 0;
}
