//
//  main.cpp
//  PA3.1
//
//  Created by Joseph DeLeonardis  on 4/11/18.
//  Copyright © 2018 Joseph DeLeonardis . All rights reserved.
//
//Heapsort
#include <iostream>
#include "PriorityQueue.h" //the priority queue file provided
#include "stopwatch.h"  //stopwatch file
#include "Stack.h"     //reuse the stack header file
using namespace std;
class HeapPriorityQueue: public PriorityQueue<class Type> {
    int capacity= 100; // maximum possible size of min heap
    int *data= new int[capacity];
    int Top = -1;  //just keeps track of where in the array we are inserting
    
public:
    
    //default constructor
    HeapPriorityQueue(){
        
        
    }
    
    int size(){
        return Top + 1;
    }
    
    //parent node
    int parent(int i) {return (i-1)/2;}
    
    // to get index of left child of node at index i
    int left(int i) { return (2*i + 1); }
    
    // to get index of right child of node at index i
    int right(int i) { return (2*i + 2); }
    
    void swap(int *x, int *y)  //seperate function to swap elements
    {
        int temp = *x;
        *x = *y;
        *y = temp;
        
    }
    void downheap(int i)
    {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if (l < size() && data[l] < data[i])
            smallest = l;
        if (r < size() && data[r] < data[smallest])
            smallest = r;
        if (smallest != i)
        {
            swap(&data[i], &data[smallest]);
            downheap(smallest);
        }
        
    }
    
    bool isEmpty(void) {
        if ( Top == -1) return true;
        return false;
    }
    
    void upheap(int i){
        int p = parent(i);  //parent node
        
        
        if(i != 0 && data[p] > data[i] ){
            swap(&data[p],&data[i]);
            upheap(p);
        }
    }
    //this is the heapify function i like to call is sort because that is what is doing
    
    //data is what is being pushed into the array
    void insertItem(int data){
        if( Top == capacity-1){
            capacity*=2;   //increase the size of the array
            int *new_data = new int[capacity];    //create a new pointer that points to the array
            for (int i = 0; i < capacity/2; i++) {  //copy the existing data to the new array
                new_data[i] = this->data[i];
            }
            delete [] this->data;   //delete the old memory allocated
            this->data = new_data;   //data now points to new_data
        }
        this->data[++Top] = data;
        //cout<<"inserting at "<<Top<<" with data " << data <<endl;
        upheap(Top);
        
    }
    
    int removeMin(){
        if(Top == -1){
            //cout<<"error the priority queue is empty"<<endl;
        }
        int temp = data[0];
        data[0] = data[Top];
        Top --;  //decriment top
        downheap(0);
        return temp;  //get the first element
        
    }
    int Minvalue(){
        
        return data[0];  //get the first element
        
    }
    //destructor
    ~HeapPriorityQueue(){
        
    }
    void print(){
        
        for(int i = 0; i<size(); i++){
            cout<<data[i]<<endl;
        }
    }
    
};

//The header file was not properly working so the heap from the previous programming assignment is used
//a function was added to take in an array and sort it with the heap
void HeapSort(int arr[],int n){
    HeapPriorityQueue h;
    int sorted[n];
    for(int i=0; i < n; i++){
        h.insertItem(arr[i]);
    }
    for(int j=0; j< n; j++){
        //h.removeMin();
        sorted[j] = h.Minvalue();
        h.removeMin();
        cout<<sorted[j]<<endl;
    }
    
}


int main() {
    CStopWatch timer;
    int arr[80000];
    for(int i=0;i<80000;i++){
        arr[i] = rand()%100;

    }
     HeapSort(arr, 80000);
    cout<<"The time taken was "<< timer.GetElapsedSeconds()<<endl;
    timer.Reset();
    
    return 0;
};

