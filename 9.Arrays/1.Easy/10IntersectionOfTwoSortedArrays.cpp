//! Intersection of Two Sorted Arrays 
//* (Medium Level)

//? Eg :   arr1[] = {1,2,2,3,3,4,5,6}
//?        arr2[] = {2,3,3,5,6,6,7}
//?  --> intersection[] = {2,3,3,5,6}

//* Brute --> Better --> Optimal
// #include<iostream>
// #include<vector>
// using namespace std;
// void IntersectionOfTwoSortedArrays(vector<int>& arr1, int n1, vector<int>& arr2, int n2){
//     vector<int> Intersection;
//     vector<int> visited(n2);
//     for(int i=0; i<n1; i++){
//         for(int j=0; j<n2; j++){
//             if(arr1[i]==arr2[j] && visited[j]==0){
//                 Intersection.push_back(arr1[i]);
//                 visited[j] = 1;
//                 break;
//             }
//             if(arr2[j]>arr1[i]) break;
//         }
//     }
//     for(auto it : Intersection){   //? <-- return Intersection
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
//     IntersectionOfTwoSortedArrays(arr1, n1, arr2, n2);
//     return 0;
// }
//? Time Complexity : O( n1* n2 ) [worst case]
//? Space Complexity : O(n2)


//* Optimal : 
//? (Two Pointer)
#include<iostream>
#include<vector>
using namespace std;
void IntersectionOfTwoSortedArrays(vector<int>& arr1, int n1, vector<int>& arr2, int n2){
    vector<int> Intersection;
    int i = 0;
    int j = 0;
    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]) i++;
        else if(arr2[j] < arr1[i]) j++;
        else {
            Intersection.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    for(auto it : Intersection){    //? <-- return Intersection
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
    IntersectionOfTwoSortedArrays(arr1, n1, arr2, n2);
    return 0;
}
//? Time Complexity : O(n1 + n2)
//? Space Complexity : O(n1 + n2) [worst case to return intersection array]