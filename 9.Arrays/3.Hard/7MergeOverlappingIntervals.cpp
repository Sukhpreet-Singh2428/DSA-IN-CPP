//! Merge Overlapping Intervals
//* (Hard Problem)

//? Eg:  arr[] = { (1,3), (2,6), (8,9), (9,11), (8,10), (2,4), (15,18), (16,17)}
//? --> return { {1,6}, {8,11}, {15,18} }

//* Brute --> Better --> Optimal


//* Brute 
// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>>& arr){
//     int n = arr.size();
//     sort(arr.begin(), arr.end());
//     vector<vector<int>> ans;
//     for(int i=0; i<n; i++){
//         int start = arr[i][0];
//         int end = arr[i][1];
//         if(!ans.empty() && end <= ans.back()[1]){
//             continue;
//         }
//         for(int j=i+1; j<n; j++){
//             if(arr[j][0] <= end){
//                 end = max(end, arr[j][1]);
//             }
//             else{
//                 break;
//             }
//         }
//         ans.push_back({start, end});
//     } 
//     return ans;
// }
// int main(){
//     int n;
//     cin >> n;
//     vector<vector<int>> arr(n, vector<int>(2));
//     for(int i=0; i<n; i++){
//         for(int j=0; j<2; j++){
//             cin >> arr[i][j];
//         }
//     }
//     vector<vector<int>> ans = mergeOverlappingIntervals(arr);
//     for(int i=0; i<ans.size(); i++){
//         for(int j=0; j<ans[i].size(); j++){
//             cout << ans[i][j] << " ";
//         }
//     }
//     return 0;
// }
//? Time Complexity : O( N*LogN + O(2N) ) 
//? Space Complexity : O(N)


//* Optimal 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>>& arr){
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for(int i=0; i<n; i++){
        if(ans.empty() || arr[i][0] > ans.back()[1]){
            ans.push_back(arr[i]);
        }
        else{
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }
    return ans;
}
int main(){
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(2));
    for(int i=0; i<n; i++){
        for(int j=0; j<2; j++){
            cin >> arr[i][j];
        }
    }
    vector<vector<int>> ans = mergeOverlappingIntervals(arr);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
    }
    return 0;
}
//? Time Complexity : O(N*LogN) + O(N)
//? Space Complexity : O(N)