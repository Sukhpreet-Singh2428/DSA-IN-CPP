//! Selection Sort :
//* Select minimum/smallest and swap

#include<iostream>
void SWAP(int* i, int *j){
    int temp = *i;
    *i = *j;
    *j = temp;
}
void selectionSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        int mini = i;
        for(int j=i; j<n;j++){
            if(arr[j]<arr[mini]) mini = j;
        }
        SWAP(&arr[mini],&arr[i]);
    }
}
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    selectionSort(arr,n);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}
//* Time Complexity : O(N^2)  [best, worst, average]