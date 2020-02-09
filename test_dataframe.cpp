#include "dataframe.cpp"
#include <vector>
#include <string>
#include <array>
#include <iostream>
#include <assert.h>

int main(void){
  StaticDataFrame df(10);

  std::vector<double> new_data(10, 5.0);
  df.add_column("numbers", new_data);

  std::array<std::string, 10> array_data = {"a","a","b","b","c","c","c","c","a","a"};
  std::vector<std::string> filter_data(array_data.begin(), array_data.end());
  df.add_column("labels", filter_data);
  
  std::vector<double> * x  = df["numbers"];
  std::vector<double> * y = df["labels"];
    
  for(auto it = x -> begin(); it != x->end(); ++it){
    std::cout<< *it << std::endl;
  }
  assert(y == NULL);  
  
  return 0;
}
