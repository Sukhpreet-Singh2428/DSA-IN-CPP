//! Set Matrix Zeros
//* (Medium Problem)

//? Eg : 
//?  1  1  0  1             0  0  0  0
//?  1  0  0  1     -->     0  0  0  0 
//?  1  1  0  1             0  0  0  0
//?  1  1  1  1             1  0  0  1

//* Brute --> Better --> Optimal


//* Brute : 
// #include<iostream>
// #include<vector>
// using namespace std;
// void MarkRow(vector<vector<int>>& arr, int r, int c, int i){
//     for(int j=0; j<c; j++){
//         if(arr[i][j]!=0){
//             arr[i][j] = -1;
//         }
//     }
// }
// void MarkCol(vector<vector<int>>& arr, int r, int c, int j){
//     for(int i=0; i<r; i++){
//         if(arr[i][j]!=0){
//             arr[i][j] = -1;
//         }
//     }
// }
// void SetMatrixZeros(vector<vector<int>>& arr, int r, int c){
//     for(int i=0; i<r; i++){
//         for(int j=0; j<c; j++){
//             if(arr[i][j]==0){
//                 MarkRow(arr, r, c, i);
//                 MarkCol(arr, r, c, j);
//             }
//         }
//     }

//     for(int i=0; i<r; i++){
//         for(int j=0; j<c; j++){
//             if(arr[i][j]==-1){
//                 arr[i][j] = 0;
//             }
//         }
//     }
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
//     SetMatrixZeros(arr, r, c);
//     for(int i=0; i<r; i++){
//         for(int j=0; j<c; j++){
//             cout << arr[i][j] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }
//? Time Complexity : O(n*m) * O(n+m) + O(n*m) --> nearly O(n^3) [as n or m is same for matrix]
//? Space Complexity : O(1)


//* Better : 
// #include<iostream>
// #include<vector>
// using namespace std;
// void SetMatrixZeros(vector<vector<int>>& arr, int r, int c){
//     // int r = matrix.size();
//     // int c = matrix[0].size();
//     vector<bool> rows(r, false);
//     vector<bool> cols(c, false);

//     for(int i=0; i<r; i++){
//         for(int j=0; j<c; j++){
//             if(arr[i][j]==0){
//                 rows[i] = true;
//                 cols[j] = true;
//             }
//         }
//     }

//     for(int i=0; i<r; i++){
//         for(int j=0; j<c; j++){
//             if(rows[i] || cols[j]){
//                 arr[i][j] = 0;
//             }
//         }
//     }
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
//     SetMatrixZeros(arr, r, c);
//     for(int i=0; i<r; i++){
//         for(int j=0; j<c; j++){
//             cout << arr[i][j] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }
//? Time Complexity : O(2*n*m) --> O(2 * n^2)
//? Space Complexity : O(n) + O(m)


//* Optimal : 
#include<iostream>
#include<vector>
using namespace std;
void SetMatrixZeros(vector<vector<int>>& arr, int r, int c){
    //     vector<bool> rows(r, false);  --> arr[0][..]
    //     vector<bool> cols(c, false);  --> arr[..][0]

    int col0 = 1;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(arr[i][j]==0){
                //? mark the i-th row
                arr[i][0] = 0;
                //? mark the j-th col
                if(j!=0){
                    arr[0][j] = 0;
                }
                else{
                    col0 = 0;
                }
            }
        }
    }

    for(int i=1; i<r; i++){
        for(int j=1; j<c; j++){
            if(arr[i][j] != 0){
                //? check for col & row
                if(arr[0][j]==0 || arr[i][0]==0){
                    arr[i][j] = 0;
                }
            }
        }
    }

    if(arr[0][0] == 0){
        for(int j=0; j<c; j++) arr[0][j] = 0;
    }
    if(col0 == 0){
        for(int i=0; i<r; i++) arr[i][0] = 0;
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
    SetMatrixZeros(arr, r, c);
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
//? Time Complexity : O(2 * m * n)  --> O(2 * n^2)
//? Space Complexity : O(1)

//* Intuition
//* To optimize space complexity, we can use the first row and the first column of the matrix itself to store the markers, 
//* instead of using extra arrays. This reduces the extra space from O(m + n) to O(1). However, we need to be cautious 
//* about using the first row and column for marking, as they may also be part of the matrix.

//* Approach
//* Use the first row and the first column to mark which rows and columns need to be set to zero.
//* If the first row or the first column needs to be zeroed, use additional variables to remember this.
//* Traverse the matrix and mark the first row and first column accordingly.
//* Finally, use the first row and column markers to set the respective rows and columns to zero.