#include "dataframe.cpp"
#include <vector>
#include <string>
#include <array>
#include <iostream>
#include <assert.h>
#include "lr.cpp"

int main(void){

  //Basic testing
  StaticDataFrame df(10);

  std::vector<double> new_data(10, 5.0);
  df.add_column("numbers", new_data);

  std::array<std::string, 10> array_data = {"a","a","b","b","c","c","c","c","a","a"};
  std::vector<std::string> filter_data(array_data.begin(), array_data.end());
  df.add_column("labels", filter_data);
  
  std::vector<double> * x  = df["numbers"];
  std::vector<double> * y =  df["labels"];
    
  for(auto it = x -> begin(); it != x->end(); ++it){
    std::cout<< *it << std::endl;
  }
  assert(y == NULL);  

  StaticDataFrame * new_df1 = df.filter("labels", "d");
  assert(new_df1 == NULL);

  StaticDataFrame * new_df2 = df.filter("numbers", "12");
  assert(new_df2 == NULL);

  StaticDataFrame * new_df = df.filter("labels", "a");

  x = new_df -> at( "numbers" );
  for(auto it = x -> begin(); it != x->end(); ++it){
    std::cout<< *it << std::endl;
  }

  //Do some basic linear regression 
  StaticDataFrame lr_df(10);

  std::array<double, 10> xd = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::array<double, 10> yd = {3, 5.3, 7.7, 8.6, 11, 13, 15, 16, 19.9, 21};
  std::array<double, 10> constant = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  std::vector<double> a(xd.begin(), xd.end());
  std::vector<double> b(constant.begin(), constant.end());
  std::vector<double> c(yd.begin(), yd.end());

  lr_df.add_column("x", a);
  lr_df.add_column("c", b);
  lr_df.add_column("y", c);

  LR ols = LR();

  std::string x_col_arr[2] = {"x", "c"};
  std::vector<std::string> x_cols(x_col_arr, x_col_arr+2);
  ols.fit(lr_df, x_cols, "y");
  ols.summary();

  return 0;
}
