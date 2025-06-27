//! Insertion Sort : 
//* Takes an element & place it in its correct order
//? Insertion sort is a simple, comparison-based sorting algorithm 
//? that builds a sorted array (or list) one element at a time. The algorithm 
//? works by dividing the array into a "sorted" and "unsorted" part. 
//? Initially, the first element is considered sorted. Then, for each subsequent element, 
//? insertion sort removes it from the unsorted part and inserts it into its correct position 
//? within the sorted part by shifting larger elements one position to the right

#include<iostream>
using namespace std;
void InsertionSort(int arr[], int n){
    for(int i=1; i<n; i++){
        int curr = arr[i];
        int prev = i-1;
        while(prev>=0 && arr[prev]>curr){
            arr[prev+1] = arr[prev];
            prev--;
        }
        arr[prev+1] = curr;
    }
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    InsertionSort(arr,n);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}
//* Time Complexity : O(N^2)  {worst and average case}
//*                    O(N)  {best case complexity}