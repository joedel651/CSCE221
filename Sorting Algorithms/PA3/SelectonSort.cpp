//
//  main.cpp
//  PA3
//
//  Created by Joseph DeLeonardis  on 4/24/18.
//  Copyright © 2018 Joseph DeLeonardis . All rights reserved.
//
#include "stopwatch.h"
#include <iostream>
//#include "Heap.h"
using namespace std;
class SelectionSort /*: public Heap<class Type>*/ {
    
    public:
    
    SelectionSort(){
    } //constructor
    
    // reuse the swap function from assignment 2
    void swap(int *x, int *y)  //seperate function to swap elements
    {
        int temp = *x;
        *x = *y;
        *y = temp;}
    
    // find which value is the min and keep going through the loop until all the values are sorted
    void selectionSort(int a[], int n)
    {
        int i, j, min_index;
        
        // One by one move boundary of unsorted subarray
        for (i = 0; i < n-1; i++)
        {
            // Find the minimum element in unsorted array
            min_index = i;
            for (j = i+1; j < n; j++)
                if (a[j] < a[min_index])
                    min_index = j;
            
            // Swap the found minimum element with the first element
            swap(&a[min_index], &a[i]);
        }
        
    }
    
    void printArray(int a[], int size)
    {
        int i;
        for (i=0; i < size; i++){
            cout << a[i] <<" "<<endl;
        }
           
    }
    
    
    ~SelectionSort(){
    } //destructor
    
    
};
 int main() {
      CStopWatch timer;
     SelectionSort arr;
     int a[80000];
     for(int i=0; i<80000; i++){
         a[i] = (rand()%100); }
     //int a[] = {19, 257, 36, 42, 11};
     int n = sizeof(a)/sizeof(a[0]);
     arr.selectionSort(a, n);
     arr.printArray(a,n);
     cout<<"The time taken was "<< timer.GetElapsedSeconds()<<endl;
     timer.Reset();
     
    return 0;
}
