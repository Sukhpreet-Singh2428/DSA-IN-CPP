//! Search in Rotated sorted array - I  [unique elements]
//* (Medium Problem)

//? Eg:  arr[] = {7, 8, 9, 1, 2, 3, 4, 5, 6}   target = 1
//?    ---> return 3


//* Linear Search
// #include<iostream>
// #include<vector>
// using namespace std;
// int SearchInRotatedSortedArray(vector<int>& arr, int target){
//     int n = arr.size(); 
//     int ans = -1;
//     for(int i=0; i<n; i++){
//         if(arr[i] == target){
//             ans = i;
//         }
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
//     int target;
//     cin >> target;
//     cout << SearchInRotatedSortedArray(arr, target);
//     return 0;
// }
//? Time Complexity : O(N)
//? Space Complexity : O(1)


//* Binary Search : 
//? Look for the sorted part : left or right
#include<iostream>
#include<vector>
using namespace std;
int SearchInRotatedSortedArray(vector<int>& arr, int target){
    int n = arr.size(); 
    
    int low = 0;
    int high = n-1;
    int ans = -1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid] == target) return mid;

        if(arr[low] <= arr[mid]){
            if(arr[low] <= target && target <= arr[mid]){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        else{
            if(arr[mid] <= target && target <= arr[high]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
    }
    return ans;
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
    cout << SearchInRotatedSortedArray(arr, target);
    return 0;
}
//? Time Complexity : O(log2N)
//? Space Complexity : O(1)