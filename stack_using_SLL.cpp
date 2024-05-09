#include <iostream>

using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Function prototypes
void push(Node** head, int value);
int pop(Node** head);
void displayStack(Node* head);

int main() {
    Node* head = nullptr; // Initialize the head pointer to null
    int choice, value;

    do {
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Display stack\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to push: ";
                cin >> value;
                push(&head, value);
                break;
            case 2:
                if (head == nullptr) {
                    cout << "Stack is empty, cannot pop.\n";
                } else {
                    value = pop(&head);
                    cout << "Popped value: " << value << endl;
                }
                break;
            case 3:
                displayStack(head);
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}

// Function to push a value onto the stack
void push(Node** head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

// Function to pop a value from the stack
int pop(Node** head) {
    if (*head == nullptr) {
        cout << "Stack underflow!\n";
        return -1; // Assuming -1 indicates underflow
    }
    int value = (*head)->data;
    Node* temp = *head;
    *head = (*head)->next;
    delete temp;
    return value;
}

// Function to display the stack
void displayStack(Node* head) {
    if (head == nullptr) {
        cout << "Stack is empty.\n";
        return;
    }
    cout << "Stack: ";
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
