//Just testing out methods in array
//Array is fixed size, constant time element access, no search

#include <iostream>
#include <array>
using namespace std;

int main(void) {
    //Construction
    const int n = 10;
    array<int, n> x;

    //Fill in the array 
    for(int k = 0; k < n; ++k)
      x[k] = k;

    //Constant iterators for printing 
    for(auto it = x.cbegin(); it != x.cend(); ++ it) {
      cout << *it << endl;
      //(*it) = 5; // Compile time error
    }
    
    //Non-constant iterator for altering values   
    for(auto it = x.begin(); it != x.end(); ++ it)
      (*it)++; //No compile time error

    for(auto it = x.cbegin(); it != x.cend(); ++ it)
      cout << *it << endl;

    //Capacity 
    cout << "Size: " << x.size() << ", Max_size: " << x.max_size() << endl;
    cout << "Empty: " << x.empty() << endl;

    //Element access 
    cout << "Front: " << x.front() << ", Back: " << x.back() << endl;

    //Observers 
    int * start = x.data();
    for(int k = 0; k < x.size(); ++ k)
      cout << *(start + k) << endl;
}
