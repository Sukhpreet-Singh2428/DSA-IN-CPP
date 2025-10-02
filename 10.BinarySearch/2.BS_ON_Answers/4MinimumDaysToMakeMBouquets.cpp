//! Minimum Days to make M Bouquets
//* (Medium Problem)

//? Eg:  bloomDay = {7, 7, 7, 7, 13, 11, 12, 7}    m = 2        k = 3
//?                                                |            |
//?                                         no. of bouquets   adjacent flowers required
//?   ---> Return 12


//* Brute --> Better --> Optimal


//* Brute : 
//? Linear Search 
// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// int possible(vector<int>& arr, int day, int m, int k){
//     int n = arr.size();

//     int cnt = 0;
//     int noOfBouquets = 0;
//     for(int i=0; i<n; i++){
//         if(arr[i] <= day){
//             cnt++;
//         }
//         else{
//             noOfBouquets += cnt/k;
//             cnt = 0;
//         }
//     }
//     noOfBouquets += cnt/k;   //? Add remaining flowers as a bouquet
//     return noOfBouquets;
// }
// int MinimumDaysToMakeMBouquets(vector<int>& arr, int m, int k){
//     int n = arr.size();

//     if(n < m*k) return -1;
//     int mini = *min_element(arr.begin(), arr.end());
//     int maxi = *max_element(arr.begin(), arr.end());
//     for(int i=mini; i<=maxi; i++){
//         if(possible(arr, i, m, k) >= m){
//             return i;
//         }
//     }
//     return -1;
// }
// int main(){
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(int i=0; i<n; i++){
//         cin >> arr[i];
//     }
//     int m;
//     cin >> m;
//     int k;
//     cin >> k;
//     cout << MinimumDaysToMakeMBouquets(arr, m, k);
//     return 0;
// }
//? Time Complexity : O((Maxi - Mini + 1)*N)
//? Space Complexity : O(1)


//* Optimal :
//? Binary Search 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int possible(vector<int>& arr, int day, int m, int k){
    int n = arr.size();

    int cnt = 0;
    int noOfBouquets = 0;
    for(int i=0; i<n; i++){
        if(arr[i] <= day){
            cnt++;
        }
        else{
            noOfBouquets += cnt/k;
            cnt = 0;
        }
    }
    noOfBouquets += cnt/k;   //? Add remaining flowers as a bouquet
    return noOfBouquets;
}
int MinimumDaysToMakeMBouquets(vector<int>& arr, int m, int k){
    int n = arr.size();

    if(n < m*k) return -1;
    int low = *min_element(arr.begin(), arr.end());
    int high = *max_element(arr.begin(), arr.end());
    int ans = high;
    while(low<=high){
        int mid = low + (high-low)/2;
        int noOfBouquets = possible(arr, mid, m, k);
        if(noOfBouquets >= m){
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
    int m;
    cin >> m;
    int k;
    cin >> k;
    cout << MinimumDaysToMakeMBouquets(arr, m, k);
    return 0;
}
//? Time Complexity : O(N * log2(max - min))
//? Space Complexity : O(1)