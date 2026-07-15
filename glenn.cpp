#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    ~DoublyLinkedList() {
        while (head != NULL) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) { 
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtTail(int value) {
        Node* newNode = new Node(value);
        if (tail == NULL) { 
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void deleteFromHead() {
        if (head == NULL) {
            cout << "List is empty. Cannot delete from head." << endl;
            return;
        }

        Node* temp = head;
        if (head == tail) { 
            head = tail = NULL;
        } else {
            head = head->next;
            head->prev = NULL;
        }

        delete temp;
    }

    void deleteFromTail() {
        if (tail == NULL) {
            cout << "List is empty. Cannot delete from tail." << endl;
            return;
        }

        Node* temp = tail;
        if (head == tail) { 
            head = tail = NULL;
        } else {
            tail = tail->prev;
            tail->next = NULL;
        }

        delete temp;
    }

    void printList() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void printListReverse() {
        if (tail == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = tail;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }

    void removeByValue(int value) {
        if (head == NULL) {
            cout << "List is empty. Cannot remove by value." << endl;
            return;
        }

        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == value) {
                if (temp == head) {
                    deleteFromHead();
                } else if (temp == tail) {
                    deleteFromTail();
                } else {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    delete temp;
                }
                return;
            }
            temp = temp->next;
        }

        cout << "Value not found in the list." << endl;
    }
};

int main() {
    DoublyLinkedList list;

    list.insertAtHead(10);
    list.insertAtTail(20);
    list.insertAtTail(30);
    list.insertAtHead(5);

    cout << "List after insertion (head to tail): ";
    list.printList();

    cout << "List in reverse (tail to head): ";
    list.printListReverse();

    list.deleteFromHead();
    cout << "List after deleting from head: ";
    list.printList();

    list.deleteFromTail();
    cout << "List after deleting from tail: ";
    list.printList();

    list.removeByValue(20);
    cout << "List after removing value 20: ";
    list.printList();

    list.removeByValue(100); // Trying to remove a non-existent value
    cout << "List after trying to remove value 100: ";
    list.printList();

    return 0;
}

