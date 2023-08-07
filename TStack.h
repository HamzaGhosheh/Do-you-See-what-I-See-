#ifndef TStack_H
#define TStack_H
#include <iostream>

//All header files needed are included above
template <typename T>
class TStack{
    public:
        TStack(int iSize);
        //defualt constructor
        ~TStack();
        //default destructor
        void push(T c); //add to the top
        T pop(); //remove from the top
        T peek(); //return the top without removing
        bool isFull();
        bool isEmpty();
        int size();

    private:
        T* stackArr;
        int count; //number of items currently in the stack
        int maxSize; //max number of things in the stack
        int top; //index of the current top of the stack
};

template <typename T>
TStack<T>::TStack(int iSize){
    stackArr = new T[iSize];
    maxSize = iSize;
    count = 0;
    top = -1;
}

template <typename T>
TStack<T>::~TStack(){
    delete[] stackArr;
    // deallocation of the array
    //another form of cleanup
}

template <typename T>
bool TStack<T>::isFull(){
    return (count == maxSize);
    //checks to see if stack is full
}

template <typename T>
bool TStack<T>::isEmpty(){
    return (count == 0);
    //checks to see
}

template <typename T>
int TStack<T>::size(){
    return count;
}

template <typename T>
void TStack<T>::push(T c){
    if(isFull()){
        T* temp = new T[2*maxSize];
        for(int i = 0; i < maxSize; ++i){
            temp[i] = stackArr[i];
        }
        maxSize *= 2;
        delete[] stackArr;
        stackArr = temp;
    }
    stackArr[++top] = c;
    ++count;
}

template <typename T>
T TStack<T>::pop(){
    --count;
    return stackArr[top--];
}

template <typename T>
T TStack<T>::peek(){
    return stackArr[top];
}

#endif