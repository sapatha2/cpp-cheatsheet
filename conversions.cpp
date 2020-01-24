//Code for converting between different data structures 
#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <forward_list>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>

int main(void){
    //Array, fixed size
    std::array<int, 10> x  = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    //Vector from array - resizable, const access, fast insertion/deletion at end 
    std::vector<int> my_vector (x.begin(), x.end());

    //Deque from array - resizable, const access, fast insertion/deletion at start/end
    std::deque<int> my_deque (my_vector.begin(), my_vector.end());

    //Forward_list from array - resizable, linear access, fast insertion/deletion anywhere
    std::forward_list<int> my_flist (my_deque.begin(), my_deque.end());

    //List from array - resizable, linear access, fast insertion/deletion anywhere; can iterate backwards
    std::list<int> my_list (my_deque.begin(), my_deque.end());

    //Ordered set from array (tree), fast sorting, logarithmic searching; only unique keys!
    std::set<int> my_set (my_list.begin(), my_list.end());
    std::multiset<int> my_multiset (my_list.begin(), my_list.end()); //Allows for repeat indices

    //Ordered map from array (tree with keys), fast sorting, logarithmic searching, more memory 
    std::map<char, int> my_map;
    char keys[] = {'a','b','c','d','e','f','g','h','i','j'};
    for(int k = 0; k < x.size(); k ++ )
      my_map[keys[k]] = x[k];

    //Ordered set from array (hash table), fast sorting, logarithmic searching; only unique keys!
    std::unordered_set<int> my_uset (my_list.begin(), my_list.end());
    std::unordered_multiset<int> my_umultiset (my_list.begin(), my_list.end()); //Allows for repeat indices

    //Ordered map from array (tree with keys), fast sorting, logarithmic searching, more memory 
    std::unordered_map<char, int> my_umap;
    for(int k = 0; k < x.size(); k ++ )
      my_umap[keys[k]] = x[k];
}
