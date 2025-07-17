//! Group Anagrams 
//* Medium Problem

//? Given an array of strings strs, group all anagrams together into sublists. You may return the output in any order.
//? An anagram is a string that contains the exact same characters as another string, but the order of the characters can be different.
//? Example 1:
//? Input: strs = ["act","pots","tops","cat","stop","hat"]
//? Output: [["hat"],["act", "cat"],["stop", "pots", "tops"]]
//? Example 2:
//? Input: strs = ["x"]
//? Output: [["x"]]
//? Example 3:
//? Input: strs = [""]
//? Output: [[""]]


//* 1. Hashing with using sorting
// #include<iostream>
// #include<vector>
// #include<unordered_map>
// #include<string>
// #include<algorithm>
// using namespace std;
// vector<vector<string>> GroupAnagrams(vector<string>& strs){
//     unordered_map<string, vector<string>> mpp;
//     for(auto it : strs){
//         string s = it;
//         sort(s.begin(), s.end());
//         mpp[s].push_back(it);
//     }
//     vector<vector<string>> v;
//     for(auto it : mpp){
//         v.push_back(it.second);
//     }
//     return v;
// }
// int main(){
//     int n;
//     cin >> n;
//     vector<string> strs(n);
//     for(int i=0; i<n; i++){
//         cin >> strs[i];
//     }
//     vector<vector<string>> ans = GroupAnagrams(strs);
//     for(auto it : ans){
//         for(auto s : it){
//             cout << s << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }
//? Time Complexity : O(N * klogk)
//? Space Complexity : O(N * k)
//? Where N is the number of strings and K is the length of the longest string.


//* 2. Hashing Using to_string 
#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>
using namespace std;
vector<vector<string>> GroupAnagrams(vector<string>& strs){
    unordered_map<string, vector<string>> mpp;
    for(auto it : strs){
        vector<int> count(26,0);
        for(auto c : it){
            count[c-'a']++;
        }
        string key = to_string(count[0]);
        for(int i=1; i<26; i++){
            key += ',' + to_string(count[i]);
        }
        mpp[key].push_back(it);
    }
    vector<vector<string>> v;
    for(auto it : mpp){
        v.push_back(it.second);
    }
    return v;
}
int main(){
    int n;
    cin >> n;
    vector<string> strs(n);
    for(int i=0; i<n; i++){
        cin >> strs[i];
    }
    vector<vector<string>> ans = GroupAnagrams(strs);
    for(auto it : ans){
        for(auto s : it){
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}
//? Time Complexity : O(N * k)
//? Space Complexity : O(k)
//? Where N is the number of strings and K is the length of the longest string.


//* 🔹 Note: Although the frequency-count (hashmap) approach has better theoretical time complexity O(N*K) 
//* compared to the sorting approach O(N*K log K), in practice (e.g., on LeetCode), 
//* the sorting approach often performs faster due to:

//* Optimized implementation of std::sort for short strings.
//* Shorter keys (sorted words) being faster to hash and compare.
//* String concatenation in the count-based method being slower.