// lab4_asd.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdexcept>


template <typename T, int maxSize>
class ArrayStack {
private:
    T data[maxSize];
    int topIndex;

public:
    ArrayStack() : topIndex(-1) {}

    void push(const T& item) {
        if (topIndex == maxSize - 1) {
            throw std::overflow_error("Stack is full");
        }
        data[++topIndex] = item;
    }

    T pop() {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty");
        }
        return data[topIndex--];
    }

    const T& top() const {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty");
        }
        return data[topIndex];
    }

    bool isEmpty() const {
        return topIndex == -1;
    }

    bool isFull() const {
        return topIndex == maxSize - 1;
    }

    int size() const {
        return topIndex + 1;
    }
};

int main() {
    ArrayStack<int, 5> stack;

    stack.push(1);
    stack.push(2);
    stack.push(7);
    stack.push(3);
    stack.push(8);

    std::cout << "Stack size: " << stack.size() << std::endl;
    std::cout << "Top element: " << stack.top() << std::endl;

    stack.pop();
    std::cout << "Popped top element" << std::endl;




    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
