//Testing out methods for vector
//Resizable, contiguous memory so resizing can cause linear time memory reallocation, 
//constant time access, fast insertion/deletion at end

#include <iostream>
#include <array>
#include <vector>
using namespace std;

int main(void) {
  array <int, 5> data = {1, 2, 3, 4, 5};
  vector <int> x(data.begin(), data.end());

  //Iterators
  for(auto it = x.cbegin(); it != x.cend(); ++it)
    cout << *it << endl;

  //Capacity 
  cout << x.size () <<endl;
  cout << x.max_size () <<endl;
  cout << x.empty () <<endl;
  cout << x.capacity () <<endl;

  //Element access: front, back, etc 

  //Modifiers 
  //Insert before given index (linear)
  auto it = x.insert(x.begin() + 4, 15, 100);
  
  //Erase at a given index (linear)
  for(int k = 0; k < 4; ++ k)
    x.erase(it + k);

  //Push and pop back for fast insertion/deletion
  x.pop_back();
  x.pop_back();
  x.push_back(200);

  for(auto it = x.cbegin(); it != x.cend(); ++it)
    cout << *it << endl;
}
