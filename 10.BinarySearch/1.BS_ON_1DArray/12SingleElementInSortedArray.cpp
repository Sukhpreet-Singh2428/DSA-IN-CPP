//! Single Element in Sorted Array
//* (Medium Problem)

//? Eg:  arr[] = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6}
//?    ---> return 4
//! It is gurantee that there always a one single element and all others are in pair i.e, twice
//*  [twice][once]
//* Every number in the array except one appears twice


//* Brute --> Better --> Optimal 


//* Brute-1 : 
//? Linear Search 
// #include<iostream>
// #include<vector>
// using namespace std;
// int singleElementInSortedArray(vector<int>& arr){
//     int n = arr.size(); 

//     if(n==1) return arr[0];
//     for(int i=0; i<n; i++){
//         if(i==0){
//             if(arr[i] != arr[i+1]) return arr[i];
//         }
//         else if(i==n-1){
//             if(arr[i] != arr[i-1]) return arr[i];
//         }
//         else{
//             if(arr[i] != arr[i+1] && arr[i] != arr[i-1]) return arr[i];
//         }
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
//     cout << singleElementInSortedArray(arr);
//     return 0;
// }
//? Time Complexity : O(N)
//? Space Complexity : O(1)


//* Brute - 2: 
// //? XOR 
// #include<iostream>
// #include<vector>
// using namespace std;
// int singleElementInSortedArray(vector<int>& arr){
//     int n = arr.size(); 
//     int ans = 0;
    
//     for(int i=0; i<n; i++){
//         ans = ans ^ arr[i];
//     }
//     return ans;
// }
// int main(){
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(int i=0; i<n; i++){
//         cin >> arr[i];
//     }
//     cout << singleElementInSortedArray(arr);
//     return 0;
// }
//? Time Complexity : O(N)
//? Space Complexity : O(1)


//* Optimal : 

//? Binary Search 
//* (even, odd) --> Element is on the right half  [(even index, odd index) means we are on left half and element will be on right half]
//* (odd, even) --> Element is on hhe left half [(odd index, even index)] means we are on right half and element will be on left half]
#include<iostream>
#include<vector>
using namespace std;
int singleElementInSortedArray(vector<int>& arr){
    int n = arr.size(); 

    if(n==1) return arr[0];
    if(arr[0] != arr[1]) return arr[0];
    if(arr[n-1] != arr[n-2]) return arr[n-1];
    int low = 1;
    int high = n-2;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1]){
            return arr[mid];
        }
        //? Left half
        if((mid%2==1 && arr[mid-1] == arr[mid]) || (mid%2==0 && arr[mid] == arr[mid+1])){
            low = mid+1;
        }
        //? right half
        else{
            high = mid-1;
        }
    }
    return -1;
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << singleElementInSortedArray(arr);
    return 0;
}
//? Time Complexity : O(log2N)
//? Space Complexity : O(1)

//! Intuition: 
//? The idea is to use the binary search algorithm to optimize the solution, 
//? especially when it is given that the array is sorted. Binary search is well-suited for efficiently finding elements in sorted arrays.
//* Since each element in the array appears twice and forms pair(even, odd), 
//* that is the first element occurs at even index and the second one occurs at odd index, 
//* till a single unpaired element has appeared in the array, after that the index of occurrence of pairs would be(odd, even). 
//* This observation can be used to adjust the search space dynamically, hence enhancing the overall time complexity.