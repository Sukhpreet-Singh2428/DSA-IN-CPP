//! Longest Subarray with Sum k
//* (easy problem)

//? Eg :  arr[] = {1,2,3,1,1,1,1,4,2,3}  k = 3
//?    --> return 3   [{1,1,1} has sum 3 and it's length is 3 which is longest]

//* Subarray :- Contigous part of the Array

//* Brute --> Better --> Optimal


//* Brute : 
//? (Generate all Subarrays)
// #include<iostream>
// #include<vector>
// using namespace std;
// int LongestSubarrayWithSumK(vector<int>& arr, int n, int k){
//     int len = 0;
//     for(int i=0; i<n; i++){
//         for(int j=i; j<n; j++){
//             int s = 0;
//             for(int K=i; K<=j; K++){
//                 s += arr[K];
//             }
//             if(s==k) len = max(len, j-i+1);
//         }
//     }
//     return len;
// }
// int main(){
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(int i=0; i<n; i++){
//         cin >> arr[i];
//     }
//     int k;
//     cin >> k;
//     cout << LongestSubarrayWithSumK(arr, n, k);
//     return 0;
// }
//? Time Complexity : O(N^3) [near around, not exactly]
//? Space Complexity : O(1)

// #include<iostream>
// #include<vector>
// using namespace std;
// int LongestSubarrayWithSumK(vector<int>& arr, int n, int k){
//     int len = 0;
//     for(int i=0; i<n; i++){
//         int s = 0;
//         for(int j=i; j<n; j++){
//             s += arr[j];     //? Instant of iterating in subarrays, we noticed that only one element is adding to subarray one after another (Eg : [1], [1,2], [1,2,3], [1,2,3,1],..)
//             if(s==k) len = max(len, j-i+1);
//         }
//     }
//     return len;
// }
// int main(){
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(int i=0; i<n; i++){
//         cin >> arr[i];
//     }
//     int k;
//     cin >> k;
//     cout << LongestSubarrayWithSumK(arr, n, k);
//     return 0;
// }
//? Time Complexity : O(N^2) 
//? Space Complexity : O(1)
//* Brute --> TC : O(N^2) [Best possible we can do]


//* Better
//? (Hashing)
// #include<iostream>
// #include<vector>
// #include<map>
// using namespace std;
// int LongestSubarrayWithSumK(vector<int>& arr, int n, int k){
//     map<int,int> preSumMap;
//     int preSum = 0;
//     int maxLen = 0;
//     for(int i=0; i<arr.size(); i++){
//         preSum += arr[i];
//         if(preSum==k){
//             maxLen = max(maxLen,i+1);
//         }
//         int rem = preSum - k;
//         if(preSumMap.find(rem) != preSumMap.end()){
//             int len = i - preSumMap[rem];
//             maxLen  = max(maxLen, len);
//         }
//         if(preSumMap.find(preSum) == preSumMap.end()) preSumMap[preSum] = i;
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
//     int k;
//     cin >> k;
//     cout << LongestSubarrayWithSumK(arr, n, k);
//     return 0;
// }
//? the if condition --> if(preSumMap.find(preSum) == preSumMap.end()) preSumMap[preSum] = i;
//? Is added due to the egde case : if there are zeroes in array 
//? Eg : arr[] = {1,1,0,0,3}  k = 3
//? so if we dry run the code and not using this if condition so it 
//? repeatively add sum of 2 in map till index 3. so the subarray with sum 3 is [3]
//? which is correct but not longest, instead it will be [0,0,3]
//? So that's why added that if condition so that repeative sum should not added to map.
//TODO: 
//* If Array has Negative elements, then this better will be the optimal for that
//* we can't optimise it further for case of Array with negatives.
//? Time Complexity : O(N*LogN)
//? Space Complexity : O(N)


//* Optimal : (if array just contains positives and zeroes)
//* {if array contains negative, positive and zero then in that case better will be optimal}
//? (Two Pointer)
#include<iostream>
#include<vector>
#include<map>
using namespace std;
int LongestSubarrayWithSumK(vector<int>& arr, int n, int k){
    int left = 0;
    int right = 0;
    int sum = arr[0];
    int maxLen = 0;
    while(right<n){
        while(left<=right && sum > k){
            sum -= arr[left];
            left++;
        }
        if(sum==k){
            maxLen = max(maxLen, right-left+1);
        }
        right++;
        if(right<n) sum += arr[right];
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
    int k;
    cin >> k;
    cout << LongestSubarrayWithSumK(arr, n, k);
    return 0;
}
//? Time Complexity : O(2N) 
//? Space Complexity : O(1)