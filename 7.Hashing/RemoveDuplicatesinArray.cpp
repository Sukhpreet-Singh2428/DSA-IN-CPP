//? Given an array arr consisting of positive integer numbers, remove all duplicate numbers.
//? Example:
//? Input: arr[] = [2, 2, 3, 3, 7, 5] 
//? Output: [2, 3, 7, 5]
//? Explanation: After removing the duplicates 2 and 3 we get 2 3 7 5.
//? Input: arr[] = [2, 2, 5, 5, 7, 7] 
//? Output: [2, 5, 7]

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
void RemoveDuplicate(vector<int>& nums){
    unordered_set<int> seen;
    vector<int> ans;
    for(auto it : nums){
        if(seen.find(it) == seen.end()){
            seen.insert(it);
            ans.push_back(it);
        }
    }
    for(auto it : ans){     //? <-- return ans
        cout << it << " ";
    }
}
int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    RemoveDuplicate(nums);
    return 0;
}

// #include<iostream>
// #include<vector>
// using namespace std;
// void RemoveDuplicate(vector<int>& nums){
//     bool check[1000001] = {false};
//     vector<int> ans;
//     for (int i = 0; i < nums.size(); i++) {
//         if (!check[nums[i]]) {
//             check[nums[i]] = true;
//             ans.push_back(nums[i]);
//         }
//     }
//     for(auto it : ans){     //? <-- return ans
//         cout << it << " ";
//     }
// }
// int main(){
//     int n;
//     cin >> n;
//     vector<int> nums(n);
//     for(int i=0;i<n;i++){
//         cin >> nums[i];
//     }
//     RemoveDuplicate(nums);
//     return 0;
// }