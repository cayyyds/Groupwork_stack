#include<iostream>
#include"Link.h"
using namespace std;

template <typename E>
class LStack {
    private:
        Link<E>* top;    // Pointer to stack top
        int size;       // Number of stack elements
    public:
        LStack() : top(NULL), size(0) {}  // Constructor
        ~LStack();                         // Destructor
        void clear();                      // Reinitialize stack
        void push(const E& it);           // Push element onto stack
        E pop();                           // Pop element off stack
        const E& topValue() const;        // Return top element
        int length() const { return size; } // Return stack size
};
template <typename E>
LStack<E>::~LStack() {
    clear();
}
template <typename E>
void LStack<E>::clear() {
    while (top != NULL) {
        Link<E>* temp = top;
        top = top->next;
        delete temp;
    }
}
template <typename E>
void LStack<E>::push(const E& it) {
    top = new Link<E>(it, top);
    size++;
}
template <typename E>
E LStack<E>::pop() {
    if (size == 0) {
        throw "Stack is empty";
    }
    E it = top->element;
    Link<E>* temp = top;
    top = top->next;
    delete temp;
    size--;
    return it;
}
template <typename E>
const E& LStack<E>::topValue() const {
    if (size == 0) {
        throw "Stack is empty";
    }
    return top->element;
}