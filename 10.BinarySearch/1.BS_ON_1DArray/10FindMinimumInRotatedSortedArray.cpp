//! Find Minimum in Rotated Sorted Array   [unique]
//* (Medium Problem)

//? Eg:  arr[] = {4, 5, 6, 7, 0, 1, 2}
//?   ---> return 0

//* Linear Search --> Binary Search


//* Linear Search : 
// #include<iostream>
// #include<vector>
// #include<climits>
// using namespace std;
// int MinimumInRotatedSortedArray(vector<int>& arr){
//     int n = arr.size(); 
//     int ans = INT_MAX;
//     for(int i=0; i<n; i++){
//         ans = min(ans, arr[i]);
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
//     cout << MinimumInRotatedSortedArray(arr);
//     return 0;
// }


//* Binary Search : 
//? pick the min from the sorted half and eliminate
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int MinimumInRotatedSortedArray(vector<int>& arr){
    int n = arr.size(); 
    int low = 0;
    int high = n-1;
    int ans = INT_MAX;
    while(low<=high){
        int mid = low + (high-low)/2;

        if(arr[low] <= arr[high]){
            ans = min(ans, arr[low]);
            break;
        }

        if(arr[low]<=arr[mid]){
            ans = min(ans, arr[low]);
            low = mid+1;
        }
        else{
            ans = min(ans, arr[mid]);
            high = mid-1;
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
    cout << MinimumInRotatedSortedArray(arr);
    return 0;
}
//? Time Complexity : O(log2N)
//? Space Complexity : O(1)