// lab4_asd_part2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <stdexcept>

template <typename T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(const T& item) : data(item), next(nullptr) {}
};

template <typename T>
class LinkedListStack {
private:
    Node<T>* topNode;

public:
    LinkedListStack() : topNode(nullptr) {}

    ~LinkedListStack() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(const T& item) {
        Node<T>* newNode = new Node<T>(item);
        newNode->next = topNode;
        topNode = newNode;
    }

    T pop() {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty");
        }
        T item = topNode->data;
        Node<T>* temp = topNode;
        topNode = topNode->next;
        delete temp;
        return item;
    }

    const T& top() const {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty");
        }
        return topNode->data;
    }

    bool isEmpty() const {
        return topNode == nullptr;
    }

    int size() const {
        int count = 0;
        Node<T>* current = topNode;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }
};

int main() {
    LinkedListStack<int> stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

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
