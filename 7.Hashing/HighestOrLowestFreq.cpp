//? Find the highest/lowest frequency element

#include<iostream>
#include<unordered_map>
#include<climits>
using namespace std;
void H_L_freq(int arr[], int n){
    unordered_map<int, int> mpp;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }
    int high_element;
    int high_freq = 0;
    int low_element;
    int low_freq = INT_MAX;
    for(auto it : mpp){
        if(it.second>high_freq){
            high_freq = it.second;
            high_element = it.first;
        }
        if(it.second<low_freq){
            low_freq = it.second;
            low_element = it.first;
        }
    }
    cout << high_element << " " << low_element << endl;
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    H_L_freq(arr,n);
    return 0;
}