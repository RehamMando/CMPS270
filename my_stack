#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

template <class T> class my_stack{
    public:
    int front = -1;
    vector<T> elements = {};
    void push(const T element);
    T pop();
    T top();
    bool empty();
};
//requires: nothing
//effescts: it return true is the stack is empty and false if the stack contains at least one element.
//Test cases: 1) empty stack
//2) non empty stack
template <class T> bool my_stack<T>::empty(){
    if(front == -1)
        return true;
    else
        return false;
}

//requires: a pointer to a constant variable of a generic type T.
//effescts: it will add the item to the top of the stack
//Test cases: 1) try different types of stacks: int, char, double, etc.
//2) give 0 
template <class T> void my_stack<T>::push(const T element){
    front++;
    elements[front] = element;
}

//requires: nothing
//effescts: returns a pointer to the element at top of the stak without deleting it
//Test cases: 1) empty stack
//2) non empty stack
//3) try different types of stacks: int, char, double, etc.
template <class T> T my_stack<T>::top(){
    return elements[front];
}

//requires: nothing
//effescts: returns the element at top of the stak and delete it
//Test cases: 1) empty stack
//2) non empty stack
//3) try different types of stacks: int, char, double, etc.
template <class T> T my_stack<T>::pop(){
    T last_element = elements[front];
    front--;
    return last_element;
}
