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
    newNode->next = nullptr;

    // If list is empty
    if (head == nullptr) {
        head = newNode;
        return;
    }

    // Traverse to the last node
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Delete a node by value
void deleteNode(Node*& head, int value) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    // If the first node contains the value
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Node deleted.\n";
        return;
    }

    Node* temp = head;

    while (temp->next != nullptr && temp->next->data != value) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        cout << "Value not found.\n";
        return;
    }

    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;

    cout << "Node deleted.\n";
}

// Display the linked list
void display(Node* head) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;

    cout << "Linked List: ";

    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

int main() {
    Node* head = nullptr;
    int choice, value;

    while (true) {
        cout << "\n--- Singly Linked List ---\n";
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
                cout << "Node inserted.\n";
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
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
