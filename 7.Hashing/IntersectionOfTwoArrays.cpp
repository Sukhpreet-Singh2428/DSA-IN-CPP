//? Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.
//? Example 1:
//? Input: nums1 = [1,2,2,1], nums2 = [2,2]
//? Output: [2]
//? Example 2:
//? Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
//? Output: [9,4]
//? Explanation: [4,9] is also accepted.

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
// void Intersection(vector<int>& nums1, vector<int>& nums2){
//     unordered_set<int> set;
//     for(auto it : nums1){
//         set.insert(it);
//     }
//     vector<int> ans;

//     for(auto it : nums2){
//         if(set.erase(it)) ans.push_back(it);
//     }
//     for(auto it : ans){           //? <-- return ans;
//         cout << it << " ";
//     }
// }
//* Time complexity : O(N + M)

void Intersection(vector<int>& nums1, vector<int>& nums2){
    unordered_set<int> set1(nums1.begin(), nums1.end());
    unordered_set<int> set2(nums2.begin(), nums2.end());
    vector<int> ans;
    for(auto it : set1){
        if(set2.count(it)) ans.push_back(it);
    }
    for(auto it : ans){           //? <-- return ans;
        cout << it << " ";
    }
}
//* Time complexity : O(N + M)
int main(){
    int n1,n2;
    cin >> n1;
    vector<int> nums1(n1);
    for(int i=0;i<n1;i++){
        cin >> nums1[i];
    }
    cin >> n2;
    vector<int> nums2(n2);
    for(int i=0;i<n2;i++){
        cin >> nums2[i];
    }
    Intersection(nums1,nums2);
    return 0;
}