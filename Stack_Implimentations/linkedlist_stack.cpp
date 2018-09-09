//
//  main.cpp
//  Lab8.3 3rd Part of programming Assignment 1
//
//  Created by Joseph DeLeonardis  on 2/23/18.
//  Copyright © 2018 Joseph DeLeonardis . All rights reserved.
//
#include <iostream>
#include "Stack.h"
#include "stopwatch.h"
using namespace std;
struct Node{   //a seperate class  the nodes
    Node *next;  //point to the next element in the list
    int data;   //the contents of the element
    
    
};

class LinkListArrayStack: public AbstractStack<class Type> {
    Node *head = NULL;  //head of linked list
    Node *temp;  //a temporary node for insertion and deletion
    
public:
    
    Node *newnode;
   int count = -1;  //count through the list
    LinkListArrayStack(){
    } //constructor
    
    bool isEmpty(void) {
        if ( head == NULL) return true;  //if the head equals NULL the stack is empty
        return false;
    }
    
    void pop(){
        if( head == NULL){  //check if the stack is empty
            cout<<"the stack is empty"<<endl;
        }
        else {
            Node *temp = head;  //make temp point to head
            head = temp->next;  //make head point skip over that element and point to the next one
            count --;           //count how many times the head moves through the list
            cout<<"poped "<<temp->data<<endl;
        }
        }
    
    void push(int element){ //take in the element we want to push in as the argument
    //allocate the node
   Node* temp  = (struct Node*)malloc(sizeof(struct Node));
        //Node *temp = new Node;  //make a temporary node
        if(head == NULL){
            temp->data = element;  //access data through a pointer and set it equal to the element being passed in
            temp->next = NULL;  //since it was empty the next node will now be the NULL
            head = temp; //reassign the original head to the temporary pointer
            count++;     //count how many itmes the head moves through the list
        
            
        }
        else
            
            temp->data = element;  //link the old list to the new node
            temp->next = head;
            head = temp;
            count ++;
    }
    
   
    
  
    Node Head(){   //this function is not doing anything can probably be deleted
  
        return *head;   //return the index of the stack
        
    }
    
  void  print(){
      
      while(head!=NULL){
          
      }
    }
 
    
    
    ~LinkListArrayStack(){ //destructor
        
    }
    int getcount(){   //get the count to make sure the code is indexing through the list
        return count;
    }
    
};



int main() {
    LinkListArrayStack x;
    //x.push(6);
   // x.push(7);
    //x.push(5);
   // x.push(4);
   // cout<<x.count<<endl;
   // x.print();
    CStopWatch timer;
    for(int i=0;i<150000000;i++){
        x.push(8);
    }
    x.pop();
    x.pop();
    x.pop();
    x.pop();
    cout<<"The time taken was "<< timer.GetElapsedSeconds()<<endl;
    timer.Reset();
    
    return 0;
}
