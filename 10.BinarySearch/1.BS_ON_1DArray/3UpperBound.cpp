//! Upper Bound
//* (Easy Problem)

//* Upper Bound --> Smallest Index such that arr[ind] > x

//? Eg :  arr[] = {2, 3, 6, 7, 8, 8, 11, 11, 11, 12}  x = 6
//? --> return 3

//* Brute --> Better --> Optimal

//* Optimal : 
#include<iostream>
#include<vector>
using namespace std;
int UpperBound(vector<int>& arr, int x){
    int n = arr.size();

    int low = 0;
    int high = n-1;
    int ans = n;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid] > x){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
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
    int x;
    cin >> x;
    cout << UpperBound(arr, x);
    return 0;
}
//? Time Complexity : O(log2N)
//? Space Complexity : O(1)


//! In C++ : 
// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// int UpperBound(vector<int>& arr, int x){
//     int n = arr.size();

//     int up = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
//     return up;
// }
// int main(){
//     int n; 
//     cin >> n;
//     vector<int> arr(n);
//     for(int i=0; i<n; i++){
//         cin >> arr[i];
//     }
//     int x;
//     cin >> x;
//     cout << UpperBound(arr, x);
//     return 0;
// }