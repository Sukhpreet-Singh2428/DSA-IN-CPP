//! Count Inversions
//* (Hard Problem)

//? Eg :  arr[] = {5, 3, 2, 4, 1}
//* -->  i < j and arr[i] > arr[j]
//?     (5,3), (5,2), (5,4), (5,1), (3,2), (3,1), (2,1), (4,1)
//?   --> return 8

//* Brute --> Better --> Optimal

//* Brute : 
// #include<iostream>
// #include<vector>
// using namespace std;
// int CountInversions(vector<int>& arr){
//     int n = arr.size();
//     int cnt = 0;
//     for(int i=0; i<n; i++){
//         for(int j=i+1; j<n; j++){
//             if(arr[i] > arr[j]) cnt++;    //? No need to add && i>j because here j is always greater than i
//         }
//     }
//     return cnt;
// }
// int main(){
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(int i=0; i<n; i++){
//         cin >> arr[i];
//     }
//     cout << CountInversions(arr);
//     return 0;
// }
//? Time Complexity : O(N^2) [not exactly, but somewhere near to O(N^2)]
//? Space Complexity : O(1)


//* Optimal : 
//? ( Merge Sort + Logic )
#include<iostream>
#include<vector>
using namespace std;
// int cnt = 0;   //* recommended to not use global variable, then we have to make changes and use int instead of void type
int merge(vector<int>& arr, int low, int mid, int high){
    int left = low;
    int right = mid+1;
    vector<int> temp;

    int cnt = 0;

    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        //? right is smaller
        else{
            temp.push_back(arr[right]);
            cnt += (mid - left + 1);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=low; i<=high; i++){
        arr[i] = temp[i-low];
    }

    return cnt;
}
int mergesort(vector<int>& arr, int low, int high){
    int cnt = 0;
    if(low>=high) return cnt;
    int mid = low + (high-low)/2;
    cnt += mergesort(arr, low, mid);
    cnt += mergesort(arr, mid+1, high);
    cnt += merge(arr, low, mid, high);
    return cnt;
}
int CountInversions(vector<int>& arr){
    int n = arr.size();
    return mergesort(arr, 0, n-1);
    
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << CountInversions(arr);
    return 0;
}
//? Time Complexity : O(N*logN)
//? Space Complexity : O(N)


// class Solution {
//   public:
//     int cnt = 0;
//     void merge(vector<int>& arr, int low, int mid, int high){
//         int left = low;
//         int right = mid + 1;
//         vector<int> temp;
//         while(left<=mid && right<=high){
//             if(arr[left]<=arr[right]){
//                 temp.push_back(arr[left]);
//                 left++;
//             }
//             else{
//                 temp.push_back(arr[right]);
//                 cnt += (mid - left + 1);
//                 right++;
//             }
//         }
//         while(left<=mid){
//             temp.push_back(arr[left]);
//             left++;
//         }
//         while(right<=high){
//             temp.push_back(arr[right]);
//             right++;
//         }
//         for(int i=low; i<=high; i++){
//             arr[i] = temp[i-low];
//         }
//     }
//     void mergeSort(vector<int>& arr, int low, int high){
//         if(low>=high) return;
//         int mid = low + (high-low)/2;
//         mergeSort(arr, low, mid);
//         mergeSort(arr, mid+1, high);
//         merge(arr, low, mid, high);
//     }
//     int inversionCount(vector<int> &arr) {
//         // Code Here
//         int n = arr.size();
//         mergeSort(arr, 0, n-1);
//         return cnt;
//     }
// };