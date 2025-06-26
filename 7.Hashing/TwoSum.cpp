//? Given an array of integers nums and an integer target, return the indices i and j such that nums[i] + nums[j] == target and i != j.
//? You may assume that every input has exactly one pair of indices i and j that satisfy the condition.
//? Return the answer with the smaller index first.
//? Example 1:
//? Input: 
//? nums = [3,4,5,6], target = 7
//? Output: [0,1]
//? Explanation: nums[0] + nums[1] == 7, so we return [0, 1].
//? Example 2:
//? Input: nums = [4,5,6], target = 10
//? Output: [0,2]
//? Example 3:
//? Input: nums = [5,5], target = 10
//? Output: [0,1]
//? Constraints:
//? 2 <= nums.length <= 1000
//? -10,000,000 <= nums[i] <= 10,000,000
//? -10,000,000 <= target <= 10,000,000

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int> TwoSum(vector<int>& nums, int target){
    unordered_map<int,int> mpp;    //* num --> index
    for(int i=0; i<nums.size(); i++){
        mpp[nums[i]] = i;
    }
    for(int i=0;i<nums.size();i++){
        int diff = target - nums[i];
        if(mpp.count(diff) && mpp[diff]!=i){     //? <-- count() is used to check whether a specific key exists in the map. If the key is present in the map, count(key) returns 1.
            return {i,mpp[diff]};                //? If the key is not present, it returns 0
        }
    }
    return {};
}
int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    int target;
    cin >> target;
    vector<int> ans = TwoSum(nums, target);
    for(auto it : ans){
        cout << it << " ";
    }
    return 0;
}
//* Time Complexity : O(N)