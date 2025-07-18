//! Rearrange array elements by Sign
//* (Medium Problem)

//? Eg:  arr[] = {3,1,-2,-5,2,-4}
//?   --> rearrange arr[] = {3,-2,1,-5,2,-4}
//?                           +,-,+,-,+,-
//? Rearrange elements in array in +,- will maintaining the order
//? like positive elements {3,1,2} are in same order as they are before rearrange
//? similiar for negative elements {-2,-5,-4} are in same order as they are before rearrange
//? Now, we need to just alternate the + or - will maintaining the order.
//? Number of positive and negative elements are same in the array.


//* Brute --> Better --> Optimal


//* Brute : 
// #include<iostream>
// #include<vector>
// using namespace std;
// void RearrangeElements(vector<int>& arr, int n){
//     vector<int> pos(n/2);
//     vector<int> neg(n/2);
//     int po=0, ne=0;
//     for(int i=0; i<n; i++){
//         if(arr[i]>0) pos[po++] = arr[i];
//         else neg[ne++] = arr[i];
//     }

//     for(int i=0; i<n/2; i++){
//         arr[2*i] = pos[i];
//         arr[2*i + 1] = neg[i];
//     }
// }
// int main(){
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(int i=0; i<n; i++){
//         cin >> arr[i];
//     }
//     RearrangeElements(arr, n);
//     for(auto it : arr){
//         cout << it << " ";
//     }
//     return 0;
// }
//? Time Complexity : O(N) + O(N/2)
//? Space Complexity : O(N)  --> pos(n/2) and neg(n/2)


//* Optimal : 
// #include<iostream>
// #include<vector>
// using namespace std;
// void RearrangeElements(vector<int>& arr, int n){
//     vector<int> ans(n,0);
//     int posIndex = 0, negIndex = 1;
//     for(int i=0; i<n; i++){
//         if(arr[i]<0){
//             ans[negIndex] = arr[i];
//             negIndex += 2;
//         }
//         else{
//             ans[posIndex] = arr[i];
//             posIndex += 2;
//         }
//     }

//     for(int i=0; i<n; i++){   //? --> return ans
//         arr[i] = ans[i];
//     }
// }
// int main(){
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(int i=0; i<n; i++){
//         cin >> arr[i];
//     }
//     RearrangeElements(arr, n);
//     for(auto it : arr){
//         cout << it << " ";
//     }
//     return 0;
// }


//? Second Variety : 
//? There is NOT Mention that positive elements and negative elements are equal
//? Like above positive are n/2 and negative are n/2. 
//? --> If any of the positive and negative numbers are left, add them at
//?     the end without altering the order.

//? Eg :  arr[] = {1,2,-4,-5,3,6}
//?      Here 2 negatives and 4 positive numbers
//?      pos > neg
//?   --> return arr[] = {1,-4,2,-5,3,6}

//* --> Since pos != neg (In this variety, pos > neg or neg > pos)

//* Brute :
//? For this variety, this brute is the Optimal 
//* Brute becomes Optimal  
#include<iostream>
#include<vector>
using namespace std;
void RearrangeElements(vector<int>& arr, int n){
    vector<int> pos;
    vector<int> neg;
    for(int i=0; i<n; i++){
        if(arr[i] > 0){
            pos.push_back(arr[i]);
        }
        else{
            neg.push_back(arr[i]);
        }
    }
    
    if(pos.size() > neg.size()){
        for(int i=0; i<neg.size(); i++){
            arr[2*i] = pos[i];
            arr[2*i + 1] = neg[i];
        }
        int index = neg.size()*2;
        for(int i=neg.size(); i<pos.size(); i++){
            arr[index] = pos[i];
            index++;
        }
    }
    else{
        for(int i=0; i<pos.size(); i++){
            arr[2*i] = pos[i];
            arr[2*i + 1] = neg[i];
        }
        int index = pos.size()*2;
        for(int i=pos.size(); i<neg.size(); i++){
            arr[index] = neg[i];
            index++;
        }
    }
    //? --> return arr
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    RearrangeElements(arr, n);
    for(auto it : arr){
        cout << it << " ";
    }
    return 0;
}
//? Time Complexity : O(N) + O(min(pos, neg)) + O(leftovers)
//?                         min |     max |
//?                      O(0) + o(N)   O(N/2) + O(0)
//?                      max  leftover   min  leftover
//?                                  |
//?                 worst : O(N) + O(N) --> O(2N)
//? TC : O(2N)
//? Space Complexity : O(N)