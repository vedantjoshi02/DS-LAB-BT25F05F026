#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Insert a node at the end
void insertNode(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;

    // If the list is empty
    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
        return;
    }

    // Find the last node
    Node* temp = head;

    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
}

// Delete a node by value
void deleteNode(Node*& head, int value) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node* current = head;
    Node* previous = nullptr;

    // Case 1: Only one node
    if (head->next == head) {
        if (head->data == value) {
            delete head;
            head = nullptr;
            cout << "Node deleted.\n";
        } else {
            cout << "Value not found.\n";
        }
        return;
    }

    // Case 2: Delete head node
    if (head->data == value) {
        Node* last = head;

        while (last->next != head) {
            last = last->next;
        }

        current = head;
        head = head->next;
        last->next = head;

        delete current;
        cout << "Node deleted.\n";
        return;
    }

    // Case 3: Delete any other node
    current = head;

    do {
        previous = current;
        current = current->next;

        if (current->data == value) {
            previous->next = current->next;
            delete current;
            cout << "Node deleted.\n";
            return;
        }

    } while (current != head);

    cout << "Value not found.\n";
}

// Display the circular linked list
void display(Node* head) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;

    cout << "Circular Linked List: ";

    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);

    cout << "HEAD\n";
}

int main() {
    Node* head = nullptr;
    int choice, value;

    while (true) {
        cout << "\n--- Circular Linked List ---\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;

                insertNode(head, value);
                cout << "Node inserted successfully.\n";
                break;

            case 2:
                cout << "Enter value to delete: ";
                cin >> value;

                deleteNode(head, value);
                break;

            case 3:
                display(head);
                break;

            case 4:
                cout << "Program terminated.\n";
                return 0;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
