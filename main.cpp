#include<iostream>
#include"Stack.h"
using namespace std;


int main() {

    //test LStack
    LStack<int> stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    cout << "Top element: " << stack.topValue() << endl; // Should print 30
    cout << "Stack size: " << stack.length() << endl; // Should print 3
    cout << "Popped element: " << stack.pop() << endl; // Should print 30
    cout << "New top element: " << stack.topValue() << endl; // Should print 20
    cout << "Stack size after pop: " << stack.length() << endl; // Should print 2
    stack.clear();
    cout << "Stack size after clear: " << stack.length() << endl; // Should print 0
    return 0;
}