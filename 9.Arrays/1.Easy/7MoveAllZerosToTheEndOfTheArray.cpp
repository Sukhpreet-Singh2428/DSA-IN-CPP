//! Move all Zeros to the end of the Array
//* (easy problem)

//? eg :  arr[] = {1,0,2,3,2,0,0,4,5,1}
//?   --> arr[] = {1,2,3,2,4,5,1,0,0,0}


//* Brute --> Better --> Optimal


//* Brute : 
// #include<iostream>
// #include<vector>
// using namespace std;
// void MoveZeros(vector<int>& arr){
//     vector<int> temp;
//     //? step 1
//     for(int i=0; i<arr.size(); i++){              //* O(N)
//         if(arr[i]!=0) temp.push_back(arr[i]);
//     }
//     //? step 2
//     for(int i=0; i<temp.size(); i++){            //* O(k)
//         arr[i] = temp[i];
//     }
//     //? step 3
//     for(int i=temp.size(); i<arr.size(); i++){   //* O(N - k)
//         arr[i] = 0;
//     }
// }
// int main(){
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(int i=0; i<n; i++){
//         cin >> arr[i];
//     }
//     MoveZeros(arr);
//     for(auto it : arr){
//         cout << it << " ";
//     }
//     return 0;
// }
//? Time Complexity : o(N) + O(k) + O(N-k) --> O(2N)
//? Space Complexity : O(k) --> at max O(N) [extra space]


//* Optimal
//? (Two Pointers) 
#include<iostream>
#include<vector>
using namespace std;
void MoveZeros(vector<int>& arr){
    int j = -1;
    //? step 1
    for(int i=0; i<arr.size(); i++){     //* O(k)
        if(arr[i]==0){
            j = i;
            break;
        }
    }
    //? step 2
    for(int i=j+1; i<arr.size(); i++){   //* O(N-k)
        if(arr[i]!=0){
            swap(arr[i], arr[j]);
            j++;
        }
    }
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    MoveZeros(arr);
    for(auto it : arr){
        cout << it << " ";
    }
    return 0;
}
//? Time Complexity : O(N)
//? Space Complexity : O(1)  [extra space]