/* C program for Merge Sort */
#include <iostream>
#include<stdlib.h> 
#include<stdio.h> 
#include <chrono>
#include <ctime>  
#include <math.h>  
using namespace std;

void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 

    /* create temp arrays */
    int L[n1], R[n2]; 

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 

    /* Copy the remaining elements of L[], if there 
    are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 

    /* Copy the remaining elements of R[], if there 
    are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 

/* l is for left index and r is right index of the 
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 

        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 

        merge(arr, l, m, r); 
    } 
} 

void printArray(int A[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 



// Driver program 
void iter(int n) 
{ 
    int arr[n];
   for(int i=0;i<n;i++)
      arr[i]=-i; //Generate number between 0 to 99
  
    auto start = std::chrono::system_clock::now();
    
    mergeSort(arr, 0, n - 1); 
    // printArray(arr,n);
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    //cout << "Sorted array is \n"; 
    //printArray(arr, n); 

  cout<< "count "<<n<<",elapsed time: "<<elapsed_seconds.count() <<"\tnlog(n)= "<<n*log(n)<<"\tratio = "<<n*log(n)/( elapsed_seconds.count()*1000000)<<" \n";
} 


int main()
{   int a[] = {10,20,30,40,50};

    for (int i = 0; i < 5; ++i)
    {
        iter(a[i]);
    }
    /* code */
    return 0;
}