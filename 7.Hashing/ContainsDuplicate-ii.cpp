//* Good Question 
//? contains-duplicate-ii :
//? Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.
//? Example 1:
//? Input: nums = [1,2,3,1], k = 3
//? Output: true
//? Example 2:
//? Input: nums = [1,0,1,1], k = 1
//? Output: true
//? Example 3:
//? Input: nums = [1,2,3,1,2,3], k = 2
//? Output: false

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
bool solve(vector<int>& nums, int k){
    unordered_map<int,int> mpp;     //* val --> idx
    for(int i=0; i<nums.size(); i++){
        if(mpp.count(nums[i])){
            if(abs(i - mpp[nums[i]]) <= k) return true;
        }
        mpp[nums[i]] = i;
    }
    return false;
}
int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    int k;
    cin >> k;
    if(solve(nums,k)) cout << "true";
    else cout << "false";
    return 0;
}