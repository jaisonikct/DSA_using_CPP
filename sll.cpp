#include <iostream>

using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Function prototypes
void appendNode(Node** head, int value);
void displayList(Node* head);

int main() {
    Node* head = nullptr; // Initialize the head pointer to null
    int choice, value;

    do {
        cout << "1. Append node\n";
        cout << "2. Display list\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to append: ";
                cin >> value;
                appendNode(&head, value);
                break;
            case 2:
                displayList(head);
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 3);

    return 0;
}

// Function to append a node to the end of the linked list
void appendNode(Node** head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (*head == nullptr) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to display the linked list
void displayList(Node* head) {
    if (head == nullptr) {
        cout << "The list is empty.\n";
        return;
    }

    Node* current = head;
    cout << "List: ";
    while (current != nullptr) {
        cout << "->" << current->data;
        current = current->next;
    }
    cout << "Null";
    cout << "\n";
}