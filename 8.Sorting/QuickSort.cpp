//! Ouick Sort : 
//? Why doing Quick sort, if we know Merge Sort, Reason : 
//? TC : O( N * logN ) & SC : O(1) whereas for merge sort TC : O(N * logN ) & SC : O(N) (due to extra temp arr)

//* Quick Sort :   --> Divide & conquer
//* 1. Pick a Pivot & place it in its correct place in the sorted array.
//* Pivot can :
//? a. 1st element in the array
//? b. last element in the array
//? c. median of the array
//? d. random element of the array
//* 2. Smaller on the left, larger on the right 


//! Code :
#include<iostream>
#include<vector>
using namespace std;
int partition(vector<int>& arr, int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i < j){
        while(arr[i] <= pivot && i <= high - 1){
            i++;
        }
        while(arr[j] > pivot && j >= low + 1){
            j--;
        }
        if(i<j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}
void quickSort(vector<int>& arr, int low, int high){
    if(low < high){
        int pIndex = partition(arr, low, high);
        quickSort(arr, low, pIndex-1);
        quickSort(arr, pIndex+1, high); 
    }
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    quickSort(arr,0,n-1);
    for(auto it : arr) cout << it << " ";
    return 0;
}
//* Time Complexity --> O( NlogN )
//* Space Complexity --> O(1)  [Recursion stack space is not computed]