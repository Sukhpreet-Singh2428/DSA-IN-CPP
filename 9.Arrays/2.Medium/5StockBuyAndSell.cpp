//! Stock Buy and Sell
//* (Medium problem)

//? Best Time to Buy and Sell Stocks

//? Eg :  arr[] = {7,1,5,3,6,4}  n = 6 (days)
//?     Buy --> 1
//?     Sell --> 6
//?    Profit --> 5    (Maximum)
//? Always Buy first and then Sell, we can't Sell early before Buy


//* If you are Selling on ith day
//* You Buy on the minimum price from 1st day to (i-1) day


//* Optimal : 
#include<iostream>
#include<vector>
using namespace std;
int StockBuyAndSell(vector<int>& arr, int n){
    int mini = arr[0];
    int maxProfit = 0;
    for(int i=1; i<n; i++){
        int cost = arr[i] - mini;
        maxProfit = max(maxProfit, cost);
        mini = min(mini, arr[i]);
    }
    return maxProfit;
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << StockBuyAndSell(arr, n);
    return 0;
}
//? Time Complexity : O(N)
//? Space Complexity : O(1)