//! Rotate Matrix By 90 Degrees
//* (Medium Problem)

//? Eg : 
//?  1 2 3 4                13 9 5 1
//?  5 6 7 8       --->     14 10 6 2
//?  9 10 11 12             15 11 7 3
//?  13 14 15 16            16 12 8 4

//* Brute --> Better --> Optimal 


//* Brute : 
//? Observation : 
//?  before     after
//?   i  j       j  r-1-i        i  j       j  r-1-i
//?  [0][0] --> [0][3]          [1][0] --> [0][2]
//?  [0][1] --> [1][3]          [1][1] --> [1][2]
//?  [0][2] --> [2][3]          [1][2] --> [2][2]
//?  [0][3] --> [3][3]          [1][3] --> [3][2]
// #include<iostream>
// #include<vector>
// using namespace std;
// vector<vector<int>> RotateMatrixBy90Degree(vector<vector<int>>& arr, int r, int c){
//     // int r = arr.size();
//     // int c = arr[0].size();

//     vector<vector<int>> ans(r, vector<int>(c));
//     for(int i=0; i<r; i++){
//         for(int j=0; j<c; j++){
//             ans[j][r-1-i] = arr[i][j];
//         }
//     }
//     return ans;
// }
// int main(){
//     int r,c;
//     cin >> r >> c;
//     vector<vector<int>> arr(r, vector<int>(c));
//     for(int i=0; i<r; i++){
//         for(int j=0; j<c; j++){
//             cin >> arr[i][j];
//         }
//     }
//     vector<vector<int>> ans = RotateMatrixBy90Degree(arr, r, c);
//     for(int i=0; i<r; i++){
//         for(int j=0; j<c; j++){
//             cout << ans[i][j] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }
//? Time Complexity : O(N^2)
//? Space Complexity : O(N^2)


//* Optimal 
//? Observation :
//? Transpose + Reverse rows
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void RotateMatrixBy90Degree(vector<vector<int>>& arr, int r, int c){
    // int r = arr.size();
    // int c = arr[0].size();

    //? Transpose 
    for(int i=0; i<r; i++){
        for(int j=0; j<i; j++){
            swap(arr[i][j], arr[j][i]);
        }
    }

    //? Reverse every row
    for(int i=0; i<r; i++){
        reverse(arr[i].begin(), arr[i].end());
    }
}
int main(){
    int r,c;
    cin >> r >> c;
    vector<vector<int>> arr(r, vector<int>(c));
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> arr[i][j];
        }
    }
    RotateMatrixBy90Degree(arr, r, c);
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
//? Time Complexity : O(N^2) + O(N^2) --> O(N^2)
//? Space Complexity : O(1)