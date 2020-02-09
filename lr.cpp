//Linear regression 
#define ARMA_DONT_USE_BLAS
#include <vector>
#include <string>
#include <assert.h>
#include <armadillo>

using namespace arma;
class LR { 
  public:
    LR() {};
    ~LR() {};
    void fit(StaticDataFrame &, std::vector<std::string>, std::string);
    void summary();
    std::vector<double> params;
    std::vector<std::string> x_cols;
    std::string y_col;
};

void LR::fit(StaticDataFrame & df, std::vector<std::string> x_vars, std::string y_var) {
  //Built data matrices
  assert(df[y_var] != NULL);
  vec Y = vec(df[y_var]->size());
  for(int i = 0; i < df[y_var]->size(); i++)  Y[i] = df[y_var] -> at(i);

  assert(df[x_vars[0]] != NULL);
  mat X_matrix = mat(df[x_vars[0]] -> size(), x_vars.size());

  for (int i = 0; i < x_vars.size(); ++i){
      assert(df[x_vars[i]] != NULL);
      for(int j = 0; j < df[x_vars[i]]->size(); j++)
        X_matrix[j, i] = df[x_vars[i]] -> at(j);
  }

  //LR as a linear solve
  vec B = solve(X_matrix.t() * X_matrix, X_matrix * Y);

  for(int i=0; i< x_vars.size(); i++) params[i] = B[i];
  x_cols = x_vars;
  y_col = y_var;
}

void LR::summary(){
  std::cout<<"Fit to y variable: "<<y_col<<std::endl;
  for(int i = 0; i < x_cols.size(); i++)
    std::cout << x_cols[i] <<": "<< params[i] << std::endl;
}
