#include <iostream>
#include "my_stack.cpp"
#include <vector>
using namespace std;



template <class T> class my_stack;

template <class T> 

//Requires: two pointers for two stacks of a the same generic type; 
//Effects: returns a new stack containing a’s items followed by b’s items (assuming a and b are both Stacks), in their original order
//Test cases: 1) different types of stacks: int, char, double, etc.
//2) a is empty while b is not
//3) b is empty while a is not
//4) two stacks are empty
//5) a = {1,2,3} & b = {7,8,2}
//6) a = {a,f,r} & b = {o,t,e}
//7) a = {1.5,6.4} & b = {9.4,2.4}
//8) given the same pointer for the two parameters.
my_stack<T> operator + (my_stack<T> &a,  my_stack<T> &b){

    my_stack result_stack = a;   //copy st1 to my result stack

    for(unsigned i = 0; i < a.elements.size(); ++i){
        result_stack.push(b.elements[i]);        //copy b's items to st1
    }
    return result_stack;
}
template <class T>class op_overload{
    

    friend my_stack<T> operator + <> (my_stack<T> &a,  my_stack<T> &b);


};
    int main(void){
        cout<<"hi";
        my_stack<int> a, b;
        my_stack<int> emptyst = a + b;
        printStack(emptyst);
        a.push(1);
        a.push(2);
        b.push(3);
        b.push(4);
        cout<< "a = ";
        printStack(a);
        cout<<endl;
        cout<< "b = ";
        printStack(b);
        cout<<endl;
        my_stack<int> c = a + b;
        cout<< "c = a + b = ";
        printStack(c);
        cout<<endl;
    }
template <class T> 
//requires: nothing
    //effects: print the elements of the stack from bottom to top without changing their order.
    //test cases: 1)emptystack
    //2) try different types of stacks
    //3){1,2,3,4}
        
void printStack(my_stack<T> st){
        if(st.empty()){  
            cout << "{}";
            return;
        }
        else{
            T x = st.pop();
            printStack(st);  //recursively call the function printStack
            cout << x << " ";
            st.push(x);
            }
    }
