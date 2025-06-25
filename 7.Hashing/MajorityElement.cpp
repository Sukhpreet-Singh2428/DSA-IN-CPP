//! Hashing Approach/Code : 
//? Given an array nums of size n, return the majority element.
//? The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int majorityElement(vector<int>& v){
    unordered_map<int, int> mpp;
    for(auto it : v){
        mpp[it]++;
    }
    for(auto it : mpp){
        if(it.second>v.size()/2) return it.first;
    }
    return 0;
}
int main(){
    int n;
    cin >> n;
    // vector<int> v;
    // for(int i=0;i<n;i++){
    //     int num;
    //     cin >> num;
    //     v.push_back(num);
    // }
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    cout << majorityElement(v);
    return 0;
}