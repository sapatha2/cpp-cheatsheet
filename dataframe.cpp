// constructing unordered_maps
#include "dataframe.h"
#include <algorithm>
#include <assert.h>
#include <iostream>
#include <string>

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

std::vector<double> * StaticDataFrame::operator[](std::string colname){
    auto it = numeric_columns.find(colname);
    if(it == numeric_columns.end()){
      return NULL;
    }else{
      return &(it -> second);
    }
}

std::vector<double> * StaticDataFrame::at(std::string colname){
    auto it = numeric_columns.find(colname);
    if(it == numeric_columns.end()){
      return NULL;
    }else{
      return &(it -> second);
    }
}

StaticDataFrame * StaticDataFrame::filter(std::string colname, std::string value) {
  //Get indices 
  StaticDataFrame * new_df;

  if(filter_columns.count(colname) == 0) { 
    new_df =  NULL;
  } else { 
    std::unordered_map<std::string, std::vector<int> > column = filter_columns[colname];
    if(column.count(value) == 0) new_df =  NULL;
    else {
      std::vector<int> indices = column[value];
 
      //New DF
      new_df = new StaticDataFrame(indices.size());       
      
      //Get reduced numeric rows 
      for(auto it = numeric_columns.begin(); it != numeric_columns.end(); ++it) {
          
          //Reduced column
          std::vector<double> col_data(indices.size(), 0);
          for(int j = 0; j < col_data.size(); j++) 
            col_data[j] = (it -> second)[indices[j]];

          new_df -> add_column(it -> first, col_data);
      }
      
      //Get reduced filter rows 
      for(auto it = filter_columns.begin(); it != filter_columns.end(); ++it) {
          
          //Recover column
          std::vector<std::string> full_data(col_size);
          for(auto it2 = (it -> second).begin(); it2 != (it->second).end(); ++it2) {
              for(auto it3 = (it2->second).begin(); it3 != (it2->second).end(); ++it3) {
                full_data[*it3] = it2 -> first;
              } 
          }

          //Reduced column
          std::vector<std::string> col_data(indices.size());
          for(int j = 0; j < col_data.size(); j++)
            col_data[j] = full_data[indices[j]];

          new_df -> add_column(it -> first, col_data);
      }
    }
  }
  return new_df;
}
