//! First and Last Occurrence
//* (Easy Problem)

//? Eg:  arr[] = {2, 4, 6, 8, 8, 8, 11, 13}   x = 8
//?    --> return {3, 5}


//* Linear Search :
// #include<iostream>
// #include<vector>
// using namespace std;
// vector<int> FirstandLastOccurrence(vector<int>& arr, int x){
//     int n = arr.size(); 
//     int first = -1;
//     int last = -1;
//     for(int i=0; i<n; i++){
//         if(arr[i] == x){
//             if(first==-1) first = i;
//             last = i;
//         }
//     }
//     return {first, last};
// }
// int main(){
//     int n;
//     cin >> n;
//     vector<int> arr(n); 
//     for(int i=0; i<n; i++){
//         cin >> arr[i];
//     }
//     int x;
//     cin >> x;
//     vector<int> ans = FirstandLastOccurrence(arr, x);
//     for(auto it : ans){
//         cout << it << " ";
//     }
//     return 0;
// }
//? Time Complexity : O(N)
//? Space Complexity : O(1)


//* Using Bounds [lower-bound and upper-bound] : 
//? Lower bound --> arr[ind] >= x
//? Upper bound --> arr[ind] > x
// #include<iostream>
// #include<vector>
// using namespace std;
// int LowerBound(vector<int>& arr, int x){
//     int n = arr.size(); 
//     int low = 0;
//     int high = n-1;
//     int ans = n;
//     while(low<=high){
//         int mid = low + (high-low)/2;
//         if(arr[mid] >= x){
//             ans = mid;
//             high = mid-1;
//         }
//         else{
//             low = mid+1;
//         }
//     }
//     return ans;
// }
// int UpperBound(vector<int>& arr, int x){
//     int n = arr.size(); 
//     int low = 0;
//     int high = n-1;
//     int ans = n;
//     while(low<=high){
//         int mid = low + (high-low)/2;
//         if(arr[mid] > x){
//             ans = mid;
//             high = mid-1;
//         }
//         else{
//             low = mid+1;
//         }
//     }
//     return ans;
// }
// vector<int> FirstandLastOccurrence(vector<int>& arr, int x){
//     int n = arr.size(); 
    
//     int lb = LowerBound(arr, x);
//     if(lb == n || arr[lb] != x) return {-1,-1};
//     return {lb, UpperBound(arr, x) - 1};
// }
// int main(){
//     int n;
//     cin >> n;
//     vector<int> arr(n); 
//     for(int i=0; i<n; i++){
//         cin >> arr[i];
//     }
//     int x;
//     cin >> x;
//     vector<int> ans = FirstandLastOccurrence(arr, x);
//     for(auto it : ans){
//         cout << it << " ";
//     }
//     return 0;
// }
//? Time Complexity : 2 * O(log2N)
//? Space Complexity : O(1)


//* Binary Serach : 
#include<iostream>
#include<vector>
using namespace std;
int First(vector<int>& arr, int x){
    int n = arr.size(); 
    int low = 0;
    int high = n-1;
    int ans = -1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid] == x){
            ans = mid;
            high = mid-1;
        }
        else if(arr[mid] < x){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return ans;
}
int Last(vector<int>& arr, int x){
    int n = arr.size(); 
    int low = 0;
    int high = n-1;
    int ans = -1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid] == x){
            ans = mid;
            low = mid+1;
        }
        else if(arr[mid] < x){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return ans;
}
vector<int> FirstandLastOccurrence(vector<int>& arr, int x){
    int n = arr.size(); 
    
    int f = First(arr, x); 
    if(f == -1) return {-1, -1};
    int l = Last(arr, x);
    return {f, l};
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n); 
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int x;
    cin >> x;
    vector<int> ans = FirstandLastOccurrence(arr, x);
    for(auto it : ans){
        cout << it << " ";
    }
    return 0;
}
//? Time Complexity : O(log2N)
//? Space Complexity : O(1)