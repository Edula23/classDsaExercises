#include <iostream>
#include <string>
using namespace std;
const int MAX_SIZE = 4;
struct Stack {
    string data[MAX_SIZE];
    int top;
};

void initializeStack(Stack &s) {
    s.top = -1;
}

bool isEmpty(Stack &s) {
    return s.top == -1;
}

bool isFull(Stack &s) {
    return s.top == MAX_SIZE - 1;
}

void push(Stack &s, string value) {
    if (isFull(s)) {
        cout << "Stack Overflow! Cannot push " << value << endl;
        return;
    }
    s.top++;
    s.data[s.top] = value;
    cout << value << " pushed onto stack successfully!" << endl;
}

string pop(Stack &s) {
    if (isEmpty(s)) {
        cout << "Stack Underflow! Cannot pop from empty stack" << endl;
        return "";
    }
    string value = s.data[s.top];
    s.top--;
    cout << value << " popped from stack successfully!" << endl;
    return value;
}

string peek(Stack &s) {
    if (isEmpty(s)) {
        cout << "Stack is empty!" << endl;
        return "";
    }
    return s.data[s.top];
}

void displayForward(Stack &s) {
    if (isEmpty(s)) {
        cout << "Stack is empty!" << endl;
        return;
    }
    
    cout << "Stack elements (Top to Bottom):" << endl;
    cout << "TOP -> ";
    for (int i = s.top; i >= 0; i--) {
        cout << s.data[i];
        if (i > 0) cout << " | ";
    }
    cout << " <- BOTTOM" << endl;
    cout << "Total elements: " << s.top + 1 << endl;
}

// Function to display stack backward (bottom to top)
void displayBackward(Stack &s) {
    if (isEmpty(s)) {
        cout << "Stack is empty!" << endl;
        return;
    }
    
    cout << "Stack elements (Bottom to Top):" << endl;
    cout << "BOTTOM -> ";
    for (int i = 0; i <= s.top; i++) {
        cout << s.data[i];
        if (i < s.top) cout << " | ";
    }
    cout << " <- TOP" << endl;
    cout << "Total elements: " << s.top + 1 << endl;
}

// Function to display stack status
void displayStatus(Stack &s) {
    cout << "\n=== Stack Status ===" << endl;
    cout << "Top pointer: " << s.top << endl;
    cout << "Is empty: " << (isEmpty(s) ? "Yes" : "No") << endl;
    cout << "Is full: " << (isFull(s) ? "Yes" : "No") << endl;
    if (!isEmpty(s)) {
        cout << "Top element: " << peek(s) << endl;
    }
    cout << "===================" << endl;
}

// Function to display menu
void displayMenu() {
    cout << "\n=== ARRAY BASED STACK MENU ===" << endl;
    cout << "1. Push element" << endl;
    cout << "2. Pop element" << endl;
    cout << "3. Peek top element" << endl;
    cout << "4. Display stack forward (Top to Bottom)" << endl;
    cout << "5. Display stack backward (Bottom to Top)" << endl;
    cout << "6. Display stack status" << endl;
    cout << "7. Clear screen" << endl;
    cout << "8. Exit" << endl;
    cout << "Enter your choice (1-8): ";
}

int main() {
    Stack myStack;
    initializeStack(myStack);
    int choice;
    string value;
    
    cout << "=== ARRAY BASED STACK IMPLEMENTATION ===" << endl;
    cout << "Maximum stack size: " << MAX_SIZE << " elements" << endl;
    
    do{
        displayMenu();
        cin >> choice;
        
        switch (choice) {
            case 1: {
                cout << "Enter element to push: ";
                cin.ignore(); 
                getline(cin, value);
                push(myStack, value);
                break;
            }
            
            case 2: {
                string popped = pop(myStack);
                if (popped != "") {
                    cout << "Successfully popped: " << popped << endl;
                }
                break;
            }
            
            case 3: {
                string topElement = peek(myStack);
                if (topElement != "") {
                    cout << "Top element is: " << topElement << endl;
                }
                break;
            }
            
            case 4: {
                displayForward(myStack);
                break;
            }
            
            case 5: {
                displayBackward(myStack);
                break;
            }
            
            case 6: {
                displayStatus(myStack);
                break;
            }
            
            case 7: {
                system("cls"); 
                cout << "Screen cleared!" << endl;
                break;
            }
            
            case 8: {
                cout << "Exiting program. Goodbye!" << endl;
                return 0;
            }
            
            default: {
                cout << "Invalid choice! Please enter 1-8." << endl;
                break;
            }
        }
    } while(choice!= 8);
    
    return 0;
}