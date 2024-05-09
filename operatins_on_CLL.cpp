#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Circular Linked List class
class CircularLinkedList {
private:
    Node* head;
public:
    CircularLinkedList() {
        head = nullptr;
    }
    
    // Function to add a node at the beginning of the list
    void addAtBeginning(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }
    
    // Function to add a node at the end of the list
    void addAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
        }
    }
    
    // Function to add a node at a specified position
    void addAtPosition(int value, int position) {
        if (position < 0) {
            cout << "Invalid position\n";
            return;
        }
        
        if (position == 0) {
            addAtBeginning(value);
            return;
        }
        
        Node* newNode = new Node(value);
        Node* temp = head;
        int count = 0;
        while (count < position - 1 && temp->next != head) {
            temp = temp->next;
            count++;
        }
        
        if (temp->next == head) {
            cout << "Position out of range\n";
            return;
        }
        
        newNode->next = temp->next;
        temp->next = newNode;
    }
    
    // Function to delete a node at a specified position
    void deleteAtPosition(int position) {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        
        if (position == 0) {
            Node* temp = head;
            while (temp->next != head)
                temp = temp->next;
            if (head->next == head) {
                delete head;
                head = nullptr;
            } else {
                temp->next = head->next;
                delete head;
                head = temp->next;
            }
            return;
        }
        
        Node* temp = head;
        Node* prev = nullptr;
        int count = 0;
        while (count < position && temp->next != head) {
            prev = temp;
            temp = temp->next;
            count++;
        }
        
        if (temp->next == head) {
            cout << "Position out of range\n";
            return;
        }
        
        prev->next = temp->next;
        delete temp;
    }
    
    // Function to display the circular linked list
    void display() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    CircularLinkedList list;
    int choice;
    
    do {
        cout << "Choose operation:\n";
        cout << "1. Add a node\n";
        cout << "2. Delete a node\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                int addChoice, value, position;
                cout << "Add Operation:\n";
                cout << "1. Add at beginning\n";
                cout << "2. Add at end\n";
                cout << "3. Add at position\n";
                cout << "Enter your choice: ";
                cin >> addChoice;
                
                cout << "Enter value: ";
                cin >> value;
                
                if (addChoice == 3) {
                    cout << "Enter position: ";
                    cin >> position;
                }
                
                switch(addChoice) {
                    case 1:
                        list.addAtBeginning(value);
                        break;
                    case 2:
                        list.addAtEnd(value);
                        break;
                    case 3:
                        list.addAtPosition(value, position);
                        break;
                    default:
                        cout << "Invalid choice\n";
                }\
                cout << "Circular Linked List: ";
                list.display();
                break;
            case 2:
                int deletePosition;
                cout << "Enter position to delete: ";
                cin >> deletePosition;
                list.deleteAtPosition(deletePosition);
                cout << "Circular Linked List: ";
                list.display();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while(choice != 0);
    
    return 0;
}
