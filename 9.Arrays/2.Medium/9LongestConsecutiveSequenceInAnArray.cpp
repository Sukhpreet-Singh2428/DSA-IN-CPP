//! Longest Consecutive Sequence in an Array
//* (Medium Problem)

//? Eg:  arr[] = {102, 4, 100, 1, 101, 3, 2, 1, 1}
//? Longest Consecutive Sequence : 
//? Sequences in array 
//? 1 2 3 4 --> len = 4
//? 100 101 102 --> len = 3
//? Longest Consecutive Sequence: len = 4 --> 1 2 3 4
//? --> return 4

//* Brute --> Better --> Optimal 


//* Brute : 
//? (Linear Search)
// #include<iostream>
// #include<vector>
// using namespace std;
// bool ls(vector<int>& arr, int num){
//     for(int i=0; i<arr.size(); i++){
//         if(arr[i]==num){
//             return true;
//         }
//     }
//     return false;
// }
// int LongestConsecutiveSequence(vector<int>& arr, int n){
//     int longest = 1;
//     for(int i=0; i<n; i++){
//         int x = arr[i];
//         int cnt = 1;
//         while(ls(arr, x+1)==true){
//             x = x + 1;
//             cnt = cnt + 1;
//         }
//         longest = max(longest, cnt);
//     }
//     return longest;
// }
// int main(){
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(int i=0; i<n; i++){
//         cin >> arr[i];
//     }
//     cout << LongestConsecutiveSequence(arr, n);
//     return 0;
// }
//? Time Complexity: O(N) * O(N) --> O(N^2)
//? Space Complexity: O(1)


//* Better :
//? (Sort)
// #include<iostream>
// #include<vector>
// #include<climits>
// using namespace std;
// int parition(vector<int>& arr, int low, int high){
//     int pivot = arr[low];
//     int i = low;
//     int j = high;
//     while(i<j){
//         while(arr[i]<=pivot && i<=high-1){
//             i++;
//         }
//         while(arr[j]>pivot && j>=low+1){
//             j--;
//         }
//         if(i<j) swap(arr[i], arr[j]);
//     }
//     swap(arr[low], arr[j]);
//     return j;
// }
// void quicksort(vector<int>& arr, int low, int high){
//     if(low<high){
//         int pIndex = parition(arr, low, high);
//         quicksort(arr, low, pIndex-1);
//         quicksort(arr, pIndex+1, high);
//     }
// }
// int LongestConsecutiveSequence(vector<int>& arr, int n){
//     quicksort(arr, 0, n-1);
//     int longest = 1;
//     int cnt = 0;
//     int lastSmaller = INT_MIN;
//     for(int i=0; i<n; i++){
//         if(arr[i]-1 == lastSmaller){
//             cnt = cnt + 1;
//             lastSmaller = arr[i];
//         }
//         else if(arr[i] != lastSmaller){
//             cnt = 1;
//             lastSmaller = arr[i];
//         }
//         longest = max(longest, cnt);
//     }
//     return longest;
// }
// int main(){
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(int i=0; i<n; i++){
//         cin >> arr[i];
//     }
//     cout << LongestConsecutiveSequence(arr, n);
//     return 0;
// }
//? Time Complexity : O(NlogN) + O(N)
//? Space Complexity : O(1)


//* Optimal : 
#include<iostream>
#include<vector>
#include<climits>
#include<unordered_set>
using namespace std;
int LongestConsecutiveSequence(vector<int>& arr, int n){
    int longest = 1;
    unordered_set<int> st;
    for(int i=0; i<n; i++){
        st.insert(arr[i]);
    }

    for(auto it : st){
        if(st.find(it-1) == st.end()){
            int cnt = 1;
            int x = it;
            while(st.find(x+1) != st.end()){
                x = x + 1;
                cnt = cnt + 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << LongestConsecutiveSequence(arr, n);
    return 0;
}
//? Time Complexity : O(N) + O(2N) --> O(3N)  [assuming unordered set taking O(1)]
//? Space Complexity : O(N)