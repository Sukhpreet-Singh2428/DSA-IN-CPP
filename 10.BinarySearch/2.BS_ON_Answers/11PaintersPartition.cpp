//! Painter's Partiton
//* (Hard Problem)

//? You are given A painters and an array C of N integers where C[i] denotes the length of the ith board. 
//? Each painter takes B units of time to paint 1 unit of board. You must assign boards to painters such that:
//? Each painter paints only contiguous segments of boards.
//? No board can be split between painters.
//? The goal is to minimize the time to paint all boards.


//* Optimal Code : 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int countPartition(int time, int a, int b, vector<int>& c){
    int n = c.size();
    int paintersNeeded = 1;
    int currentSum = 0;
    for(int i=0; i<n; i++){
        if(currentSum + c[i]*b <= time){
            currentSum += c[i]*b;
        }
        else{
            paintersNeeded++;
            currentSum = c[i]*b;
        }
    }
    return paintersNeeded;
}
int PaintersPartition(int a, int b, vector<int>& c){
    int n = c.size();
    int sum = 0;
    for(auto it : c){
        sum += it;
    }

    int low = *max_element(c.begin(), c.end()) * b;
    int high = sum * b;
    int ans = high;
    while(low<=high){
        int mid = low + (high-low)/2;
        int partition = countPartition(mid, a, b, c);
        if(partition > a){
            low = mid+1;
        }
        else{
            ans = mid;
            high = mid-1;
        }
    }
    return ans;
}
int main(){
    int a;
    cin >> a;
    int b;
    cin >> b;
    int n;
    cin >> n;
    vector<int> c(n);
    for(int i=0; i<n; i++){
        cin >> c[i];
    }
    cout << PaintersPartition(a, b, c);
    return 0;
}
//? Time Complexity : O(N log(sum of board lengths * B))
//? Space Complexity : O(1)