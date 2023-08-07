#ifndef MONOSTACK_H
#define MONOSTACK_H

#include "TStack.h"
#include <iostream>
#include <string>

// All header files needed are included above

template <typename T>
class MonoStack{
    public:
        MonoStack(int thisSize, char value);
        //defualt constructor
        ~MonoStack();
        //defualt destructor
        void push(T c); // read values from the input file 
        T pop();
        T peek();
        bool isFull();
        bool isEmpty();
        int size();
        // all methods are identical to TStack.h
    private:
        int top; // index of the top of the current stack
        int count; // number of current values in the stack
        int maxSize; // maximum number of elements in the stack
        T* stackArr;
        char o;
        // these integers are set to the values read from the input file
};

template <typename T> 
MonoStack<T>::MonoStack(int iSize , char value){ 
    stackArr = new T[iSize];
    maxSize = iSize;
    top = -1; // this value is used for preincrementing
    count = 0;
    o = value;
}
template <typename T>
MonoStack<T>::~MonoStack(){ 
    delete[] stackArr;
    // deallocation helps clean up array
}

template <typename T>
bool MonoStack<T>::isFull(){
    return (count == maxSize);
    // checks to see if stack is full
}

template <typename T>
bool MonoStack<T>::isEmpty(){
    return (count == 0);
    // checks to see if stack is empty
}

template <typename T>
int MonoStack<T>::size(){ 
    return count;
}

template <typename T>
void MonoStack<T>::push(T c){ 
    // this method allocates a new array
    if (isFull())
    {
        T *temp = new T[2 * maxSize];
        for (int i = 0; i < maxSize; ++i)
        { // linear O(n)
            temp[i] = stackArr[i];
        }
        maxSize *= 2;
        delete[] stackArr;
        stackArr = temp;
    }

    if (o == 'i'){ // used to see if the current value after previous value is increasing
        while (!isEmpty()){
            if (c == peek()){ // implements peek method to see if stack is filled
                break;
            }
            if (c < peek()){
                pop(); // adds new value to the top of the stack
            }
            else {
                ++count;
                stackArr[++top] = c;
                break;
            }
        }
        if (isEmpty()){
            ++count;
            stackArr[++top] = c;
        }
    }
    if (o == 'd'){ // used to see if the current value after previous value is decreasing
        while (!isEmpty()){
            if (c == peek()){ // implements peek method to see if stack is filled
                break;
            }
            if (c > peek()){
                pop(); // adds new value to the top of the stack
            } else {
                ++count;
                stackArr[++top] = c;
                break;
            }
        }
        if (isEmpty()){
            ++count;
            stackArr[++top] = c;
        }
    }
}

template <typename T>
T MonoStack<T>::pop(){
    --count;
    return stackArr[top--];
    // moves onto the next value
}

template <typename T>
T MonoStack<T>::peek(){ 
    return stackArr[top];
    // checks to see what value is at the top of the stackArr
}
#endif