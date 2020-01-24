//Testing out methods for forwards_list 
//Non-continuous memory storage, no direct random access, constant insertion/removal at any place in the array 

#include <iostream>
#include <forward_list>
#include <array>
#include <stdlib.h>
using namespace std;

bool equals(int first, int second){
    return abs(first - second) < 3;
}

int main(void) {
  array <int, 5> data = {1, 2, 3, 4, 5};
  forward_list<int> x (data.begin(), data.end());

  //Element access, reference to front 
  int f = x.front();
  cout << f << endl;

  //Modifiers - both are constant time 
  x.insert_after(x.before_begin(), 5, 100);
  x.erase_after(x.before_begin());
  x.erase_after(x.before_begin());
  x.erase_after(x.before_begin());
  

  //List operations
  //Splicing - cuts out data from one list into another; linear in size of removal/addition
  forward_list<int> second (data.begin() + 1, data.end() - 1);
  x.splice_after(x.before_begin(), second);

  //Remove (based on condition), linear 
  x.remove(100);

  //Unique
  x.unique(equals);

  //Sort (N log N)
  x.sort();

  //Reverse (Linear)
  x.reverse();

  for(auto it = x.begin(); it != x.end(); ++ it)
    cout << *it << endl;
}
