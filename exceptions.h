#ifndef exceptions_h
#define exceptions_h
#include <iostream>
#include <stdexcept>
using namespace std;
class CharStack {
private:
    static const int maxStackSize = 100;
    char stack[maxStackSize];
    int top;

public:
    CharStack() : top(-1) {}

    bool IsEmpty() const {
        return top == -1;
    }

    bool IsFull() const {
        return top == maxStackSize - 1;
    }

    void Push(char value) {
        if (IsFull()) {
            throw overflow_error("Stack overflow: Cannot push more elements.");
        }
        stack[++top] = value;
        cout << "Pushed: " << value << endl;
    }

    void Pop() {
        if (IsEmpty()) {
            throw underflow_error("Stack underflow: Cannot pop from an empty stack.");
        }
        char poppedValue = stack[top--];
        cout << "Popped: " << poppedValue << endl;
    }

    int GetSize() const {
        return top + 1;
    }

    void Clear() {
        top = -1;
        cout << "Stack cleared." << endl;
    }

    void Peek() const {
        if (IsEmpty()) {
            throw underflow_error("Stack is empty: Cannot peek.");
        }
        cout << "Top element: " << stack[top] << endl;
    }
    void ShowStackDigits() const {
        cout << "Digits in the stack: ";
        for (int i = top; i >= 0; --i) {
            cout << stack[i] << ";";
        }
        cout << endl;
    }
};
#endif