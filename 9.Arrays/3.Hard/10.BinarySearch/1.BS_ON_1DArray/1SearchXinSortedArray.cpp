//! Search X in Sorted Array
//* (Easy Problem)

//* Binary Search :-
//? Binary search is an efficient algorithm to find a target value within a sorted array. 
//? It works on the idea of repeatedly dividing the search space(the space in which the search of the target is taking place) 
//? in half until the target is found or it is concluded that the target is not present in the array.

//? Eg:  arr[] = {-1, 0, 3, 5, 9, 12}  target = 9
//? --> return 4

//* Iterative implementation 
// #include<iostream>
// #include<vector>
// using namespace std;
// int Search(vector<int>& arr, int target){
//     int n = arr.size();
//     int low = 0;
//     int high = n-1;

//     while(low<=high){
//         int mid = (low+high)/2;
//         if(arr[mid] == target) return mid;
//         else if(arr[target] > arr[mid]) low = mid+1;
//         else high = mid-1;
//     }
//     return -1;
// }
// int main(){
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(int i=0; i<n; i++){
//         cin >> arr[i];
//     }
//     int target;
//     cin >> target;
//     cout << Search(arr, target);
//     return 0;
// }
//? Time Complexity : O(log2N)

//* Recursive implementation
#include<iostream>
#include<vector>
using namespace std;
int bs(vector<int>& arr, int low, int high, int target){
    if(low>high) return -1;
    int mid = (low+high)/2;
    if(arr[mid] == target) return mid;
    else if(target > arr[mid]) return bs(arr, mid+1, high, target);
    return bs(arr, low, mid-1, target);
}
int Search(vector<int>& arr, int target){
    return bs(arr, 0, arr.size()-1, target);
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int target;
    cin >> target;
    cout << Search(arr, target);
    return 0;
}

//? Time Complexity : O(log2N)

//* Overflow condition :
//? instead of mid = (low + high)/2 
//! use mid = low + (high-low)/2