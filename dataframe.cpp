// constructing unordered_maps
#include "dataframe.h"
#include <algorithm>
#include <assert.h>

void StaticDataFrame::add_column(std::string colname, std::vector<double> & data){
    assert (data.size() == col_size);
    std::pair<std::string,std::vector<double> > new_column (colname, data);
    numeric_columns.insert(new_column);
}

void StaticDataFrame::add_column(std::string colname, std::vector<std::string> & data) {
    assert (data.size() == col_size);
    std::unordered_map<std::string, std::vector<int> > hash_map;
    for(int i = 0; i < data.size(); i++){
      //Search for item 
      if(hash_map.count(data[i]) > 0){
        auto it = hash_map.find(data[i]);
        it -> second.push_back(i);
      }
      else{
        std::vector<int> new_index(1,i);
        std::pair<std::string, std::vector<int> > new_entry(data[i], new_index);
        hash_map.insert(new_entry);
      }
    }

    std::pair<std::string, std::unordered_map<std::string, std::vector<int> > > new_column (colname, hash_map);
    filter_columns.insert(new_column);
}
