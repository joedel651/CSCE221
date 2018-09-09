//
//  main.cpp
//  PA2
//
//  Created by Joseph DeLeonardis  on 4/9/18.
//  Copyright © 2018 Joseph DeLeonardis . All rights reserved.
//

#include <iostream>
#include "PriorityQueue.h" //the priority queue file provided
#include "stopwatch.h"  //stopwatch file
#include "Stack.h"     //reuse the stack header file

struct Node{   //a seperate class  the nodes
    Node *next;  //point to the next element in the list
    int data;   //the contents of the element
    
    Node(){
        next = NULL;
        data = -1;
    }
    
    
};

//change the queue that we worked on in a previous lab to be a priority queue
class PriorityLinkListQueue: public PriorityQueue<class Type> {
    Node *head = NULL;  //head of linked list
    //Node *temp;  //a temporary node for insertion and deletion
    Node *end = NULL;   //point to the back of the list and start off empty
    
    
public:
    Node *newnode;
    int count = -1;  //count through the list
    int min = INT_MAX;
    PriorityLinkListQueue(){
    } //constructor
    
    bool isEmpty(void) {
        if ( head == NULL) return true;  //if the head equals NULL the stack is empty
        return false;}
    
    void minValue(){
        Node *temp = head,  *popNode =NULL, *prev =NULL,  *prevtemp = head;
        //traversing from head to end for find min value and min popNode
        min = temp-> data;
        temp = temp->next;
        while (temp != NULL)
        {
            //checking temp->data is min or not
            if (min > temp->data)
            {
                //if min assign to min
                min = temp->data;
                //assigning popNode
                popNode = temp;
                prev = prevtemp;
            }
            //storing previous
            prevtemp = prevtemp->next;
            //move to next node
            temp = temp->next;
        }
        cout<<" the min is "<<min<<endl;
    }
        
        
    
    
    void removeMin(){
        
        if (head == NULL){ //check if the stack is empty
            //use two pointers to accomplish the task
            cout << "the queue is empty" << endl;
            if (head == end)
            {head = end = NULL; //the the front and the end pointer equal then it is empty
                }
        }
        else{
           // int min = INT_MAX;
            //declaring temp node to traversal from head to end, popNode to remove min node and prev link to another
            Node *temp = head,  *popNode =NULL, *prev =NULL,  *prevtemp = head;
            //traversing from head to end for find min value and min popNode
            min = head-> data;
            temp = head->next;
            popNode=head;
            while (temp != NULL)
            {
                //checking temp->data is min or not
                if (min > temp->data)
                {
                    //if min assign to min
                    min = temp->data;
                    //assigning popNode
                    popNode = temp;
                    prev = prevtemp;
                }
                //storing previous
                prevtemp = prevtemp->next;
                //move to next node
                temp = temp->next;
            //  cout<<"The node to be popped is"<<popNode->data;
            }
            //cout<<popNode->data<<"\n";
            //if popNode is head then move head to head->next
            if(popNode == head){
                head = popNode->next;
            }
            //if popNode is end then assinging NULL to prev->next node
            else if(popNode->next == NULL){
                prev->next = NULL;
                end = prev;
            }
            //if popNode is somewhere middle in list then bypassing node
            else{
                prev->next = popNode->next;
            }
            //popping popNode;
            delete popNode;
            cout << "popped " << min << endl;
            count --;
        }
        
    }
    
    
    
    void insertItem(int element){ //take in the element we want to push in as the argument
        //allocate the node
        //Node* temp  = (struct Node*)malloc(sizeof(struct Node));
        Node *temp = new Node;  //make a temporary node
        temp -> data = element;
        temp -> next = NULL;
        if(end  == NULL && head == NULL){
            head = end = temp;  //if the front and the end equal the queue is empty
            count++;     //count how many itmes the head moves through the list
        }
        else
            
            temp->data = element;  //link the old list to the new node
        end ->next = temp;
        //temp->next = end;
        end = temp;
        count ++;
    }
    
   
    
    ~PriorityLinkListQueue(){ //destructor
        
    }
    int size(){
        cout<<count<<endl;//get the count to make sure the code is indexing through the list
        return count;
    }
    
    
    
};



int main() {
    PriorityLinkListQueue x;
    CStopWatch timer;
  // x.insertItem(4);
   // x.insertItem(7);
   // x.insertItem(2);
    //x.insertItem(3);
    //x.minValue();
    //x.size();
    //x.removeMin();
    //x.removeMin();
    for(int i=0;i<80000;i++){
        x.insertItem(rand());
    }
   // x.insertItem(2);
   // x.removeMin();
  
  for(int i=0;i<80000;i++){
        x.removeMin();
    }
  
    cout<<"The time taken was "<< timer.GetElapsedSeconds()<<endl;
    timer.Reset();
    
  
    
    
    return 0;
}


