#include <iostream>
using namespace std;
#define MAX_SIZE 5

class Stack {
private:
    int arr[MAX_SIZE];
    int top;

public:
    Stack() { top = -1; }

    void push(int value) {
        if (top >= MAX_SIZE - 1) {
            std::cout << "Stack overflow! Cannot push " << value << "\n";
        } else {
            arr[++top] = value;
            std::cout << "Pushed " << value << " into stack.\n";
        }
    }

    int pop() {
        if (top < 0) {
            std::cout << "Stack underflow! Cannot pop.\n";
            return -1;
        } else {
            int poppedValue = arr[top--];
            std::cout << "Popped " << poppedValue << " from stack.\n";
            return poppedValue;
        }
    }

    void display() {
        if (top < 0) {
            std::cout << "Stack is empty.\n";
        } else {
            std::cout << "Stack elements (top to bottom): ";
            for (int i = top; i >= 0; i--) {
                std::cout << arr[i] << " ";
            }
            std::cout << "\n";
        }
    }
};

int main() {
    Stack stack;
    int choice, value;

    do {
        std::cout << "\nStack Operations Menu:\n";
        std::cout << "1. Push\n2. Pop\n3. Display\n4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter value to push: ";
                std::cin >> value;
                stack.push(value);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                stack.display();
                break;
            case 4:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice! Please enter a valid option.\n";
        }
    } while (choice != 4);

    return 0;
}

