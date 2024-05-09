#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Function to insert a node at the end of the list
    void insertEnd(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;

        if (head == nullptr) {
            newNode->prev = nullptr;
            head = newNode;
            tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Function to reverse the doubly linked list
    void reverse() {
        Node* temp = nullptr;
        Node* current = head;

        // Swap next and prev pointers for all nodes
        while (current != nullptr) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }

        // If the list is not empty, head should point to the last node
        if (temp != nullptr) {
            head = temp->prev;
        }
    }

    // Function to display the doubly linked list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    int choice, data;

    do {
        cout << "\n1. Insert\n2. Display\n3. Reverse\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to insert: ";
                cin >> data;
                list.insertEnd(data);
                break;
            case 2:
                cout << "List contents: ";
                list.display();
                break;
            case 3:
                list.reverse();
                cout << "List reversed successfully." << endl;
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}
