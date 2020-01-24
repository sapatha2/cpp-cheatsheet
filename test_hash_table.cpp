#include "hash_table.cpp"
#include <math.h>
#include <iostream>

int main(void) {
    //Testing linked_list
    std::cout<<"Test linked list"<<std::endl;
   
    Linked_List<double> mylist;
    int list_size = 15;
    for(double i = 0; i < list_size; i++){
        Link_Container<double> * new_container = new Link_Container<double>(cos(3.14*i/16.));
        mylist.add_element(new_container);
    }
    std::cout << "Size: " << mylist.size << std::endl;
    for(int i = 0; i < mylist.size; i++){
        Link_Container<double> * returned = mylist.return_value(i);
        std::cout << returned -> get_value() << std::endl;
    }

    Link_Container<double> * remove_container = mylist.return_value(5);
    mylist.remove_element(remove_container);
    std::cout << "Size: " << mylist.size << std::endl;

    for(int i = 0; i < mylist.size; i++){
        Link_Container<double> * returned = mylist.return_value(i);
        std::cout << returned -> get_value() << std::endl;
    }
   
    //Testing Hash_table
    std::cout<<"Test hash table"<<std::endl;

    Hash_Table<double> my_table(100);
    for(double i = 0; i < 80; i++)        
        my_table.add_element(sin(3.14*i*15) + i);

    std::cout << sin(3.14*5*15) + 5 << " in table?: " << my_table.search_element(sin(3.14*5*15) + 5) << std::endl;
    std::cout << sin(3.14*5*15) + 6 << " in table?: " << my_table.search_element(sin(3.14*5*15) + 6) << std::endl;
    
    my_table.remove_element(sin(3.14*5*15) + 5);
    std::cout << sin(3.14*5*15) + 5 << " in table?: " << my_table.search_element(sin(3.14*5*15) + 5) << std::endl;
}
