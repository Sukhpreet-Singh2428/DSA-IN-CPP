//! Largest Element in an Array 
//* (Easy problem)

//? eg :   arr[] = {3,2,1,5,2}

//* Brute --> Better --> Optimal

//* Brute : 
//? sort --> cout arr[n-1]
// #include<iostream>
// #include<vector>
// using namespace std;
// int partition(vector<int>& arr, int low, int high){
//     int pivot = arr[low];
//     int i = low;
//     int j = high;
//     while(i<j){
//         while(arr[i]<=pivot && i<=high-1){
//             i++;
//         }
//         while(arr[j]>pivot && j>=low+1){
//             j--;
//         }
//         if(i<j) swap(arr[i],arr[j]);
//     }
//     swap(arr[low],arr[j]);
//     return j;
// }
// void quicksort(vector<int>& arr, int low, int high){
//     if(low<high){
//         int pIndex = partition(arr,low,high);
//         quicksort(arr,low,pIndex-1);
//         quicksort(arr,pIndex+1,high);
//     }
// }
// void largestElement(vector<int>& arr){
//     quicksort(arr,0,arr.size()-1);
//     cout << arr[arr.size()-1];
// }
// int main(){
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(int i=0;i<n;i++){
//         cin >> arr[i];
//     }
//     largestElement(arr);
//     return 0;
// }
//? Time Complexity : O(NlogN)
//? Space Complexity : O(1)  {ignoring tha recursion stack space}


//* There is no better for this problem (better means modify the brute code and make it better)


//* Optimal :
#include<iostream>
#include<vector>
using namespace std;
void largestElement(vector<int>& arr){
    int largest = arr[0];
    for(int i=1; i<arr.size(); i++){
        if(arr[i]>largest) largest = arr[i];
    }
    cout << largest;
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    largestElement(arr);
    return 0;
}
//? Time Complexity : O(N)