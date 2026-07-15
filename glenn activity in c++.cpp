#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(NULL) {}

   
    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void reverse() {
        Node* prev = NULL;
        Node* current = head;
        Node* next = NULL;
        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }


    ~LinkedList() {
        Node* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;
    
    
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);
    list.insert(50  );
    
    cout << "Original list: ";
    list.display();

    list.reverse();
    
    cout << "Reversed list: ";
    list.display();
    
    return 0;
}

