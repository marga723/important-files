#include <iostream>

using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Singly Linked List class
class SinglyLinkedList {
private:
    Node* head;

public:
    // Constructor
    SinglyLinkedList() {
        head =  NULL;
    }

    // Insert at the beginning
    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // Insert at the end
    void insertAtTail(int val) {
        Node* newNode = new Node(val);
        if (head ==  NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next !=  NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Insert at a specific position
    void insertAtPosition(int val, int pos) {
        if (pos < 1) {
            cout << "Invalid position!" << endl;
            return;
        }
        if (pos == 1) {
            insertAtHead(val);
            return;
        }
        Node* newNode = new Node(val);
        Node* temp = head;
        for (int i = 1; temp !=  NULL && i < pos - 1; i++) {
            temp = temp->next;
        }
        if (temp ==  NULL) {
            cout << "Position out of range!" << endl;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Delete a node by value
    void deleteByValue(int val) {
        if (head ==  NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        while (temp->next !=  NULL && temp->next->data != val) {
            temp = temp->next;
        }
        if (temp->next ==  NULL) {
            cout << "Value not found!" << endl;
            return;
        }
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    // Delete a node by position
    void deleteByPosition(int pos) {
        if (head ==  NULL || pos < 1) {
            cout << "Invalid position or empty list!" << endl;
            return;
        }
        if (pos == 1) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        for (int i = 1; temp !=  NULL && i < pos - 1; i++) {
            temp = temp->next;
        }
        if (temp ==  NULL || temp->next ==  NULL) {
            cout << "Position out of range!" << endl;
            return;
        }
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    // Search for a value in the list
    bool search(int val) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == val) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // Display the linked list
    void display() {
        Node* temp = head;
        while (temp !=  NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Destructor to free memory
    ~SinglyLinkedList() {
        Node* temp = head;
        while (temp !=  NULL) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

// Driver function for testing
int main() {
    SinglyLinkedList sll;

    sll.insertAtTail(10);
    sll.insertAtTail(20);
    sll.insertAtTail(30);
    sll.insertAtHead(5);
    sll.insertAtPosition(15, 3);
    
    cout << "Linked List after insertions: ";
    sll.display();

    sll.deleteByValue(20);
    cout << "Linked List after deleting value 20: ";
    sll.display();

    sll.deleteByPosition(2);
    cout << "Linked List after deleting node at position 2: ";
    sll.display();

    cout << "Searching for 30: " << (sll.search(30) ? "Found" : "Not Found") << endl;
    cout << "Searching for 100: " << (sll.search(100) ? "Found" : "Not Found") << endl;

    return 0;
}
