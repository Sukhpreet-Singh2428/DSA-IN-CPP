//! Merge Two Sorted arrays without extra space
//* (Hard Problem)

//? Eg:   arr1[] = {1, 3, 5, 7}   arr2[] = {0, 2, 6, 8, 9}
//?    --> 0 1 2 3 5 6 7 8 9
//? return   arr1[] = {0,1,2,3}   arr2[] = {5,6,7,8,9}

//* Brute --> Better --> Optimal


//* Brute 
// #include<iostream>
// #include<vector>
// using namespace std;
// void MergeTwoSortedArraysWithoutExtraSpace(vector<int>& arr1, int n, vector<int>& arr2, int m){
//     vector<int> merge;
//     int left = 0;
//     int right = 0;
//     while(left<n && right<m){
//         if(arr1[left] <= arr2[right]){
//             merge.push_back(arr1[left]);
//             left++;
//         }
//         else{
//             merge.push_back(arr2[right]);
//             right++;
//         }
//     }
//     while(left<n){
//         merge.push_back(arr1[left]);
//         left++;
//     }
//     while(right<m){
//         merge.push_back(arr2[right]);
//         right++;
//     }

//     for(int i=0; i<merge.size(); i++){
//         if(i<n) arr1[i] = merge[i];
//         else arr2[i-n] = merge[i];
//     }
// }
// int main(){
//     int n;
//     cin >> n;
//     vector<int> arr1(n);
//     for(int i=0; i<n; i++){
//         cin >> arr1[i];
//     }
//     int m;
//     cin >> m;
//     vector<int> arr2(m);
//     for(int i=0; i<m; i++){
//         cin >> arr2[i];
//     }
//     MergeTwoSortedArraysWithoutExtraSpace(arr1, n, arr2, m);

//     for(auto it : arr1){
//         cout << it << " ";
//     }
//     cout << endl;
//     for(auto it : arr2){
//         cout << it << " ";
//     }
//     return 0;
// }
//? Time Complexity : O(n+m) + O(n+m)
//? Space Complexity : O(n+m)


//* Optimal - 1
// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// void MergeTwoSortedArraysWithoutExtraSpace(vector<int>& arr1, int n, vector<int>& arr2, int m){
//     int left = n-1;
//     int right = 0;
//     while(left>=0 && right<m){
//         if(arr1[left] > arr2[right]){
//             swap(arr1[left], arr2[right]);
//             left--;
//             right++;
//         }
//         else{
//             break;
//         }
//     }
//     sort(arr1.begin(), arr1.end());
//     sort(arr2.begin(), arr2.end());
// }
// int main(){
//     int n;
//     cin >> n;
//     vector<int> arr1(n);
//     for(int i=0; i<n; i++){
//         cin >> arr1[i];
//     }
//     int m;
//     cin >> m;
//     vector<int> arr2(m);
//     for(int i=0; i<m; i++){
//         cin >> arr2[i];
//     }
//     MergeTwoSortedArraysWithoutExtraSpace(arr1, n, arr2, m);

//     for(auto it : arr1){
//         cout << it << " ";
//     }
//     cout << endl;
//     for(auto it : arr2){
//         cout << it << " ";
//     }
//     return 0;
// }
//? Time Complexity : O(min(n,m)) + O(nlogn) + O(mlogm)
//? Space Complexity : O(1)


//* Optimal - 2
//? Gap Method (Shell sort part) [takes floor of gap like 4.5 floor is 5]
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void swapIfGreater(vector<int>& arr1, vector<int>& arr2, int ind1, int ind2){
    if(arr1[ind1] > arr2[ind2]){
        swap(arr1[ind1], arr2[ind2]);
    }
}
void MergeTwoSortedArraysWithoutExtraSpace(vector<int>& arr1, int n, vector<int>& arr2, int m){
    int len = (n + m);
    int gap = (len/2) + (len%2);
    while(gap>0){
        int left = 0;
        int right = left + gap;
        while(right<len){
            //? arr1 and arr2
            if(left<n && right >= n){
                swapIfGreater(arr1, arr2, left, right-n);
            }
            //? arr2 and arr2
            else if(left >= n){
                swapIfGreater(arr2, arr2, left-n, right-n);
             }
            //? arr1 and arr1
            else{
                swapIfGreater(arr1, arr1, left, right);
            }
            left++;
            right++;
        }
        if(gap == 1) break;
        gap = (gap/2) + (gap%2);
    }
}
int main(){
    int n;
    cin >> n;
    vector<int> arr1(n);
    for(int i=0; i<n; i++){
        cin >> arr1[i];
    }
    int m;
    cin >> m;
    vector<int> arr2(m);
    for(int i=0; i<m; i++){
        cin >> arr2[i];
    }
    MergeTwoSortedArraysWithoutExtraSpace(arr1, n, arr2, m);

    for(auto it : arr1){
        cout << it << " ";
    }
    cout << endl;
    for(auto it : arr2){
        cout << it << " ";
    }
    return 0;
}
//? Time Complexity : O(log2(n+m)) * O(n+m)
//? Space Complexity : O(1)