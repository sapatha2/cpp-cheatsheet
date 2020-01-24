#include "hash_table.h"
#include <cmath>
//Hash Table implementations
template <class T> Hash_Table<T>::Hash_Table(int n) {
    nbin = n;
    data_array = new Linked_List<T> [n];
}

template <class T> Hash_Table<T>::~Hash_Table() { 
    delete[] data_array; //Array delete is different than regular delete
}

template <class T> int Hash_Table<T>::hash_function(T to_add) { 
    //Modulo floored hash function 
    return ((int) to_add) % nbin;
}

template <class T> void Hash_Table<T>::add_element(T to_add) {
    if(!search_element(to_add)){
        int index = hash_function(to_add);
        Link_Container <T> * new_element = new Link_Container<T>(to_add);
        data_array[index].add_element(new_element);
    }
}

template <class T> bool Hash_Table<T>::search_element(T to_find) { 
    int index = hash_function(to_find);
    for (int i = 0; i < data_array[index].size; i++){
        if (data_array[index].return_value(i)->get_value() == to_find)
            return true;
    }
    return false;
}

template <class T> void Hash_Table<T>::remove_element(T to_remove){
    int index = hash_function(to_remove);
    for (int i = 0; i < data_array[index].size; i++){
        Link_Container<T> * value_in_table = data_array[index].return_value(i);
        if (value_in_table->get_value() == to_remove) {
            data_array[index].remove_element(value_in_table);
        }
    }
}

//Linked List Implementations
template <class T> Linked_List<T>::Linked_List(){
    size = 0;
    head = new Link_Container<T>(0);
}

template <class T> Linked_List<T>::~Linked_List(){
    Link_Container <T> * next_one = head;
    for(int i = 0; i < size; i++){
        Link_Container <T> * current = next_one;
        next_one = next_one -> get_forward_link();
        delete current;
    }
}

template <class T> void Linked_List<T>::add_element(Link_Container<T> * to_add) {
    to_add->set_forward_link(head->get_forward_link());
    head->set_forward_link(to_add);
    size++;
}

template <class T> void Linked_List<T>::remove_element(Link_Container<T> * to_remove) { 
    //Search for this element
    Link_Container<T> * current = head;
    for(int i = 0; i < size; i++){
        if(current->get_forward_link() == to_remove) {
            current->set_forward_link(to_remove -> get_forward_link()); 
            delete to_remove;
            size--;
            break; 
        }
        else { 
            current = current->get_forward_link(); 
        }
    }
}

template <class T> Link_Container<T>* Linked_List<T>::return_value(int n){
    Link_Container<T> * current = head;
    for(int i = 0; i < n + 1; i++){
        current = current->get_forward_link();  
    }
    return current;
}

//Link container implementations
template <class T> Link_Container<T>::Link_Container(T new_value) {
    value = new_value;
    next_container = NULL;
}

template <class T> Link_Container<T>::~Link_Container() {}

template <class T> T Link_Container<T>::get_value() {
    return value;
}               

template <class T> Link_Container<T> * Link_Container<T>::get_forward_link() { 
    return next_container;
}       

template <class T> void Link_Container<T>::set_forward_link(Link_Container<T>* new_container) {
    next_container = new_container;
}
