//? Given two strings s and t, return true if t is an anagram of s, and false otherwise.

// #include<iostream>
// #include<string>
// #include<unordered_map>
// using namespace std;
// bool isAnagram(string s, string t){
//     if(s.size()!=t.size()) return false;
//     unordered_map<char, int> mpp1;
//     unordered_map<char, int> mpp2;
//     for(auto it : s){
//         mpp1[it]++;
//     }
//     for(auto it : t){
//         mpp2[it]++;
//     }
//    if(mpp1==mpp2) return true;
//    return false;
// }
// int main(){
//     string s;
//     string t;
//     getline(cin, s);
//     getline(cin, t);
//     if(isAnagram(s,t)) cout << "true";
//     else cout << "false";
//     return 0;
// }
//? overall Time complexity --> O(N)
//? Due to worst case of unordered map, hashing collisions 
//? Moreover array hashing is prefer for characters and integers also whenever the are in range to apply array hashing 

//* Array hashing <-- more efficient 
#include<iostream>
#include<string>
using namespace std;
bool isAnagram(string s, string t){
    if(s.size()!=t.size()) return false;
    int hash[256] = {0};
    for(auto it : s){
        hash[it]++;
    }
    for(auto it : t){
        hash[it]--;
    }
    for(int i=0;i<256;i++){
        if(hash[i] != 0) return false;
    }
    return true;
}
int main(){
    string s;
    string t;
    getline(cin, s);
    getline(cin, t);
    if(isAnagram(s,t)) cout << "true";
    else cout << "false";
    return 0;
}
//? Overall Time complexity of code : O(N)

//? ✅ Array hashing is O(1) for both char and int,
//? 🚫 But only when the range of values is small and known.
//? It’s the fastest possible hashing technique in competitive programming and LeetCode when applicable.
//? But in case there are negative numbers then prefer to use unordered map