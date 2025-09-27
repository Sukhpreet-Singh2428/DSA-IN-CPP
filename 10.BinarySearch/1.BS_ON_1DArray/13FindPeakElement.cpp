//! Find Peak Element
//* (Hard Problem)

//?  Peak Element --> arr[i-1] < arr[i] < arr[i+1]

//? Eg:  arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1}
//?    --> return 8  [or index instead of value i.e, 7]
//?       arr[] = {1, 2, 1, 3, 5, 6, 4}
//?    --> return 2 or 6
//?       arr[] = ... -infinity {1, 2, 3, 4, 5} ... - infinity
//?    ---> return 5
//?       arr[] = {5, 4, 2, 3, 1}
//?    --> return 5

//* Linear Search ---> Binary Search 


//* Linear Search : 
// #include<iostream>
// #include<vector>
// using namespace std;
// int findPeakElement(vector<int>& arr){
//     int n = arr.size();
//     for(int i=0; i<n; i++){
//         if((i==0 || arr[i-1]<arr[i]) && (i==n-1 || arr[i] > arr[i+1])){
//             return i;
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
//     cout << findPeakElement(arr);
//     return 0;
// }
//? Time Complexity : O(N)
//? Space Complexity : O(1)


//* Binary Search :
//? 1 peak : 
// #include<iostream>
// #include<vector>
// using namespace std;
// int findPeakElement(vector<int>& arr){
//     int n = arr.size();
    
//     if(n==1) return 0;
//     if(arr[0]>arr[1]) return 0;
//     if(arr[n-1]>arr[n-2]) return n-1;
//     int low = 1;
//     int high = n-2;
//     while(low<=high){
//         int mid = low + (high-low)/2;
//         if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]){
//             return mid;
//         }
//         else if(arr[mid] > arr[mid-1]){
//             low = mid+1;
//         }
//         else if(arr[mid] > arr[mid+1]){
//             high = mid-1;
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
//     cout << findPeakElement(arr);
//     return 0;
// }

//? Multiple Peak : 
//* Eg:  arr[] = {1, 5, 1, 2, 1}
#include<iostream>
#include<vector>
using namespace std;
int findPeakElement(vector<int>& arr){
    int n = arr.size();
    
    if(n==1) return 0;
    if(arr[0]>arr[1]) return 0;
    if(arr[n-1]>arr[n-2]) return n-1;
    int low = 1;
    int high = n-2;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]){
            return mid;
        }
        else if(arr[mid] > arr[mid-1]){
            low = mid+1;
        }
        else if(arr[mid] > arr[mid+1]){
            high = mid-1;
        }
        else{
            high = mid-1;     //? or low = mid+1;
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
    cout << findPeakElement(arr);
    return 0;
}
//? Time Complexity : O(log2N)
//? Space Complexity : O(1)