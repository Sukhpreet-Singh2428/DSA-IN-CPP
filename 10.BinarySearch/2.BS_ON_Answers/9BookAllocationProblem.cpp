//! Book Allocation Problem
//* (Hard Problem)

//? Eg:  arr[] = {25, 46, 28, 49, 24}    students = 4
//? Allocate books in such a way that : 
//? (1). Each Student gets at least one book
//? (2). Each book should be allocated to only one student
//? (3). Book allocation should be in a contiguous manner

//* You have to allocate the book to 'm' students such that the maximum number
//* of pages assigned to a student is minimum.
//* if the allocation of book is not possible, return -1

//? Allocation ways are for the given example: (to better understand the problem)
//?    25 | 46 | 28 | 49 24  ---> 73
//?    25 | 46 | 28 49 | 24  ---> 77
//?    25 | 46 28 | 49 | 24  ---> 74
//?    25 46 | 28 | 49 | 24  ---> 71

//? ---> return 71


//* Brute --> Better --> Optimal 


//* Brute : 
// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// int func(vector<int>& arr, int pages){
//     int n = arr.size();

//     int stud= 1;
//     int pagesStudent = 0;
//     for(int i=0; i<n; i++){
//         if( (pagesStudent + arr[i]) <= pages ){
//             pagesStudent += arr[i];
//         }
//         else{
//             stud++;
//             pagesStudent = arr[i];
//         }
//     }
//     return stud;
// }
// int BookAllocation(vector<int>& arr, int m){
//     int n = arr.size();
//     int sum = 0;
//     for(auto it : arr){
//         sum += it;
//     }

//     if(m > n) return -1;
//     int low = *max_element(arr.begin(), arr.end());
//     int high = sum;
//     for(int pages=low; pages<=high; pages++){
//         int cntStudents = func(arr, pages);
//         if(cntStudents <= m){
//             return pages;
//         }
//     }
//     return low;
// }
// int main(){
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(int i=0; i<n; i++){
//         cin >> arr[i];
//     }
//     int m;
//     cin >> m;
//     cout << BookAllocation(arr, m);
//     return 0;
// }
//? Time Complexity : O(sum-max+1)*O(N)
//? Space Complexity : O(1)


//* Optimal : 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int func(vector<int>& arr, int pages){
    int n = arr.size();

    int stud= 1;
    int pagesStudent = 0;
    for(int i=0; i<n; i++){
        if( (pagesStudent + arr[i]) <= pages ){
            pagesStudent += arr[i];
        }
        else{
            stud++;
            pagesStudent = arr[i];
        }
    }
    return stud;
}
int BookAllocation(vector<int>& arr, int m){
    int n = arr.size();
    int sum = 0;
    for(auto it : arr){
        sum += it;
    }

    if(m > n) return -1;
    int low = *max_element(arr.begin(), arr.end());
    int high = sum;
    int ans = high;
    while(low<=high){
        int mid = low + (high-low)/2;
        int noOfStudents = func(arr, mid);
        if(noOfStudents > m){
            low = mid+1;
        }
        else{
            ans = mid;
            high = mid-1;
        }
    }
    return ans;   //? return low
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int m;
    cin >> m;
    cout << BookAllocation(arr, m);
    return 0;
}
//? Time Complexity : O(log2(sum-max+1))*O(N)
//? Space Complexity : O(1)