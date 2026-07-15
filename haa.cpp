#include <iostream>
using namespace std;

const int MAX_SIZE = 5;

class Stack {
private:
    int arr[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int value) {
        if (top >= MAX_SIZE - 1) {
            cout << "Stack Overflow! Cannot push " << value << ". Stack is full." << endl;
        } else {
            arr[++top] = value;
            cout << "Pushed " << value << " onto the stack." << endl;
        }
    }

    int pop() {
        if (top < 0) {
            cout << "Stack Underflow! Cannot pop from an empty stack." << endl;
            return -1;
        } else {
            int value = arr[top--];
            cout << "Popped " << value << " from the stack." << endl;
            return value;
        }
    }

    void display() {
        if (top < 0) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Elements in the stack (top to bottom): ";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Stack stack;
    int choice, value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                stack.push(value);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                stack.display();
                break;
            case 4:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
