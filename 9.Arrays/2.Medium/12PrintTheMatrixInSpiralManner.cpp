//! Print the Matrix in Spiral Manner
//* (Medium Problem)

//? Eg :
//?  1 2 3
//?  4 5 6   -->  1 2 3 6 9 8 7 4 5
//?  7 8 9


//* Optimal : 
#include<iostream>
#include<vector>
using namespace std;
vector<int> SpiralMatrix(vector<vector<int>>& arr){
    int n = arr.size();
    int m = arr[0].size();
    int left = 0, right = m-1;
    int top = 0, bottom = n-1;
    vector<int> ans;

    while(top<=bottom && left<=right){
        //* left to right
        for(int i=left; i<=right; i++){
            ans.push_back(arr[top][i]);
        }
        top++;

        //* top to bottom
        for(int i=top; i<=bottom; i++){
            ans.push_back(arr[i][right]);
        }
        right--;

        //* right to left
        if(top<=bottom){
            for(int i=right; i>=left; i--){
                ans.push_back(arr[bottom][i]);
            }
            bottom--;
        }

        //* bottom to top
        if(left<=right){
            for(int i=bottom; i>=top; i--){
                ans.push_back(arr[i][left]);
            }
            left++;
        }
    }

    return ans;
}
int main(){
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }
    vector<int> ans = SpiralMatrix(arr);
    for(auto it : ans){
        cout << it << " ";
    }
    return 0;
}
//? Time Complexity : O(n*m)
//? Space Complexity : O(n*m)  [but if we directly print them without storing then O(1)]