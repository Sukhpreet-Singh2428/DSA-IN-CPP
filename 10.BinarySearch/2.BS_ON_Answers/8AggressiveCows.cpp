//! Aggressive Cows
//* (Hard Problem)

//? Aggressive Cows --> (min distance between cows) is max

//? Eg:  arr[] = {0, 3, 4, 7, 10, 9}   cows = 4
//?   ---> return 3


//* Brute --> Better --> Optimal


//* Brute : 
// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// bool canWePlace(vector<int>& arr, int dist, int cows){
//     int n = arr.size();

//     int cntCows = 1;
//     int last = arr[0];
//     for(int i=0; i<n; i++){
//         if( (arr[i] - last) >= dist ){
//             cntCows++;
//             last = arr[i];
//         }
//         if(cntCows >= cows) return true;
//     }
//     return false;
// }
// int AggressiveCows(vector<int>& arr, int cows){
//     int n = arr.size();

//     sort(arr.begin(), arr.end());
//     int maxi = arr[n-1];
//     int mini = arr[0];
//     int limit = maxi-mini;
//     for(int i=1; i<=limit; i++){
//         if(canWePlace(arr, i, cows) == true){
//             continue;
//         }
//         else{
//             return (i-1);
//         }
//     }
//     return limit;
// }
// int main(){
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(int i=0; i<n; i++){
//         cin >> arr[i];
//     }
//     int cows;
//     cin >> cows;
//     cout << AggressiveCows(arr, cows);
//     return 0;
// }
//? Time Complexity : O(NlogN) + O(max-min)*O(N)
//? Space Complexity : O(1)


//* Optimal : 
//? Binary Search
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool canWePlace(vector<int>& arr, int dist, int cows){
    int n = arr.size();

    int cntCows = 1;
    int last = arr[0];
    for(int i=0; i<n; i++){
        if( (arr[i] - last) >= dist ){
            cntCows++;
            last = arr[i];
        }
        if(cntCows >= cows) return true;
    }
    return false;
}
int AggressiveCows(vector<int>& arr, int cows){
    int n = arr.size();

    sort(arr.begin(), arr.end());
    int maxi = arr[n-1];
    int mini = arr[0];
    int limit = maxi - mini;
    int low = 1;
    int high = limit;
    int ans = -1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(canWePlace(arr, mid, cows) == true){
            ans = mid;
            low = mid+1;
        }
        else{
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
    int cows;
    cin >> cows;
    cout << AggressiveCows(arr, cows);
    return 0;
}
//? Time Complexity : O(NlogN) + O(log2(max-min))*O(N)
//? Space Complexity : O(1)