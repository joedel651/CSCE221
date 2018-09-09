

#include <iostream>
using namespace std;
#include "stopwatch.h"  //stopwatch file
//merge the arrays take in the array and the left middle and right as arguments
void merge(int arr[], int left, int right, int middle)
{
    
     int i, j, k;  // indexs for the subarrays
    //int middle = left+(right-left)/2;  // define what the middle is
     //index of temp arrays 
    int temp1 = middle - left + 1;
    int temp2 =  right - middle;
    
     int L[temp1], R[temp2];  //temp arrays
   
    
    // copy the data to the temp arrays
    for (i = 0; i < temp1; i++)
    {L[i] = arr[left + i];
        }
    for (j = 0; j < temp2; j++){
        R[j] = arr[middle + 1+ j];}
    
    /* Have to define some sort of index for the split arrays*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = left; // Initial index of merged subarray
    
    while (i < temp1 && j < temp2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;}
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    //copy elements
    while (i < temp1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    //copy elements
    while (j < temp2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
     
        int middle = left+(right-left)/2;
        
        // Sort first and second halves
        MergeSort(arr, left, middle);
        MergeSort(arr, middle+1, right);
        merge(arr, left, right, middle);
       
    }
    


    
}
    
    void printArray(int a[], int size)
    {
        int i;
        for (i=0; i < size; i++){
            cout << a[i] <<" "<<endl;
        }
        
    }


int main()
{
    CStopWatch timer;
    int arr[80000];
    for(int i=0;i<80000;i++){
        arr[i] = rand()%100;
        
    }
    int arr_size = sizeof(arr)/sizeof(arr[0]);
      MergeSort(arr, 0, arr_size - 1);
      printArray(arr,arr_size);
    cout<<"The time taken was "<< timer.GetElapsedSeconds()<<endl;
    timer.Reset();
    return 0;
}
