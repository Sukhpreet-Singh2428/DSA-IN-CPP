//! Count Subarrays With Given Sum
//* (Medium Problem)

//? Eg: 
//? arr[] = {1,2,3,-3,1,1,1,4,2,-3}   k=3
//? --> {1,2}  {1,2,3,-3}  {3}  {2,3,-3,1}  {3,-3,1,1,1}  {1,1,1} 
//?     {4,2,-3}  {-3,1,1,1,4,2,-3}
//? --> return 8

//* Brute --> Better --> Optimal 


//* Brute : 
// #include<iostream>
// #include<vector>
// using namespace std;
// int CountSubarraysWithGivenSum(vector<int>& arr, int n, int k){
//     int cnt = 0;
//     for(int i=0; i<n; i++){
//         for(int j=0; j<n; j++){
//             int sum = 0;
//             for(int k=i; k<=j; k++){
//                 sum = sum + arr[k];
//             }
//             if(sum==k) cnt++;
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
//     int k;
//     cin >> k;
//     cout << CountSubarraysWithGivenSum(arr, n, k);
//     return 0;
// }
//? Time Complexity : O(N^3) [not exactly but near about N^3]
//? Space Complexity : O(1)


//* Better : 
// #include<iostream>
// #include<vector>
// using namespace std;
// int CountSubarraysWithGivenSum(vector<int>& arr, int n, int k){
//     int cnt = 0;
//     for(int i=0; i<n; i++){
//         int sum = 0;
//         for(int j=i; j<n; j++){
//             sum += arr[j];
//             if(sum==k) cnt++;
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
//     int k;
//     cin >> k;
//     cout << CountSubarraysWithGivenSum(arr, n, k);
//     return 0;
// }
//? Time Complexity : O(N^2)
//? Space Complexity : O(1)


//* Optimal : 
//? (Prefix Sum)
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int CountSubarraysWithGivenSum(vector<int>& arr, int n, int k){
    unordered_map<int, int> mpp;
    mpp[0] = 1;
    int preSum = 0, cnt = 0;
    for(int i=0; i<n; i++){
        preSum += arr[i];
        int remove = preSum - k;
        cnt += mpp[remove];
        mpp[preSum] += 1;
    }
    return cnt;
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
    cout << CountSubarraysWithGivenSum(arr, n, k);
    return 0;
}
//? Time Complexity: O(N)
//? Space Complexity : O(N)


// #include<iostream>
// #include<vector>
// #include<unordered_map>
// using namespace std;
// int CountSubarraysWithGivenSum(vector<int>& arr, int n, int k){
//     unordered_map<int, int> mpp;
//     int preSum = 0;
//     int cnt = 0;
//     mpp[0] = 1;
//     for(int i=0; i<n; i++){
//         preSum += arr[i];
//         int rem = preSum - k;
//         if(mpp.find(rem) != mpp.end()){
//             cnt += mpp[rem];
//         }
//         mpp[preSum]++;
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
//     int k;
//     cin >> k;
//     cout << CountSubarraysWithGivenSum(arr, n, k);
//     return 0;
// }