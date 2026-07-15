#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;

    // Constructor
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
        head = NULL;
    }

    // Insert at the beginning
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // Insert at the end
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Delete a node by value
    void deleteNode(int val) {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        // If head node is the one to be deleted
        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        // Search for the node to be deleted
        Node* temp = head;
        while (temp->next != NULL && temp->next->data != val) {
            temp = temp->next;
        }

        // If node not found
        if (temp->next == NULL) {
            cout << "Value not found in the list!" << endl;
            return;
        }

        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

    // Display the list
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Destructor to free memory
    ~SinglyLinkedList() {
        Node* temp;
        while (head != NULL) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Main function
int main() {
    SinglyLinkedList list;

    list.insertAtBeginning(10);
    list.insertAtBeginning(5);
    list.insertAtEnd(15);
    list.insertAtEnd(20);

    cout << "Linked List: ";
    list.display();

    list.deleteNode(15);
    cout << "After deleting 15: ";
    list.display();

    list.deleteNode(100); // Trying to delete a non-existing value

    return 0;
}

