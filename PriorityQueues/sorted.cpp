//
//  main.cpp
//  PA2.2
//
//  Created by Joseph DeLeonardis  on 4/10/18.
//  Copyright © 2018 Joseph DeLeonardis . All rights reserved.
//
//sorted linked list priority queue
#include <iostream>
#include "PriorityQueue.h" //the priority queue file provided
#include "stopwatch.h"  //stopwatch file
#include "Stack.h"     //reuse the stack header file


using namespace std;
struct Node{   //a seperate class  the nodes
    Node *next;  //point to the next element in the list
    int data;   //the contents of the element
    
    
};

class SortPriorityLinkListQueue: public PriorityQueue<class Type> {
    Node *head = NULL;  //head of linked list
    Node *end = NULL;   //point to the back of the list and start off empty
    
    
public:
    int min = INT_MAX;
    Node *newnode;
    int count = 0;  //count through the list
    SortPriorityLinkListQueue(){
    } //constructor
    
    bool isEmpty(void) {
        if ( head == NULL) return true;  //if the head equals NULL the stack is empty
        return false;
    }
    
    void removeMin(){
        
        if( head == NULL){  //check if the queue is empty
            //use two pointers to accomplish the task
            cout<<"the queue is empty"<<endl;
            if ( head == end ){
                head = end = NULL; //the the front and the end pointer equal then it is empty
            }
        }
        else {
            //have a temp pointer point to the end so that the end can be popped instead of the front
            Node *temp = head;  //make temp point to head
            head= head->next;
            temp->next = NULL;
            count --;           //count how many times the head moves through the list
            cout<<"poped "<<temp->data<<endl;
        }
    }
    
    void getMin(){
        sort();
        cout<<"the min is "<<min<<endl;
        }
    
    void insertItem(int element){ //take in the element we want to push in as the argument
        count ++;  //count how many elements are pushed in
        Node *temp = new Node;  //make a temporary node
        temp -> data = element;
        temp -> next = NULL;
        Node *current = new Node;
        /* Special case for the head end */
        if (head == NULL || head->data >= temp->data)
        {temp->next = head;
        head = temp;}
        else
        {/* Locate the node before the point of insertion */
            current = head;
            while (current->next!=NULL &&
                   current->next->data < temp->data)
            {
                current = current->next;
            }
            temp->next = current->next;
            current->next = temp;
        }
        end = head;
        while(end->next != NULL){
            end = end->next;
        }

    }
    
    void sort(){
        //int min = INT_MAX;
        //declaring a temp node to be able to find the insertion point
        Node *temp = head,  *pushNode =NULL, *prev =NULL,  *prevtemp = head;
        while (temp != NULL){
            //checking temp->data is min or not
            if (min > temp->data)
            {
                //if min assign to min
                min = temp->data;
                //assigning pushNode
                pushNode = temp;
                prev = prevtemp;
                
         }
            //storing previous
            prevtemp = prevtemp->next;
            //move to next node
            temp = temp->next;
            
            //if it is all the way at the head move it to the over side to be popped
            if(pushNode == head){
                end = pushNode->next;}
        }}
    
    
    
    ~SortPriorityLinkListQueue(){ //destructor
        
    }
    int size(){   //get the count to make sure the code is indexing through the list
        cout<<count<<endl;
        return count;
    }
    
};



int main() {
    SortPriorityLinkListQueue x;
     CStopWatch timer;
   // x.insertItem(6);
   // x.insertItem(7);
   // x.insertItem(5);
   // x.insertItem(4);
   // x.getMin();
   // x.size();
   // x.removeMin();
  //  x.removeMin();
  //  x.removeMin();
  //  x.removeMin();
    for(int i=0;i<80000;i++){
        x.insertItem(rand());
    }
    
    for(int i=0;i<80000;i++){
        x.removeMin();
    }
    
    
    cout<<"The time taken was "<< timer.GetElapsedSeconds()<<endl;
    timer.Reset();
    
    
    return 0;
}


