//! Lower Bound
//* (Easy Problem)

//* Lower Bound --> smallest index such that arr[ind] >= x

//? Eg:  arr[] = {3,5,8,15,19}  x=5    (array has to be sorted to implement the lower bound)
//?  --> return 1   [if x is not there, then hypothetical answer will be n i.e, size of array]

//* Brute --> Better --> Optimal

//* Brute :
// #include<iostream>
// #include<vector>
// using namespace std;
// int LowerBound(vector<int>& arr, int x){
//     int n = arr.size();

//     for(int i=0; i<n; i++){
//         if(arr[i] >= x){
//             return i;
//         }
//     }
//     return n;
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
//     cout << LowerBound(arr, x);
//     return 0;
// }
//? Time Complexity : O(N)
//? Space Complexity : O(1)


//* Optimal : 
#include<iostream>
#include<vector>
using namespace std;
int LowerBound(vector<int>& arr, int x){
    int n = arr.size();

    int low = 0;
    int high = n-1;
    int ans = n;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid] >= x){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }

        // if(arr[mid] >= x){
        //     ans = mid;
        //     high = mid-1;
        // }
        // else if(x > arr[mid]) low = mid+1;
        // else high = mid-1;
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
    cout << LowerBound(arr, x);
    return 0;
}
//? Time Complexity : O(log2N)
//? Space Complexity : O(1)


//! In C++  --> lower_bound
// #include<iostream>
// #include<vector>
// using namespace std;
// int LowerBound(vector<int>& arr, int x){
//     int n = arr.size();

//     int lb = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
//     return lb; 
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
//     cout << LowerBound(arr, x);
//     return 0;
// }