//? Find the duplicate elements in array 

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
void duplicates(vector<int>& v){
    unordered_map<int,int> mpp;
    for(auto it : v){
        mpp[it]++;
    }
    vector<int> ans;
    for(auto it : mpp){
        if(it.second>1) ans.push_back(it.first);
    }
    for(auto it : ans){        //? <-- return ans
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
    duplicates(v);
    return 0;
}