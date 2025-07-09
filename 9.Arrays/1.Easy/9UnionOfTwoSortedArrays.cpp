//! Union of Two Sorted Arrays
//* (Medium Problem)

//? Eg :  arr1[] = {1,1,2,3,4,5}
//?       arr2[] = {2,3,4,4,5,6}
//? --> Union[] = {1,2,3,4,5,6}

//* Brute --> Better --> Optimal


//* Brute :
// #include<iostream>
// #include<vector>
// #include<set>
// using namespace std;
// void UnionOfTwoSortedArrays(vector<int>& arr1, int n1, vector<int>& arr2, int n2){
//     //? step 1
//     set<int> st;
//     for(int i=0; i<n1; i++){
//         st.insert(arr1[i]);        //* O(n1LogN)
//     }
//     for(int i=0; i<n2; i++){
//         st.insert(arr2[i]);        //* O(n2LogN)
//     }
//     //? step 2
//     vector<int> Union(st.size());
//     int i=0;
//     for(auto it : st){       //* O(n1+n2) [worst case : no duplicates]
//         Union[i++] = it;
//     }
//     for(auto it : Union){   //? <-- return Union
//         cout << it << " ";
//     }
// }
// int main(){
//     int n1;
//     cin >> n1;
//     vector<int> arr1(n1);
//     for(int i=0; i<n1; i++){
//         cin >> arr1[i];
//     }
//     int n2; 
//     cin >> n2;
//     vector<int> arr2(n2);
//     for(int i=0; i<n2; i++){
//         cin >> arr2[i];
//     }
//     UnionOfTwoSortedArrays(arr1, n1, arr2, n2);
//     return 0;
// }
//? Time Complexity : O(n1LogN + n2LogN) + O(n1+n2)
//? Space Complexity : O(n1+n2) [worst case] + O(n1+n2) [this space : array space used to return]


//* Optimal 
//? (Two Pointer)
#include<iostream>
#include<vector>
using namespace std;
void UnionOfTwoSortedArrays(vector<int>& arr1, int n1, vector<int>& arr2, int n2){
    int i = 0;
    int j = 0;
    vector<int> Union;
    while(i<n1 && j<n2){
        if(arr1[i] <= arr2[j]){
            if(Union.size()==0 || Union.back() != arr1[i]){
                Union.push_back(arr1[i]);
            }
            i++;
        }
        else{
            if(Union.size()==0 || Union.back() != arr2[j]){
                Union.push_back(arr2[j]);
            }
            j++;
        }
    }
    while(i<n1){
        if(Union.back() != arr1[i]) Union.push_back(arr1[i]);
        i++;
    }
    while(j<n2){
        if(Union.back() != arr2[j]) Union.push_back(arr2[j]);
        j++;
    }

    for(auto it : Union){    //? <-- return Union
        cout << it << " ";
    }
}
int main(){
    int n1;
    cin >> n1;
    vector<int> arr1(n1);
    for(int i=0; i<n1; i++){
        cin >> arr1[i];
    }
    int n2; 
    cin >> n2;
    vector<int> arr2(n2);
    for(int i=0; i<n2; i++){
        cin >> arr2[i];
    }
    UnionOfTwoSortedArrays(arr1, n1, arr2, n2);
    return 0;
}
//? Time Complexity : O(n1 + n2)
//? Space Complexity : O(n1 + n2) [worst case]