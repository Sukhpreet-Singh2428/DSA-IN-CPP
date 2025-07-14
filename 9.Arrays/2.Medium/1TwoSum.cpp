//! Two Sum
//* (Medium problem)

//? Eg : arr[] = {2,6,5,8,11}  target = 14
//?   --> return {1,3} ( both the indexs)

//* Brute --> Better --> Optimal


//* Brute : 
// #include<iostream>
// #include<vector>
// using namespace std;
// vector<int> TwoSum(vector<int>& arr, int n, int target){
//     for(int i=0; i<n; i++){
//         for(int j=0; j<n; j++){
//             if(i==j) continue;
//             if(arr[i] + arr[j]==target){
//                 return {i,j};
//             }
//         }
//     }
//     return {};
// }
// int main(){
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(int i=0; i<n; i++){
//         cin >> arr[i];
//     }
//     int target;
//     cin >> target;
//     vector<int> ans = TwoSum(arr,n, target);
//     if(!ans.empty()) cout << ans[0] << " " << ans[1] << endl;
//     else cout << "No pair found" << endl;
//     return 0;
// }
//? Time Complexity : O(N^2)
//? Space Complexity : O(1)


//* Optimal 
//? (Hashing)
// #include<iostream>
// #include<vector>
// #include<unordered_map>
// using namespace std;
// vector<int> TwoSum(vector<int>& arr, int n, int target){
//     unordered_map<int, int> mpp;
//     for(int i=0; i<n; i++){
//         int diff = target - arr[i];
//         if(mpp.find(diff) != mpp.end()){
//             return {mpp[diff], i};
//         }
//         mpp[arr[i]] = i;
//     }
//     return {};
// }
// int main(){
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(int i=0; i<n; i++){
//         cin >> arr[i];
//     }
//     int target;
//     cin >> target;
//     vector<int> ans = TwoSum(arr,n, target);
//     if(!ans.empty()) cout << ans[0] << " " << ans[1] << endl;
//     else cout << "No pair found" << endl;
//     return 0;
// }
//? Time Complexity : O(N)  [worst case O(N^2), if there is worst case then we use map --> O(N*LogN)]
//? Space Complexity : O(N)