//! Maximum Subarray Sum
//* (Medium Problem)
//* --> Kadane's Algorithm 

//? Subarray --> Contigous part of the array

//? eg : arr[] = {-2, -3, 4 -1, -2, 1, 5 ,-3}
//?      --> ans 7
//?      return 7

//* Brute --> Better --> Optimal

//* Brute : 
// #include<iostream>
// #include<vector>
// #include<climits>
// using namespace std;
// int MaximumSubarraySum(vector<int>& arr, int n){
//     int MaxSum = INT_MIN;
//     for(int i=0; i<n; i++){
//         for(int j=i; j<n; j++){
//             int sum = 0;
//             for(int k=i; k<=j; k++){
//                 sum += arr[k];
//             }
//             MaxSum = max(MaxSum, sum);
//         }
//     }
//     return MaxSum;
// }
// int main(){
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(int i=0; i<n; i++){
//         cin >> arr[i];
//     }
//     cout << MaximumSubarraySum(arr, n);
//     return 0;
// }
//? Time Complexity : O(N^3) [near about not exactly]
//? Space Complexity : O(1)


//* Better : 
// #include<iostream>
// #include<vector>
// #include<climits>
// using namespace std;
// int MaximumSubarraySum(vector<int>& arr, int n){
//     int MaxSum = INT_MIN;
//     for(int i=0; i<n; i++){
//         int Sum = 0;
//         for(int j=i; j<n; j++){
//             Sum += arr[j];       //? Instant of iterating in subarrays, we noticed that only one element is adding to subarray one after another (Eg : [1], [1,2], [1,2,3], [1,2,3,1],..)
//             MaxSum = max(MaxSum, Sum);
//         }
//     }
//     return MaxSum;
// }
// int main(){
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(int i=0; i<n; i++){
//         cin >> arr[i];
//     }
//     cout << MaximumSubarraySum(arr, n);
//     return 0;
// }
//? Time Complexity : O(N^2)
//? Space Complexity : O(1)


//* Optimal : 

//* Kadane's Algorithm

// #include<iostream>
// #include<vector>
// #include<climits>
// using namespace std;
// int MaximumSubarraySum(vector<int>& arr, int n){
//     int MaxSum = INT_MIN;
//     int Sum = 0;
//     for(int i=0; i<n; i++){
//         Sum += arr[i];
//         if(Sum > MaxSum){
//             MaxSum = Sum;
//         }
//         if(Sum < 0){
//             Sum = 0;
//         }
//     }

//     if(MaxSum < 0) return 0;  //? This is added only bcz if in the problem, if empty subarray is also included then if MaxSum is -ve and empty subarray sum is always zero. so MaxSum = 0 as Zero > -ve.
//     return MaxSum;
// }
// int main(){
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(int i=0; i<n; i++){
//         cin >> arr[i];
//     }
//     cout << MaximumSubarraySum(arr, n);
//     return 0;
// }
//? Time Complexity : O(N)
//? Space Complexity : O(1)


//! Print the Subarray with Maximum Subarray Sum 

//* Optimal : Kadane's Algorithm
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
vector<int> MaximumSubarraySum(vector<int>& arr, int n){
    int MaxSum = INT_MIN;
    int Sum = 0;
    int ansStart = -1, ansEnd = -1;
    int Start;
    for(int i=0; i<n; i++){
        if(Sum==0) Start = i; 
        Sum += arr[i];
        if(Sum > MaxSum){
            MaxSum = Sum;
            ansStart = Start;
            ansEnd = i;
        }
        if(Sum < 0){
            Sum = 0;
        }
    }
    if(MaxSum < 0) return {};  //? This is added only bcz if in the problem, if empty subarray is also included then if MaxSum is -ve and empty subarray sum is always zero. so MaxSum = 0 as Zero > -ve.
    return {ansStart, ansEnd, MaxSum};
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    vector<int> ans =  MaximumSubarraySum(arr, n);
    if(!ans.empty()){
        for(int i=ans[0]; i<=ans[1]; i++) cout << arr[i] << " ";
        cout << endl;
        cout << ans[2];   //? <-- MaxSum
    }
    else cout << "Empty";
    return 0;
}
//? Time Complexity : O(N)
//? Space Complexity : O(1)


//* Intuition:
//? The intuition of the algorithm is not to consider the subarray as a part of the answer if its sum is less than 0. 
//? A subarray with a sum less than 0 will always reduce our answer and so this type of subarray cannot be a part of the subarray with maximum sum.
//? Here, we will iterate the given array with a single loop and while iterating we will add the elements in a sum variable. 
//? Now, if at any point the sum becomes less than 0, we will set the sum as 0 as we are not going to consider any subarray with a negative sum. 
//? Among all the sums calculated, we will consider the maximum one.

//? Thus we can solve this problem with a single loop.