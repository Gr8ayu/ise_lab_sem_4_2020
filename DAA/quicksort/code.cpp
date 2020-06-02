/* C++ implementation of QuickSort */
#include <bits/stdc++.h> 
#include <chrono>
#include <ctime>  
#include <math.h>  
using namespace std; 

// A utility function to swap two elements 
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

/* This function takes last element as pivot, places 
the pivot element at its correct position in sorted 
array, and places all smaller (smaller than pivot) 
to left of pivot and all greater elements to right 
of pivot */
int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high]; // pivot 
    int i = (low - 1); // Index of smaller element 

    for (int j = low; j <= high - 1; j++) 
    { 
        // If current element is smaller than the pivot 
        if (arr[j] < pivot) 
        { 
            i++; // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 

/* The main function that implements QuickSort 
arr[] --> Array to be sorted, 
low --> Starting index, 
high --> Ending index */
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
        at right place */
        int pi = partition(arr, low, high); 

        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 

/* Function to print an array */
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        cout << arr[i] << " "; 
    cout << endl; 
} 

// Driver program 
void iter(int n) 
{ 
    int arr[n];
   for(int i=0;i<n;i++)
        arr[i] = i;
      // arr[i]=rand()%100;  //Generate number between 0 to 99

    auto start = std::chrono::system_clock::now();
    
    quickSort(arr, 0, n - 1); 

    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    //cout << "Sorted array is \n"; 
    //printArray(arr, n); 

  cout<< "count "<<n<<",elapsed time: "<<elapsed_seconds.count() <<"\tnlog(n)= "<<n*log(n)<<"\tratio = "<<n*log(n)/( elapsed_seconds.count()*1000000)<<" \n";
} 


int main()
{   int a[] = {1024,2048,2048*2,2048*4,2048*8};

    for (int i = 0; i < 5; ++i)
    {
        iter(a[i]);
    }
    /* code */
    return 0;
}