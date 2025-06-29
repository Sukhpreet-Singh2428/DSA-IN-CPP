//* Medium level : 
//? sort-characters-by-frequency : 
//? Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.
//? Return the sorted string. If there are multiple answers, return any of them.
//? Example 1:
//? Input: s = "tree"
//? Output: "eert"
//? Explanation: 'e' appears twice while 'r' and 't' both appear once.
//? So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
//? Example 2:
//? Input: s = "cccaaa"
//? Output: "aaaccc"
//? Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
//? Note that "cacaca" is incorrect, as the same characters must be together.
//? Example 3:
//? Input: s = "Aabb"
//? Output: "bbAa"
//? Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
//? Note that 'A' and 'a' are treated as two different characters.

#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<utility>
#include<algorithm>
using namespace std;
static bool compare(pair<char,int>& a, pair<char,int>& b){
    return a.second > b.second;
}
string frequencySort(string s){
    string ans;
    unordered_map<char,int> mpp;
    for(auto it : s){
        mpp[it]++;
    }
    vector<pair<char,int>> v(mpp.begin(), mpp.end());
    sort(v.begin(), v.end(), compare);
    for(auto it : v){
        ans.append(it.second, it.first);    //* .append(count, character)
    }
    return ans;
}
int main(){
    string s;
    getline(cin, s);
    cout << frequencySort(s) << endl;
    return 0;
}
//* Total Time Complexity : O(N + K log K)
//* (N) (counting)
//* O(K log K) (sorting)
//* O(N) (building the result)
//* Since K (number of unique characters) is at most 256 for ASCII, O(K log K) is effectively a constant.
//* So, the overall time complexity is: O(N)
//* for practical purposes, where N is the length of the input string.