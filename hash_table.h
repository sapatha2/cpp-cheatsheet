template <class T> class Link_Container { 
    private:
        T value;
        Link_Container<T> * next_container;
    
    public:
        Link_Container(T); //Construct a link container
        ~Link_Container();
        T get_value(void); //Returns value 
        Link_Container<T> * get_forward_link(void); //Returns pointer to next container 
        void set_forward_link(Link_Container<T> * ); //Sets forwards pointer to specified
};

template <class T> class Linked_List {
    private: 
      Link_Container <T> * head; //Start of linked list

    public:
      int size; //length of the linked list
      Linked_List();
      ~Linked_List();
      void add_element(Link_Container <T> *); //Add element to linked list 
      void remove_element(Link_Container<T> *); //Remove element from linked list
      Link_Container<T> * return_value(int n); //return n-th container in the linked list
};

//Hash_Table with only unique keys, technically a set in C++11
template <class T> class Hash_Table { 
    private:
      int nbin; //Number of bins
      Linked_List <T> * data_array; //Data array of linked lists 
      int hash_function(T); //Hash function given a class T object

    public:
      Hash_Table(int n); //Build hash table with n bins
      ~Hash_Table();
      void add_element(T); //Add element to Hash table if not present
      bool search_element(T); //Search for an element class T
      void remove_element(T); //Remove element from hash table
};
