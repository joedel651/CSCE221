//
//  main.cpp
//  Lab8.2 second part of assignment 1
//
//  Created by Joseph DeLeonardis  on 2/23/18.
//  Copyright © 2018 Joseph DeLeonardis . All rights reserved.
//
//growable stack increase by a constant amount
//programming assignment 1
//impliment 3 different kinds of stacks and time them
#include <iostream>
#include "Stack.h"
#include "stopwatch.h"

using namespace std;



//inherit the Abstract Stack
class ArrayStack: public AbstractStack<class Type> {
    int Top = -1;    //an index starting before
    int length = 101;  //an array starting with length 101 size of stack
    int *data= new int[length];
    
public:
    void  setTop(int index);
    ArrayStack(){
        
    } //constructor
    
    
    bool isEmpty(void) {
        if ( Top == -1) return true;
        return false;
    }
    //structured code from double stack array in such a way that i could just change the length parameter
    void push ( int data ) {
        if( Top == length-1){
            length+=10;   //increase the size of the array
            int *new_data = new int[length];    //create a new pointer that points to the array
            for (int i = 0; i < length/2; i++) {  //copy the existing data to the new array
                new_data[i] = this->data[i];
            }
            delete [] this->data;   //delete the old memory allocated
            this->data = new_data;   //data now points to new_data
        }
        this->data[++Top] = data;
        //Top++;   //incriment top
    }
    
  int pop (){
        if(Top == -1){
            cout<<"error the stack is empty"<<endl;
        }
        Top --;  //decriment top
      return data[Top+1];
        
    }
    
    int  top(){
        return Top;   //return the inxex of the stack
    }
    
    
    
    //destructor
    ~ArrayStack(){
        
    }
    int getlength(){
        return length;   //get the size of the stack
    }
    
    
};

int main() {
    //lets test this to make sure it is working
    ArrayStack x;
    //x.push(6);
    //x.push(3);
    //x.push(4);
   // x.push(5);
    //cout<<x.top()<<endl;
   // cout<<x.getlength()<<endl;
    CStopWatch timer;
    for(int i=0;i<100;i++){
        x.push(8);
    }
    cout<<x.getlength()<<endl;
    //x.print();
    cout<<x.pop()<<endl;
    cout<<x.pop()<<endl;
    cout<<x.pop()<<endl;
    cout<<x.pop()<<endl;
    cout<<"The time taken was "<< timer.GetElapsedSeconds()<<endl;
    timer.Reset();
    return 0;
}
