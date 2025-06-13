//!#include<bits/stdc++.h>   // Add all the neccesary library, no need to add particular #include for all

//! C++ STL is divided into 4 parts 
//* 1. Algorithms
//* 2. Containers
//* 3. Functions
//* 4. Iterators


// #include<bits/stdc++.h>
// using namespace std;

//! Pairs :     --> #include<utility>
// #include<utility>
// #include<iostream>
// using namespace std;
// void explainPair(){
//     pair<int, int> p = {1,3};
//     cout << p.first << " " << p.second << endl;

//     pair<int, pair<int, int>> q = {1, {3, 4}};
//     cout << q.first << " " << q.second.second << " " << q.second.first << endl;

//     pair<int, int> arr[] = { {1,2}, {3,4}, {5,6}};
//     cout << arr[1].second << endl;
// }
// int main(){
//     explainPair();
//     return 0;
// }

//! Vectors :     --> #include<vector>
//* Vectors in STL are basically dynamic arrays that have the ability 
//* to change size whenever elements are added or deleted from them. 
//* Vector elements can be easily accessed and traversed using iterators. 
//* A vector stores elements in contiguous memory locations.

// #include<vector>
// #include<iostream>
// using namespace std;
// void explainVector(){
    // vector<int> v;       //? this create the empty vector
    // v.push_back(1);      //? this add 1 to the end of the vector
    // v.emplace_back(2);   //? this add 2 to the end of the vector (similar to the push_back)
    //* The difference between push_back and emplace_back matters only when you are working 
    //* with more complex types (like classes or structs).
    //* For simple types (like int, double, char), you can use either one—they work the same way.

    // vector<pair<int, int>> vec;
    // vec.push_back({1,2});     //? Creates a temporary pair<int, int> and then moves it into the vector
    // vec.emplace_back(1,2);    //? // Constructs the pair<int, int> directly in the vector
    //* push_back({1, 2});
    //* First, a temporary pair<int, int> is created using {1, 2}.
    //* Then, this temporary pair is moved (or copied) into the vector.

    //* emplace_back(3, 4);
    //* The two numbers 3 and 4 are given directly to the vector.
    //* The pair is constructed in-place inside the vector—no temporary object is made.

    // vector<int> v(5, 100);   //? v = {100, 100, 100, 100, 100}

    // vector<int> v(5);     //? v = {0,0,0,0,0} or garbage values

    // vector<int> v1(5,20);    //? v1 = {20, 20, 20, 20, 20}
    // vector<int> v2(v1);      //? v2 = v1 = {20, 20, 20, 20, 20}

    //? v = {20, 10, 15, 5, 7}
    //? v[2] = 15
    //? other way is iterator

    // vector<int> v = {20,10,15,5,7};
    // vector<int>::iterator it = v.begin();  //* Points to the first element (20) [Address]
    // cout << *(it) << " ";   //* --> 20
    // it++;
    // cout << *(it) << " ";   //* --> 10
    // it = it + 2;
    // cout << *(it) << " ";   //* --> 5
    //* v.end() --? it returns an iterator pointing to the element theoretically after the last element of the vector.
    // for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
    //     cout << *(it) << " ";
    // }
    //* auto --> vector<int>::iterator
    // for(auto it = v.begin(); it != v.end(); it++){
    //     cout << *(it) << " ";
    // }
    // for(auto it:v){
    //     cout << it << " ";
    // }

    //* vector<int>::iterator it = v.end();  --> v.end() returns an iterator pointing just past the last element of the vector (not to the last element itself).
    //* vector<int>::iterator it = v.rend();  --> v.rend() returns a reverse iterator pointing just before the first element of the vector. [basically understand as reverse vector end()]
    //* vector<int>::iterator it = v.rbegin();  --> v.rbegin() returns a reverse iterator pointing to the last element of the vector. [basically understand as reverse vector begin()]

    // cout << v.back() << " ";  //* prints the last element of the vector v

    //* erase --> .erase(iterator) --> delete
    // v.erase(v.begin()+1);    //? Delete 1 index element --> 10 delete/erase from v

    // v.erase(v.begin()+2, v.begin()+4);  //* .erase(start,end) --> [start,end) --> [start is included and end is not included] <-- erase elements from start to end but end is not included.

    //* Insert function   --> .insert(address/iterator, value) --> address/position where you want to insert the value/values.
    // vector<int> v(2,100);   //? v = {100,100}
    // v.insert(v.begin(),300);   //? v = {300,100,100}
    // v.insert(v.begin()+1,2,10);  //? v = {300, 10, 10, 100, 100}

    // vector<int> copy(2,50);   //? copy = {50,50}
    // v.insert(v.begin(), copy.begin(), copy.end());  //? v = {50, 50, 300, 10, 10, 100, 100}

    //* Size of vector 
    // cout << v.size();

    //? {10,20}
    // v.pop_back();  //? 10

    //? v1 --> {10,20}
    //? v2 --> {30,40}
    // v1.swap(v2);    //? v1 --> {30,40}    v2 --> {10,20}

    // v.clear();   //? erases the entire vector

    // cout << v.empty();   //? returns true or 1 --> vector v contains no elements. return false or 0 --> vector v has one or more elements.


// }
// int main(){
//     explainVector();
//     return 0;
// }

//! List   -->  #include<list>
// #include<iostream>
// #include<list>
// using namespace std;
// void explainList(){
//     list<int> ls;

//     ls.push_back(2);  //? {2}
//     ls.emplace_back(4);  //? {2,4}

//     ls.push_front(5);  //? {5,2,4}
//     ls.emplace_front();  //? {0,5,2,4}   

//     //* rest functions same as vector 
//     //* begin, end, rbegin, rend, clear, insert, size, swap

//     //? Bidirectional Traversal: You can iterate both forward and backward through a list
//     //?  You cannot access elements by index (e.g., numbers[2] is invalid)
//     //? Non-contiguous Storage: Elements are stored in nodes scattered throughout memory, each with pointers to the next and previous nodes.

// }
// int main(){
//     explainList();
//     return 0;
// }

//! Deque   --> #include<deque>
// #include<iostream>
// #include<deque>
// using namespace std;
// void explainDeque(){
//     deque<int> dq;
//     dq.push_back(1);   //? {1}
//     dq.emplace_back(2);  //? {1,2}
//     dq.push_front(4);    //? {4,1,2}
//     dq.emplace_front(3);   //? {3,4,1,2}

//     dq.pop_back();   //? {3,4,1}
//     dq.pop_front();  //? {4,1}

//     dq.back();
//     dq.front();

    // * rest functions same as vector 
    // * begin, end, rbegin, rend, clear, insert, size, swap

    // ? Access by index (like vector)
    // ? Not guaranteed to be stored in contiguous memory
    // ? Fast insertions/deletions at both ends 
// }
// int main(){
//     explainDeque();
//     return 0;
// }

//! Stack   -->    #include<stack>
//? A stack is a linear data structure that follows the Last-In, First-Out (LIFO) principle: 
//? the last element added is the first one removed

// #include<iostream>
// #include<stack>
// void explainStack(){
//     stack<int> st;
//     st.push(1);  //? {1}
//     st.push(2);  //? {2,1}
//     st.push(3);  //? {3,2,1}
//     st.push(3);  //? {3,3,2,1}
//     st.emplace(5);  //? {5,3,3,2,1}

//     cout << st.top();   //? prints 5   "** st[2] is invalid **"

//     st.pop();  //? st looks like {3,3,2,1}

//     cout << st.top();  //? 3

//     cout << st.size();  //? 4

//     cout << st.empty();

//     stack<int> st2;
//     st1.swap(st2);

// }
// using namespace std;
// int main(){
//     explainStack();
//     return 0;
// }


//!  Queue   --> #include<queue>
//? A queue is a linear data structure that operates on the First-In, First-Out (FIFO) principle: 
//? the first element added is the first one removed

// #include<iostream>
// #include<queue>
// using namespace std;
// void explainQueue() {
//     queue<int> q;
//     q.push(1);   //? {1}
//     q.push(2);   //? {1,2}
//     q.emplace(4);  //? {1,2,4}

//     q.back() += 5;

//     cout << q.back();  //? prints 9

//     //? Q is {1,2,9}
//     cout << q.front();  //? prints 1

//     q.pop();  //? {2,9}

//     cout << q.front();  //? prints 2

//     //* Size, Swap, empty same as stack
// }
// int main(){
//     explainQueue();
//     return 0;
// }

//! Priority Queue   --> #include<queue>
//? A priority queue is a specialized data structure where each element has a priority,
//? and elements are served based on their priority rather than their insertion order.

#include<iostream>
#include<queue>
using namespace std;
void explainPQ(){
    
}
int main(){
    explainPQ();
    return 0;
}