#include "dataframe.cpp"
#include <vector>

int main(void){
  StaticDataFrame df(10);

  std::vector<double> new_data(5.0, 10);
  df.add_column("numbers", new_data);

  return 0;
}
