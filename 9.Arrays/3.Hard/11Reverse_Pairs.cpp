//! Reverse Pairs
//* (Hard Problem)

//? Eg:  arr[] = {40, 25, 19, 12, 9, 6, 2}
//*  --> i < j  &&  arr[i] > 2*arr[j]
//?  --> return 15


//* Brute --> Better --> Optimal

//* Brute : 
// #include<iostream>
// #include<vector>
// using namespace std;
// int ReversePairs(vector<int>& arr){
//     int n = arr.size();
//     int cnt = 0;
//     for(int i=0; i<n; i++){
//         for(int j=i+1; j<n; j++){
//             if(arr[i] > 2*arr[j]) cnt++;
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
//     cout << ReversePairs(arr);
//     return 0;
// }
//? Time Complexity : O(N^2)
//? Space Complexity : O(1)


//* Optimal : 
//? ( Merge Sort + Logic )   [kinda similiar work that done in count inversions]
#include<iostream>
#include<vector>
using namespace std;
// int cnt = 0;   //* using global variable is not a good practice
void merge(vector<int>& arr, int low, int mid, int high){
    int left = low;
    int right = mid+1;
    vector<int> temp;

    while(left<=mid && right<=high){
        if(arr[left]<arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
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
}
int CountPairs(vector<int>& arr, int low, int mid, int high){
    int right = mid+1;
    int cnt = 0;
    for(int i=low; i<=mid; i++){
        while(right <= high && arr[i] > 2*arr[right]) right++;
        cnt += (right - (mid+1));
    }
    return cnt;
}
int mergesort(vector<int>& arr, int low, int high){
    int cnt = 0;
    if(low>=high) return cnt;
    int mid = low + (high-low)/2;
    cnt += mergesort(arr, low, mid);
    cnt += mergesort(arr, mid+1, high);
    cnt += CountPairs(arr, low, mid, high);  //* <---
    merge(arr, low, mid, high);
    return cnt;
}
int ReversePairs(vector<int>& arr){
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
    cout << ReversePairs(arr);
    return 0;
}
//? Time Complexity : O( 2NlogN )
//? Space Complexity : O(N)