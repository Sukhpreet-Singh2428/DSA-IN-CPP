//? 📌 Problem Statement:
//? Given two strings s and t, determine if they are isomorphic.
//? Two strings s and t are called isomorphic if the characters in s can be replaced to get t, where:
//? Every occurrence of a character must be replaced with the same character.
//? No two characters may map to the same character, but a character can map to itself.
//? The order of characters must be preserved.

//? 🔧 Constraints:
//? 1 <= s.length, t.length <= 5 * 10^4
//? s and t consist of any valid ASCII characters.

//? 🧠 Example 1:
//? Input:  s = "egg", t = "add"
//? Output: true
//? Explanation:
//? e → a
//? g → d
//? ❌ Example 2:
//? Input:  s = "foo", t = "bar"
//? Output: false
//? Because:
//? f → b
//? o → a
//? o → r ❌ (inconsistent mapping)
//? ❌ Example 3:
//? Input:  s = "ab", t = "aa"
//? Output: false
//? Because:
//? a → a
//? b → a ❌ (two s chars mapping to one t char)

#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
bool isIsomorphic(string s, string t){
    if(s.size()!=t.size()) return false;
    unordered_map<char, char> mpp1, mpp2;
    for(int i=0;i<s.size();i++){
        char a = s[i];
        char b = t[i];

        //* Check mapping from s to t
        if(mpp1.count(a)){     //? <-- .count(key) checks if a key exists in the map. return 0 or 1
            if(mpp1[a]!=b) return false;
            else mpp1[a] = b;
        }

        //* Check reverse mapping from t to s
        if(mpp2.count(b)){
            if(mpp2[b]!=a) return false;
            else mpp2[b] = a;
        }
    }
    return true;
}
int main(){
    string s;
    string t;
    getline(cin, s);
    getline(cin, t);
    if(isIsomorphic(s,t)) cout << "true";
    else cout << "false";
    return 0;
}