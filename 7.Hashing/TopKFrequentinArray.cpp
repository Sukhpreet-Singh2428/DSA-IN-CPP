//! GOOD QUESTION : 
//? Given a non-empty integer array arr[] of size n, find the top k elements which have the highest frequency in the array.
//? Note: If two numbers have the same frequencies, then the larger number should be given more preference.
//? Examples:
//? Input: arr[] = [3, 1, 4, 4, 5, 2, 6, 1], k = 2
//? Output: [4, 1]
//? Explanation: Frequency of 4 is 2 and frequency of 1 is 2, these two have the maximum frequency and 4 is larger than 1.
//? Input: arr[] = [7, 10, 11, 5, 2, 5, 5, 7, 11, 8, 9], k = 4
//? Output: [5, 11, 7, 10]
//? Explanation: Frequency of 5 is 3, frequency of 11 is 2, frequency of 7 is 2, frequency of 10 is 1.

#include<iostream>
#include<vector>
#include<unordered_map>
#include<utility>
#include<algorithm>
using namespace std;
bool compare(pair<int,int>& a, pair<int,int>& b){
    if(a.second==b.second) return a.first > b.first;   //* <-- according to note condition
    return a.second > b.second;
}
void topkfreq(vector<int>& v, int k){
    unordered_map<int,int> mpp;
    for(auto it : v){
        mpp[it]++;
    }

    vector<pair<int,int>> freqV;   //* Move (num, frequency) pairs to a vector and Sort the vector by frequency
    for(auto it : mpp){
        freqV.push_back({it.first, it.second});
    }
    sort(freqV.begin(), freqV.end(), compare);

    //* Collect the top k frequent elements
    vector<int> ans;
    for(int i=0; i<k && i<freqV.size(); i++){
        ans.push_back(freqV[i].first);
    }
    for(auto it : ans){     //? <-- return ans
        cout << it << " ";
    }
}
int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    int k;
    cin >> k;
    topkfreq(v,k);
    return 0;
}