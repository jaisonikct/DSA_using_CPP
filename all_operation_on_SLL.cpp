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
void addNodeAtBegin(Node** head, int value);
void addNodeAfter(Node* prevNode, int value);
void deleteFirstNode(Node** head);
void deleteLastNode(Node** head);
void deleteNodeAfter(Node* prevNode);

int main() {
    Node* head = nullptr; // Initialize the head pointer to null
    int choice, value;

    do {
        cout << "1. Append node\n";
        cout << "2. Display list\n";
        cout << "3. Add at begin\n";
        cout << "4. Add after\n";
        cout << "5. Delete at start\n";
        cout << "6. Delete at end\n";
        cout << "7. Delete after\n";
        cout << "8. Exit\n";
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
                cout << "Enter the value to add at the beginning: ";
                cin >> value;
                addNodeAtBegin(&head, value);
                break;
            case 4:
                int afterValue;
                cout << "Enter the value to add after: ";
                cin >> afterValue;
                cout << "Enter the value to append: ";
                cin >> value;
                addNodeAfter(head, afterValue);
                break;
            case 5:
                deleteFirstNode(&head);
                break;
            case 6:
                deleteLastNode(&head);
                break;
            case 7:
                int afterDeleteValue;
                cout << "Enter the value after which you want to delete: ";
                cin >> afterDeleteValue;
                deleteNodeAfter(head);
                break;
            case 8:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 8);

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
    cout << "->Null\n";
}

// Function to add a node at the beginning of the linked list
void addNodeAtBegin(Node** head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

// Function to add a node after a specific node
void addNodeAfter(Node* prevNode, int value) {
    if (prevNode == nullptr) {
        cout << "The given previous node cannot be null.\n";
        return;
    }

    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

// Function to delete the first node from the linked list
void deleteFirstNode(Node** head) {
    if (*head == nullptr) {
        cout << "List is empty, nothing to delete.\n";
        return;
    }

    Node* temp = *head;
    *head = (*head)->next;
    delete temp;
}

// Function to delete the last node from the linked list
void deleteLastNode(Node** head) {
    if (*head == nullptr) {
        cout << "List is empty, nothing to delete.\n";
        return;
    }

    if ((*head)->next == nullptr) {
        delete *head;
        *head = nullptr;
        return;
    }

    Node* secondLast = *head;
    while (secondLast->next->next != nullptr) {
        secondLast = secondLast->next;
    }

    delete secondLast->next;
    secondLast->next = nullptr;
}

// Function to delete the node after a specific node
void deleteNodeAfter(Node* prevNode) {
    if (prevNode == nullptr || prevNode->next == nullptr) {
        cout << "There is no node to delete after.\n";
        return;
    }

    Node* temp = prevNode->next;
    prevNode->next = prevNode->next->next;
    delete temp;
}
