#include <vector>
#include <unordered_map>
#include <string>

//DataFrame that can take float/double data and string categories
class StaticDataFrame { 
  public:
    StaticDataFrame(int n) {
      col_size = n;
    }
    ~StaticDataFrame() {} ;
    void add_column(std::string colname, std::vector<double> & data); //Add column of numeric data
    void add_column(std::string colname, std::vector<std::string> & data); //Add column of filter data

    std::vector<double> * operator [](std::string colname); //Return vector of numeric column
    StaticDataFrame iloc(int start, int end); //Pull data from rows [start, end)
    StaticDataFrame filter(std::string colname, std::string value); //Pull rows which have value value in column colname
  private:
    int col_size;
    std::unordered_map<std::string, std::vector<double> > numeric_columns;  //Numeric table
    std::unordered_map<std::string, std::unordered_map<std::string, std::vector<int> > > filter_columns; //Filter table
};
