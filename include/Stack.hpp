#ifndef STACK_HPP
#define STACK_HPP

#include <stdexcept>

template <typename Object>
class Stack {
private:
    struct Node {
        Object item;
        Node* next;

        Node(const Object& item, Node* next) : item(item), next(next) {}
    };

    Node* topOfStack = nullptr;

public:
    Stack() = default;
    Stack(const Stack&) = delete;
    Stack& operator=(const Stack&) = delete;

    ~Stack() {
        clear();
    }

    bool isEmpty() const {
        return topOfStack == nullptr;
    }

    void push(const Object& item) {
        topOfStack = new Node(item, topOfStack);
    }

    void pop() {
        if (isEmpty()) {
            throw std::underflow_error("Yığın boş.");
        }
        Node* oldTop = topOfStack;
        topOfStack = topOfStack->next;
        delete oldTop;
    }

    const Object& top() const {
        if (isEmpty()) {
            throw std::underflow_error("Yığın boş.");
        }
        return topOfStack->item;
    }

    void clear() {
        while (!isEmpty()) {
            pop();
        }
    }
};

#endif
