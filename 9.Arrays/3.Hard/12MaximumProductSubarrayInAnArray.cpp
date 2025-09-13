//! Maximum Product Subarray in an Array
//* (Hard Problem)

//? Eg:  arr[] = {2, 3, -2, 4}
//? --> return 6

//* Brute --> Better --> Optimal

//* Brute:
// #include<iostream>
// #include<vector>
// #include<climits>
// using namespace std;
// int MaximumProductSubarray(vector<int> arr){
//     int n = arr.size();
//     int maxi = INT_MIN;
//     for(int i=0; i<n; i++){
//         for(int j=i; j<n; j++){
//             int prod = 1;
//             for(int k=i; k<=j; k++){
//                 prod = prod*arr[k];
//             }
//             maxi = max(maxi, prod);
//         }
//     }
//     return maxi;
// }
// int main(){
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(int i=0; i<n; i++){
//         cin >> arr[i];
//     }
//     cout << MaximumProductSubarray(arr);
//     return 0;
// }
//? Time Complexity : O(N^3)  [not exactly but near about]
//? Space Complexity : O(1)


//* Better
// #include<iostream>
// #include<vector>
// #include<climits>
// using namespace std;
// int MaximumProductSubarray(vector<int> arr){
//     int n = arr.size();
//     int maxi = INT_MIN;
//     for(int i=0; i<n; i++){
//         int prod = 1;
//         for(int j=i; j<n; j++){
//             prod *= arr[j];
//             maxi = max(maxi, prod);
//         }
//     }
//     return maxi;
// }
// int main(){
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(int i=0; i<n; i++){
//         cin >> arr[i];
//     }
//     cout << MaximumProductSubarray(arr);
//     return 0;
// }
//? Time Complexity : O(N^2)
//? Space Complexity : O(1)


//* Optimal
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int MaximumProductSubarray(vector<int> arr){
    int n = arr.size();
    int maxi = INT_MIN;
    int prefix = 1;
    int suffix = 1;
    for(int i=0; i<n; i++){
        if(prefix==0) prefix = 1;
        if(suffix==0) suffix = 1;

        prefix = prefix*arr[i];
        suffix = suffix*arr[n-i-1];
        maxi = max(maxi, max(prefix, suffix));
    }
    return maxi;
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << MaximumProductSubarray(arr);
    return 0;
}
//? Time Complexity : O(N)
//? Space Complexity : O(1)


//! Intuition:
//* The goal is to find the subarray having the maximum product of elements. To solve the problem efficiently, we need to understand the following points:

//* The product of an even number of negative numbers result in a positive product, whereas the product of an odd number of negative numbers result in a negative product.
//* If an array element is zero, considering it in the subarray will result in product as 0, giving the idea of skipping it.

//* The multiplication of all the elements in the array could have been our answer if there were all positives or even negatives in the array (with no element as 0) but the problem arises when there are odd number of negative elements in the array.
//? When the array has an odd number of negative elements, one must be excluded to make their product positive. Since the subarray must be contiguous, only the first or last negative element can be removed. By calculating the product from both directions — prefix and suffix — we can determine the maximum product subarray.