//! Largest Subarray With Zero Sum
//* (Hard Problem)

//? Eg :  arr[] = {15, -2, 2, -8, 1, 7, 10, 23}
//? --> return 5  
//? -2 2 -8 1 7

//* Brute --> Better --> Optimal


//* Brute 
// #include<iostream>
// #include<vector>
// using namespace std;
// int LargestSubarrayWithZeroSum(vector<int>& arr){
//     int n = arr.size();
//     int maxLen = -1;
//     for(int i=0; i<n; i++){
//         for(int j=i; j<n; j++){
//             int sum = 0;
//             for(int k=i; k<=j; k++){
//                 sum += arr[k];
//             }
//             if(sum == 0){
//                 maxLen = max(maxLen, j-i+1);
//             }
//         }
//     }
//     return maxLen;
// }
// int main(){
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(int i=0; i<n; i++){
//         cin >> arr[i];
//     }
//     cout << LargestSubarrayWithZeroSum(arr);
//     return 0;
// }
//? Time Complexity : O(N^3)
//? Space Complexity : O(1)


//* Better 
// #include<iostream>
// #include<vector>
// using namespace std;
// int LargestSubarrayWithZeroSum(vector<int>& arr){
//     int n = arr.size();
//     int maxLen = -1;
//     for(int i=0; i<n; i++){
//         int sum = 0;
//         for(int j=i; j<n; j++){
//             sum += arr[j];
//             if(sum==0){
//                 maxLen = max(maxLen, j-i+1);
//             }
//         }
//     }
//     return maxLen;
// }
// int main(){
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(int i=0; i<n; i++){
//         cin >> arr[i];
//     }
//     cout << LargestSubarrayWithZeroSum(arr);
//     return 0;
// }


//* Optimal
//? (Prefix Sum + hashMap)
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int LargestSubarrayWithZeroSum(vector<int>& arr){
    int n = arr.size();
    int maxLen = -1;
    int preSum = 0;
    unordered_map<int, int> mpp;
    for(int i=0; i<n; i++){
        preSum += arr[i];
        if(preSum==0){
            maxLen = max(maxLen, i+1);
        }
        int rem = preSum;
        if(mpp.find(rem) != mpp.end()){
            int len = i-mpp[rem];
            maxLen = max(maxLen, len);
        }
        if(mpp.find(preSum) == mpp.end()) mpp[preSum] = i;     //? [Only store the first occurrence of a prefix sum because that gives the longest possible subarray.]
    }
    return maxLen;
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << LargestSubarrayWithZeroSum(arr);
    return 0;
}
//? Time Complexity : O(N)
//? Space Complexity : O(N)